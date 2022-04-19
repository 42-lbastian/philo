/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:18:56 by lbastian          #+#    #+#             */
/*   Updated: 2022/04/19 19:02:31 by lbastian         ###   ########.fr       */
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
}				t_info_p;

/*
typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;
*/

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

typedef struct s_main_s
{
	t_info_p		info_p;
	t_thread		thread;
	struct timeval	time_actual;
	unsigned long	time_start;
	unsigned long	*time_die;
	t_mutex			mutex;
}				t_main_s;

/*
**				tools.c 
*/
void			ft_putstr_fd(char *str, int fd);
int				ft_atoi(char *str);
int				ft_change_get_array(t_main_s *main_s, int index,
					int content, int fact);
unsigned int	ft_get_timestamp(t_main_s *main_s);
unsigned long	ft_get_mili(struct timeval time);
unsigned int	ft_get_timedie(t_main_s *main_s, int id);
void			ft_write_status(char *str, unsigned int next, t_main_s *main_s);
void			ft_fuck_sleep(t_main_s *main_s, unsigned int time);

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
