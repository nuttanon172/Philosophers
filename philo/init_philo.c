/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:51:47 by ntairatt          #+#    #+#             */
/*   Updated: 2023/09/30 18:25:59 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	prog->philo[0].print = prog->print;
	i = 1;
	while (i < prog->nphilo)
	{
		prog->philo[i].l_fork = &fork[i];
		prog->philo[i].r_fork = &fork[i - 1];
		prog->philo[i].print = prog->print;
		i++;
	}
}

void	prog_init(t_prog *prog, int ac, char **av)
{
	int	i;

	i = 0;
	prog->nphilo = (int)ft_atost(av[1]);
	prog->print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(prog->print, NULL) != 0)
		return (NULL);
	prog->philo = (pthread_t *)malloc(prog->nphilo * sizeof(pthread_t));
	if (!prog->philo)
		return (NULL);
	while (i < prog->nphilo)
	{
		prog->philo[i].id = i + 1;
		prog->philo[i].died_time = ft_atost(av[2]);
		prog->philo[i].eat_time = ft_atost(av[3]);
		prog->philo[i].sleep_time = ft_atost(av[4]);
		prog->philo[i].total_eat = -1;
		if (ac > 5)
			prog->philo[i].total_eat = (int)ft_atost(av[5]);
		i++;
	}
	fork_init(prog);
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

void	monitor(t_prog *prog)
{

}

void	routine(t_prog *prog)
{

}
