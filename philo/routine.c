/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:18:20 by ntairatt          #+#    #+#             */
/*   Updated: 2023/10/02 17:05:42 by ntairatt         ###   ########.fr       */
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

void	*monitor(void *var)
{
	t_prog	*prog;
	int	i;

 	i = 0;
	prog = (t_prog *)var;
	ft_sleep(1);
	while (1)
	{
		while (i < prog->nphilo)
			if (ft_isdie(&prog->philo[i++]) || full_eat(prog))
				break ;
		i = 0;
	}
	return (0);
}

void	*routine(void *var)
{
	t_philo	*philo;

	philo = var;
	if (philo->id % 2 == 0)
		usleep(10);
	while (!ft_isdie(philo))
	{
		eat(philo);
		nap(philo);
		think(philo);
	}
	if (ft_isdie(philo))
		print(philo, "is died", RED);
	return (0);
}
