/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:51:47 by ntairatt          #+#    #+#             */
/*   Updated: 2023/09/29 18:28:48 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_init(t_prog *prog)
{
	int				i;
	pthread_mutex_t	*fork;

	i = 0;
	fork = ft_calloc(prog->nphilo * sizeof(pthread_mutex_t));
	if (!fork)
		return (NULL);
	prog->philo[i].l_fork = &fork[i];
	prog->philo[i].r_fork = &fork[prog->nphilo - 1];
	i = 1;
	while (i < prog->nphilo)
	{
		prog->philo[i].l_fork = &fork[i];
		prog->philo[i].r_fork = &fork[i - 1]; 
		i++;
	}
}

void	prog_init(t_prog *prog, int ac, char **av)
{
	int	i;

	i = 0;
	prog->nphilo = ft_atol(av[1]);
	prog->philo = ft_calloc(prog->nphilo * sizeof(pthread_t));
	if (!prog->philo)
		return (NULL);
	while (i < prog->nphilo)
	{
		prog->philo[i].id = i + 1;
		prog->philo[i].died_time = ft_atol(av[2]);
		prog->philo[i].eat_time = ft_atol(av[3]);
		prog->philo[i].sleep_time = ft_atol(av[4]);
		prog->philo[i].total_eat = -1;
		if (ac > 5)
			prog->philo[i].total_eat = ft_atol(av[5]);
		i++;
	}
	fork_init(prog);
}
