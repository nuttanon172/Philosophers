/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:46:29 by ntairatt          #+#    #+#             */
/*   Updated: 2023/12/17 13:06:22 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define RED		"\x1b[31;1m"
# define GREEN		"\x1b[32;1m"
# define YELLOW		"\x1b[33;1m"
# define BLUE		"\x1b[34;1m"
# define DEFAULT	"\033[0m"

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t		thread;
	size_t			nphilo;
	int				*status;
	int				id;
	int				eat_count;
	int				max_eat;
	size_t			last_eat;
	size_t			eat_time;
	size_t			sleep_time;
	size_t			die_time;
	size_t			start_time;
	pthread_mutex_t	*die;
	pthread_mutex_t	*eat;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*print;
}					t_philo;

typedef struct s_prog
{
	pthread_t		inspector;
	size_t			nphilo;
	int				max_eat;
	int				status;
	size_t			start_time;
	size_t			eat_time;
	size_t			sleep_time;
	size_t			die_time;
	t_philo			*philo;
	pthread_mutex_t	eat;
	pthread_mutex_t	die;
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
int		ft_isdead(t_philo *philo);
void	print(t_philo *philo, char *str, char *color);
void	eat(t_philo *philo);
void	nap(t_philo *philo);
void	think(t_philo *philo);

/* utils */
size_t	ft_atost(const char *nptr);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);

/* lock */
int		eat_check(t_philo *philo);
int		dead_check(t_philo *philo);

/* ft_free */
void	exit_free(t_prog *prog);
void	destroy_mutex(t_prog *prog);

#endif
