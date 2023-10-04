/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:51:47 by ntairatt          #+#    #+#             */
/*   Updated: 2023/10/04 12:36:26 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	prog_init(t_prog *prog, int ac, char **av)
{
	prog->nphilo = ft_atost(av[1]);
	prog->die_time = ft_atost(av[2]);
	prog->eat_time = ft_atost(av[3]);
	prog->sleep_time = ft_atost(av[4]);
	prog->max_eat = -1;
	prog->status = 1;
	prog->start_time = timestamp();
	prog->philo = NULL;
	if (ac > 5)
		prog->max_eat = (int)ft_atost(av[5]);
	if (!prog->die_time || !prog->eat_time || !prog->sleep_time || \
	!prog->max_eat)
		return (0);
	if (pthread_mutex_init(&prog->eat, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&prog->die, NULL) != 0)
		return (pthread_mutex_destroy(&prog->eat), 0);
	if (pthread_mutex_init(&prog->print, NULL) != 0)
		return (pthread_mutex_destroy(&prog->eat), \
			pthread_mutex_destroy(&prog->die), 0);
	return (1);
}

int	fork_init(t_prog *prog)
{
	pthread_mutex_t	*fork;
	size_t			i;

	i = 0;
	fork = (pthread_mutex_t *)malloc(prog->nphilo * sizeof(pthread_mutex_t));
	prog->fork = fork;
	if (!prog->fork)
		return (0);
	while (i < prog->nphilo)
	{
		if (pthread_mutex_init(&prog->fork[i++], NULL) != 0)
			return (free(prog->fork), 0);
	}
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
	return (1);
}

int	philo_init(t_prog *prog)
{
	size_t	i;

	i = 0;
	prog->philo = (t_philo *)malloc(prog->nphilo * sizeof(t_philo));
	if (!prog->philo)
		return (0);
	while (i < prog->nphilo)
	{
		prog->philo[i].nphilo = prog->nphilo;
		prog->philo[i].id = i + 1;
		prog->philo[i].eat_count = 0;
		prog->philo[i].eat_time = prog->eat_time;
		prog->philo[i].sleep_time = prog->sleep_time;
		prog->philo[i].die_time = prog->die_time;
		prog->philo[i].max_eat = prog->max_eat;
		prog->philo[i].start_time = prog->start_time;
		prog->philo[i].last_eat = prog->start_time;
		prog->philo[i].status = &prog->status;
		prog->philo[i].print = &prog->print;
		prog->philo[i].eat = &prog->eat;
		prog->philo[i].die = &prog->die;
		i++;
	}
	return (1);
}

int	thread_init(t_prog *prog)
{
	size_t		i;

	if (pthread_create(&prog->inspector, NULL, \
		&monitor, prog) != 0)
		return (0);
	i = 0;
	while (i < prog->nphilo)
	{
		if (pthread_create(&prog->philo[i].thread, NULL, \
			&routine, &prog->philo[i]) != 0)
			return (0);
		i++;
	}
	if (pthread_join(&prog->inspector, NULL) != 0)
		return (0);
	i = 0;
	while (i < prog->nphilo)
		if (pthread_join(prog->philo[i++].thread, NULL) != 0)
			return (0);
	return (1);
}
