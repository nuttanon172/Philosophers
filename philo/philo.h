/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:46:29 by ntairatt          #+#    #+#             */
/*   Updated: 2023/10/03 15:34:14 by ntairatt         ###   ########.fr       */
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
	size_t			nphilo;
	pthread_t		thread;
	int				*status;
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
	size_t			nphilo;
	int				max_eat;
	int				status;
	size_t			start_time;
	size_t			eat_time;
	size_t			sleep_time;
	size_t			die_time;
	t_philo			*philo;
	pthread_mutex_t	print;
	pthread_mutex_t	*fork;
}				t_prog;

/* init_philo */
int		prog_init(t_prog *prog, int ac, char **av);
int		fork_init(t_prog *prog);
int		philo_init(t_prog *prog);
int		thread_init(t_prog *prog);

/* routine */
void	*monitor(void *var);
void	*routine(void *var);

/* ft_time */
size_t	timestamp(void);
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

/* ft_free */
void	exit_free(t_prog *prog);
#endif
