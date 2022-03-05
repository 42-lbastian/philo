/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:18:56 by lbastian          #+#    #+#             */
/*   Updated: 2022/02/25 11:23:24 by Bastian          ###   ########.fr       */
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
	int	nb_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	nb_to_eat;
	int	id;
	int	*forks;
}				t_info_p;

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

typedef struct s_thread
{
	pthread_t	*tids;
}				t_thread;

typedef struct s_time
{
	suseconds_t	us;
}				t_time;

typedef struct s_mutex
{
	pthread_mutex_t	id;
	pthread_mutex_t	*forks;
	pthread_mutex_t	sleep;
	pthread_mutex_t	array;
	pthread_mutex_t	time;
}				t_mutex;

typedef struct s_main_s
{
	t_info_p		info_p;
	t_thread		thread;
	struct timeval	time;
	t_time			start_t;
	t_mutex			mutex;
	t_list			*list;
}				t_main_s;

void		ft_putstr(char *str);
void		ft_putstr_error(char *str);
int			ft_atoi(char *str);
void		*ft_main_thread(void *main_s);
void		*ft_philo_thread(void *main_s);
int			ft_start_philo(void *main_s);
int			ft_change_get_array(void *main_s, int index, int content, int fact);
int			ft_change_get_time(void *main_s, int fact);
suseconds_t	ft_gettime(void *main_s);

#endif
