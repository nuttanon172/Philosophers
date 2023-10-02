/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:41:28 by ntairatt          #+#    #+#             */
/*   Updated: 2023/10/02 11:05:10 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(size_t millisec)
{
	size_t	start;

	start = get_current_time();
	if (get_current_time() - start < millisec)
		usleep(millisec / 2);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_putstr_fd("Error: gettimeofday()\n", 2);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
