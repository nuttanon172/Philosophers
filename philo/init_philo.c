/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:51:47 by ntairatt          #+#    #+#             */
/*   Updated: 2023/10/02 18:59:21 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	prog_init(t_prog *prog, int ac, char **av)
{
	prog->nphilo = ft_atost(av[1]);	
	prog->die_time = ft_atost(av[2]);
	prog->eat_time = ft_atost(av[3]);
	prog->sleep_time = ft_atost(av[4]);
	prog->max_eat = -1;
	prog->status = 1;
	prog->print = NULL;
	prog->fork = NULL;
	prog->philo = NULL;
	if (ac > 5)
		prog->max_eat = (int)ft_atost(av[5]);
	if (!prog->die_time || !prog->eat_time || !prog->sleep_time || \
	!prog->max_eat)
		return ;
	if (pthread_mutex_init(&prog->print, NULL) != 0)
		return ;
}

void	fork_init(t_prog *prog)
{
	size_t			i;

	i = 0;
	prog->fork = (pthread_mutex_t *)malloc(prog->nphilo * sizeof(pthread_mutex_t));
	if (!prog->fork)
		return ;
	while (i < prog->nphilo)
		if (pthread_mutex_init(&prog->fork[i++], NULL) != 0)
			return ;
	i = 0;
	while (i < prog->nphilo)
	{
		prog->philo[i].r_fork = &prog->fork[i];
		if (i == prog->nphilo - 1)
			prog->philo[i].l_fork = &prog->fork[0];
		else
			prog->philo[i].l_fork = &prog->fork[i + 1];
		i++;
	}
}

void	philo_init(t_prog *prog)
{
	size_t	i;

	i = 0;
	prog->philo = (t_philo *)malloc(prog->nphilo * sizeof(t_philo));
	if (!prog->philo)
		return ;
	while (i < prog->nphilo)
	{
		prog->philo[i].id = i + 1;
		prog->philo[i].eat_count = 0;
		prog->philo[i].status = &prog->status;
		prog->philo[i].eat_time = prog->eat_time;
		prog->philo[i].sleep_time = prog->sleep_time;
		prog->philo[i].die_time = prog->die_time;
		prog->philo[i].max_eat = prog->max_eat;
		prog->philo[i].print = &prog->print;
		prog->philo[i].start_time = get_current_time();
		prog->philo[i].last_eat = get_current_time();
		i++;
	}
}

void	thread_init(t_prog *prog)
{
	pthread_t	inspector;
	size_t		i;

	if (pthread_create(&inspector, NULL, \
		&monitor, prog) != 0)
		return ;
	i = 0;
	while (i < prog->nphilo)
	{
		if (pthread_create(&prog->philo[i].thread, NULL, \
			&routine, &prog->philo[i]) != 0)
			return ;
		i++;
	}
	i = 0;
	while (i < prog->nphilo)
		if (pthread_join(prog->philo[i++].thread, NULL) != 0)
			return ;
}
