/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:59:30 by ntairatt          #+#    #+#             */
/*   Updated: 2023/10/04 12:03:40 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	av_check(int ac, char **av)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < (size_t)ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			else
				j++;
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_prog	prog;

	if (ac < 5 || ac > 6 || av_check(ac, av))
		return (ft_putstr_fd("Error: Input error\n", 2), EXIT_FAILURE);
	prog_init(&prog, ac, av);
	if (pthread_mutex_init(&prog.print, NULL) != 0)
		return (ft_putstr_fd("Error: Print init error\n", 2), EXIT_FAILURE);
	if (!philo_init(&prog))
	{
		return (pthread_mutex_destroy(&prog.print), \
			ft_putstr_fd("Error: Philo init error\n", 2), 1);
	}
	if (prog.nphilo > 1)
	{
		if (!fork_init(&prog))
		{
			pthread_mutex_destroy(&prog.print);
			return (ft_putstr_fd("Error: Fork init error\n", 2), EXIT_FAILURE);
		}
	}
	if (!thread_init(&prog))
		ft_putstr_fd("Error: Thread init error\n", 2);
	exit_free(&prog);
	return (EXIT_SUCCESS);
}
