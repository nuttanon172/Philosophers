/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:18:20 by ntairatt          #+#    #+#             */
/*   Updated: 2023/10/02 10:28:44 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	full_eat(t_prog *prog)
{
	int	i;
	int	full;

	i = 0;
	full = 0;
	while (i < prog->nphilo)
	{
		if (prog->philo->eat_count == prog->philo->max_eat)
			full++;
	}
	if (full == prog->nphilo)
		return (1);
	return (0);
}

static int	ft_isdie(t_philo *philo)
{
	if (get_current_time() - philo->last_eat >= philo->eat_time)
	{
		philo->status = 0;
		return (1);
	}
	else
		return (0);
}

void	monitor(t_prog *prog)
{
	int	i;

	i = 0;
	ft_sleep(1);
	while (1)
	{
		while (i < prog->nphilo)
			if (ft_isdie(&prog->philo[i++]) || full_eat(prog))
				break ;
		i = 0;
	}
}

void	routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_sleep(1);
	while (!ft_isdie(philo))
	{
		eat(philo);
		nap(philo);
		think(philo);
	}
}
