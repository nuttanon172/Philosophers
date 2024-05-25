/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:28:44 by ntairatt          #+#    #+#             */
/*   Updated: 2023/12/17 13:09:38 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdead(t_philo *philo)
{
	pthread_mutex_lock(philo->die);
	if (!*philo->status)
		return (pthread_mutex_unlock(philo->die), 1);
	return (pthread_mutex_unlock(philo->die), 0);
}

void	print(t_philo *philo, char *str, char *color)
{
	pthread_mutex_lock(philo->print);
	if (!ft_isdead(philo))
	{
		printf("%s%zu  ", color, timestamp() - philo->start_time);
		printf("%d %s%s\n", philo->id, str, DEFAULT);
	}
	pthread_mutex_unlock(philo->print);
}

void	eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
	}
	print(philo, "has taken a fork", GREEN);
	pthread_mutex_lock(philo->eat);
	philo->eat_count += 1;
	pthread_mutex_unlock(philo->eat);
	pthread_mutex_lock(philo->die);
	philo->last_eat = timestamp();
	pthread_mutex_unlock(philo->die);
	print(philo, "is eating", GREEN);
	ft_sleep(philo->eat_time);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	nap(t_philo *philo)
{
	if (philo->eat_count == philo->max_eat)
		return ;
	print(philo, "is sleeping", BLUE);
	ft_sleep(philo->sleep_time);
}

void	think(t_philo *philo)
{
	if (philo->eat_count == philo->max_eat)
		return ;
	print(philo, "is thinking", YELLOW);
}
