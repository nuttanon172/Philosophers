/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:28:44 by ntairatt          #+#    #+#             */
/*   Updated: 2023/10/02 17:07:53 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *philo, char *str, char *color)
{
	pthread_mutex_lock(philo->print);
	printf("%s%zu  ", color, get_current_time() - philo->start_time);
	printf("%d %s\n", philo->id, str);
	pthread_mutex_unlock(philo->print);
}

void	eat(t_philo *philo)
{
	if (!philo->status || (philo->eat_count == philo->max_eat))
		return ;
	pthread_mutex_lock(philo->r_fork);
	print(philo, "has taken a fork", GREEN);
	pthread_mutex_lock(philo->l_fork);
	print(philo, "has taken a fork", GREEN);
	philo->eat_count += 1;
	print(philo, "is eating", GREEN);
	ft_sleep(philo->eat_time);
	philo->last_eat = get_current_time();
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	nap(t_philo *philo)
{
	if (!philo->status)
		return ;
	print(philo, "is sleeping", BLUE);
	ft_sleep(philo->sleep_time);
}

void	think(t_philo *philo)
{
	if (!philo->status)
		return ;
	print(philo, "is thinking", YELLOW);
}
