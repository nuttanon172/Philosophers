/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:18:20 by ntairatt          #+#    #+#             */
/*   Updated: 2023/10/01 17:21:51 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	full_eat(t_)
{

}

void	monitor(t_philo *prog)
{
	ft_sleep(1);
	while (1)
	{
		
	}
}

void	routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_sleep(1);
	while (1)
	{
		eat(philo);
		nap(philo);
		think(philo);
	}
}
