/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:28:44 by ntairatt          #+#    #+#             */
/*   Updated: 2023/10/01 17:16:38 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *philo, int id, char *str)
{
	pthread_mutex_lock(&philo->print);
	print("%d %s\n", id, str);
	pthread_mutex_unlock(&philo->print);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	print(philo, philo->id, "has taken a fork");
	pthread_mutex_lock(&philo->r_fork);
	print(philo, philo->id, "has taken a fork");
	philo->eat_count += 1;
	print(philo, philo->id, "is eating");
	ft_sleep(philo->eat_time);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
}

void	nap(t_philo *philo)
{
	print(philo, philo->id, "is sleeping");
	ft_sleep(philo->sleep_time);
}

void	think(t_philo *philo)
{
	print(philo, philo->id, "is thinking");
}
