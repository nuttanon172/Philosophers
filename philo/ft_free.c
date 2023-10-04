/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:18:54 by ntairatt          #+#    #+#             */
/*   Updated: 2023/10/04 15:09:28 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_prog *prog)
{
	pthread_mutex_destroy(&prog->eat);
	pthread_mutex_destroy(&prog->die);
	pthread_mutex_destroy(&prog->print);
}

void	exit_free(t_prog *prog)
{
	size_t	i;

	i = 0;
	destroy_mutex(prog);
	if (prog->nphilo > 1)
	{
		while (i < prog->nphilo)
			pthread_mutex_destroy(&prog->fork[i++]);
		if (prog->fork)
			free(prog->fork);
	}
	i = 0;
	if (prog->philo)
	{
		free(prog->philo);
		prog->philo = NULL;
	}
}
