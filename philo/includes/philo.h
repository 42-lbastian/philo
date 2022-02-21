/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:18:56 by lbastian          #+#    #+#             */
/*   Updated: 2022/02/21 17:09:56 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>

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

typedef struct s_thread
{
	pthread_t	*tids;
}				t_thread;

typedef struct s_time
{
	int	i;
}				t_time;

typedef struct s_mutex
{
	pthread_mutex_t	id;
	pthread_mutex_t *forks;
}				t_mutex;

typedef struct s_main_s
{
	t_info_p		info_p;
	t_thread		thread;
	t_time			time;
	t_mutex			mutex;
}				t_main_s;

void	ft_putstr(char *str);
void	ft_putstr_error(char *str);
int		ft_atoi(char *str);
void	*ft_main_thread(void *main_s);

#endif
