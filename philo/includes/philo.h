/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:18:56 by lbastian          #+#    #+#             */
/*   Updated: 2022/05/02 17:43:36 by lbastian         ###   ########.fr       */
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
	pthread_mutex_t	print;
}				t_mutex;

typedef struct	s_time
{
	struct timeval	s_time_actual;
	unsigned long	time_start;
	unsigned long	*time_die;
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
void			ft_wait(t_main *main_s, unsigned int time);

/*
**				tools_mili.c 
*/
unsigned int	ft_get_timestamp(t_main *main_s);
unsigned long	ft_get_mili(struct timeval time);
unsigned int	ft_get_timedie(t_main *main_s, int id);

/*
**				tools_print.c 
*/
int				ft_atoi(char *str);
void			ft_write_status(char *str, unsigned int next, t_main *main_s);
void			ft_putstr_fd(char *str, int fd);

/*
**				thread.c
*/
void			*ft_main_thread(void *main_s);
void			*ft_philo_thread(void *main_s);

/*
**				init.c
*/
int				ft_start_philo(void *main_s);

#endif
