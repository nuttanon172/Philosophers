/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:36:25 by ntairatt          #+#    #+#             */
/*   Updated: 2023/10/03 15:11:34 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_prog	prog;

	if (ac < 5 || ac > 6)
		return (EXIT_FAILURE);
	prog_init(&prog, ac, av);
	philo_init(&prog);
	if (prog.nphilo > 1)
		fork_init(&prog);
	thread_init(&prog);
	ft_sleep(5);
	exit_free(&prog);
	return (EXIT_SUCCESS);
}
