/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:18:54 by ntairatt          #+#    #+#             */
/*   Updated: 2023/10/04 12:33:23 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_free(t_prog *prog)
{
	size_t	i;

	i = 0;
	pthread_mutex_destroy(&prog->eat);
	pthread_mutex_destroy(&prog->die);
	pthread_mutex_destroy(&prog->print);
	if (prog->nphilo > 1)
	{
		while (i < prog->nphilo)
			pthread_mutex_destroy(&prog->fork[i++]);
		free(prog->fork);
	}
	i = 0;
	if (prog->philo)
	{
		free(prog->philo);
		prog->philo = NULL;
	}
}
