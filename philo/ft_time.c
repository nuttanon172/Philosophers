/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:41:28 by ntairatt          #+#    #+#             */
/*   Updated: 2023/10/01 16:37:11 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(size_t millisec)
{
	size_t	start;

	start = get_current_time();
	if (get_current_time - start < millisec)
		usleep(millisec / 2);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "Error: gettimeofday()\n", \
		ft_strlen("Error: gettimeofday()\n"));
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
