/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:18:20 by ntairatt          #+#    #+#             */
/*   Updated: 2023/10/02 18:37:02 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	full_eat(t_prog *prog)
{
	size_t	i;
	size_t	full;

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
		print(philo, "is died", RED);
		return (1);
	}
	else
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
		ft_sleep(5);
	while (1)
	{
		eat(philo);
		nap(philo);
		think(philo);
		if (ft_isdie(philo))
			break ;
	}
	return (0);
}
