/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:46:29 by ntairatt          #+#    #+#             */
/*   Updated: 2023/10/02 10:46:26 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define RED	"\x1b[31m"
# define GREEN	"\x1b[32m"
# define YELLOW	"\x1b[33m"
# define BLUE	"\x1b[34m"

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				status;
	int				id;
	int				eat_count;
	int				max_eat;
	size_t			last_eat;
	size_t			eat_time;
	size_t			sleep_time;
	size_t			die_time;
	size_t			start_time;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*print;
}					t_philo;

typedef struct s_prog
{
	int				nphilo;
	int				max_eat;
	size_t			eat_time;
	size_t			sleep_time;
	size_t			die_time;
	pthread_mutex_t	*print;
	t_philo			*philo;
}				t_prog;

/* init_philo */
void	prog_init(t_prog *prog, int ac, char **av);
void	fork_init(t_prog *prog);
void	philo_init(t_prog *prog);
void	thread_init(t_prog *prog);

/* routine */
void	monitor(t_prog *prog);
void	routine(t_philo *philo);

/* ft_time */
size_t	get_current_time(void);
void	ft_sleep(size_t millisec);

/* action */
void	print(t_philo *philo, char *str, char *color);
void	eat(t_philo *philo);
void	nap(t_philo *philo);
void	think(t_philo *philo);

/* utils */
size_t	ft_atost(const char *nptr);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);

#endif
