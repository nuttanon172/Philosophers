/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:18:54 by ntairatt          #+#    #+#             */
/*   Updated: 2023/10/03 11:34:23 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_free(t_prog *prog)
{
	size_t	i;

	i = 0;
	pthread_mutex_destroy(&prog->print);
	if (prog->fork)
	{
		while (i < prog->nphilo)
			pthread_mutex_destroy(&prog->fork[i++]);
		prog->fork = NULL;
	}
	i = 0;
	if (prog->philo)
	{
		while (i < prog->nphilo)
			free(&prog->philo[i++]);
		prog->philo = NULL;
	}
}
