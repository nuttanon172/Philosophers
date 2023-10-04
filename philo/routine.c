/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:18:20 by ntairatt          #+#    #+#             */
/*   Updated: 2023/10/04 12:01:47 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	ft_isdie(t_prog *prog)
{
	size_t	i;

	i = 0;
	while (i < prog->nphilo)
	{
		if (dead_check(&prog->philo[i]))
		{
			print(&prog->philo[i], "died", RED);
			pthread_mutex_lock(&prog->die);
			prog->status = 0;
			return (pthread_mutex_unlock(&prog->die), 1);
		}
		i++;
	}
	return (0);
}

static size_t	full_eat(t_prog *prog)
{
	size_t	i;
	size_t	full;

	i = 0;
	full = 0;
	while (i < prog->nphilo)
	{
		if (eat_check(&prog->philo[i]))
			full++;
		i++;
	}
	if (full == prog->nphilo)
		return (1);
	return (0);
}

void	*monitor(void *var)
{
	t_prog	*prog;

	prog = (t_prog *)var;
	ft_sleep(1);
	while (1)
	{
		if (ft_isdie(prog))
			break ;
		if (full_eat(prog))
			break ;
	}
	return (0);
}

void	*routine(void *var)
{
	t_philo	*philo;

	philo = var;
	if (philo->id % 2 == 0)
		ft_sleep(2);
	while (1)
	{
		if (ft_isdead(philo) || (philo->eat_count == philo->max_eat))
			break ;
		if (philo->nphilo == 1)
		{
			ft_sleep(philo->die_time);
			return (0);
		}
		eat(philo);
		nap(philo);
		think(philo);
	}
	return (0);
}
