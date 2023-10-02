/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:36:25 by ntairatt          #+#    #+#             */
/*   Updated: 2023/10/02 16:33:58 by ntairatt         ###   ########.fr       */
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
	fork_init(&prog);
	thread_init(&prog);
	return (EXIT_SUCCESS);
}
