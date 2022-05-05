/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:18:56 by lbastian          #+#    #+#             */
/*   Updated: 2022/05/05 16:14:44 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# define DEATH 1
# define PRINT 0
# define INIT 1
# define NORMAL 0

typedef struct s_info_p
{
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_to_eat;
	int				id;
	int				*forks;
	int				die;
	int				*eat;
	int				*death;
	int				dont_print;
}				t_info_p;

typedef struct s_thread
{
	pthread_t	*tids;
}				t_thread;

typedef struct s_mutex
{
	pthread_mutex_t	id;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*array;
	pthread_mutex_t	*death;
	pthread_mutex_t	print;
}				t_mutex;

typedef struct s_time
{
	struct timeval	s_actual;
	unsigned long	start;
	unsigned long	*die;
}				t_time;

typedef struct s_main
{
	t_info_p	info_p;
	t_thread	thread;
	t_mutex		mutex;
	t_time		time;
}				t_main;

/*
**				tools.c 
*/
int				ft_strlen(char *str);
int				ft_change_get_array(t_main *t_main, int index,
					int content, int fact);
int				ft_get_death(t_main *main, int id);
void			ft_change_death(t_main *main);

/*
**				tools_mili.c 
*/
unsigned int	ft_get_timestamp(t_main *main_s);
unsigned long	ft_get_mili(struct timeval time);
unsigned int	ft_get_timedie(t_main *main_s, int id);
int				ft_wait(t_main *main_s, unsigned int time, int id);

/*
**				tools_print.c 
*/
int				ft_atoi(char *str);
int				ft_write_status(char *str, unsigned int id,
					t_main *main_s, int fact);
int				ft_write_status_solo(char *str, int time);
int				ft_putstr_fd(char *str, int fd);

/*
**				thread.c
*/
void			*ft_main_thread(void *main_s);
void			*ft_philo_thread(void *main_s);

/*
**				philo_actions.c
*/
void			*ft_philo_action(int id, int prev, void *main_s);
int				ft_end_forks(t_main *main, int prev, int id);

/*
**				philo_actions_init.c
*/
int				ft_take_fork_init(int id, int prev, t_main *main);
int				ft_take_fork_init_odd(int id, int prev, t_main *main);

/*
**				forks.c
*/
void			ft_lock_forks(int id, int prev, t_main *main);
void			ft_unlock_forks(int id, int prev, t_main *main);

/*
**				init.c
*/
int				ft_start_philo(void *main_s);

/**
**				free.c
*/
void			ft_free_all(t_main *main);

#endif
