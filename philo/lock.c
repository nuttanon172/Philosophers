/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 02:29:50 by ntairatt          #+#    #+#             */
/*   Updated: 2023/10/04 11:57:32 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat_check(t_philo *philo)
{
	pthread_mutex_lock(philo->eat);
	if (philo->eat_count == philo->max_eat)
		return (pthread_mutex_unlock(philo->eat), 1);
	return (pthread_mutex_unlock(philo->eat), 0);
}

int	dead_check(t_philo *philo)
{
	pthread_mutex_lock(philo->die);
	if (timestamp() - philo->last_eat >= philo->die_time)
		return (pthread_mutex_unlock(philo->die), 1);
	return (pthread_mutex_unlock(philo->die), 0);
}
