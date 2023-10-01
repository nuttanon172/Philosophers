/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:51:47 by ntairatt          #+#    #+#             */
/*   Updated: 2023/10/01 17:15:03 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	prog_init(t_prog *prog, int ac, char **av)
{
	int	i;

	i = 0;
	prog->nphilo = ft_atost(av[1]);
	if (pthread_mutex_init(prog->print, NULL) != 0)
		return (NULL);
	prog->die_time = ft_atost(av[2]);
	prog->eat_time = ft_atost(av[3]);
	prog->sleep_time = ft_atost(av[4]);
	prog->total_eat = -1;
	if (ac > 5)
		prog->total_eat = (int)ft_atost(av[5]);
	if (!prog->die_time || !prog->eat_time || !prog->sleep_time || \
	!prog->total_eat)
		return (EXIT_FAILURE);
}

void	fork_init(t_prog *prog)
{
	pthread_mutex_t	*fork;
	int				i;

	i = 0;
	fork = (pthread_mutex_t *)malloc(prog->nphilo * sizeof(pthread_mutex_t));
	if (!fork)
		return (NULL);
	while (i < prog->nphilo)
		if (pthread_mutex_init(&fork[i++], NULL) != 0)
			return (NULL);
	prog->philo[0].l_fork = &fork[0];
	prog->philo[0].r_fork = &fork[prog->nphilo - 1];
	i = 1;
	while (i < prog->nphilo)
	{
		prog->philo[i].l_fork = &fork[i];
		prog->philo[i].r_fork = &fork[i - 1];
		i++;
	}
}

void	philo_init(t_prog *prog)
{
	int	i;

	i = 0;
	prog->philo = (pthread_t *)malloc(prog->nphilo * sizeof(pthread_t));
	if (!prog->philo)
		return (NULL);
	while (i < prog->nphilo)
	{
		prog->philo[i].id = i + 1;
		prog->philo[i].eat_count = 0;
		prog->philo[i].status = 1;
		prog->philo[i].eat_time = prog->eat_time;
		prog->philo[i].sleep_time = prog->sleep_time;
		prog->philo[i].die_time = prog->die_time;
		prog->philo[i].total_eat = prog->total_eat;
		prog->philo[i].print = prog->print;
		prog->philo[i].last_eat = 0;
		i++;
	}
}

void	thread_init(t_prog *prog)
{
	pthread_t	inspector;
	int			i;

	if (pthread_create(&inspector, NULL, &monitor, prog) != 0)
		return (NULL);
	i = 0;
	while (i < prog->nphilo)
		if (pthread_create(&prog->philo[i++].thread, NULL, \
		&routine, prog) != 0)
			return (NULL);
	i = 0;
	while (i < prog->nphilo)
		if (pthread_join(prog->philo[i++].thread, NULL) != 0)
			return (NULL);
}
