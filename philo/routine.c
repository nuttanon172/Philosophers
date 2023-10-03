/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:18:20 by ntairatt          #+#    #+#             */
/*   Updated: 2023/10/03 14:33:57 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	ft_isdie(t_prog *prog)
{
	size_t	i;

	i = 0;
	while (i < prog->nphilo)
	{
		if (timestamp() - prog->philo[i].last_eat >= prog->philo[i].die_time)
		{
			print(&prog->philo[i], "died", RED);
			prog->status = 0;
			return (1);
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
		if (prog->philo[i].eat_count == prog->philo[i].max_eat)
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
	size_t	i;

	i = 0;
	prog = (t_prog *)var;
	ft_sleep(1);
	while (1)
	{
		if (ft_isdie(prog))
			break ;
		if (full_eat(prog))
			break ;
	}
	return (var);
}

void	*routine(void *var)
{
	t_philo	*philo;

	philo = var;
	if (philo->id % 2 == 0)
		ft_sleep(2);
	while (1)
	{
		if (philo->nphilo == 1)
		{
			ft_sleep(philo->die_time);
			return (var);
		}
		eat(philo);
		nap(philo);
		think(philo);
		if (!*philo->status || (philo->eat_count == philo->max_eat))
			break ;
	}
	return (var);
}
