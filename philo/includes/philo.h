/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:18:56 by lbastian          #+#    #+#             */
/*   Updated: 2022/02/11 14:56:38 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_info_philo
{
	int	nb_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	nb_to_eat;
}				t_info_philo;

typedef struct s_thread
{
	pthread_t *tid;
}				t_thread;

typedef struct s_philo_time
{
	int i;
}				t_philo_time;

typedef struct s_main_s
{
	t_info_philo	info_philo;
	t_thread		thread;
	t_philo_time	philo_time;
}				t_main_s;

void	ft_putstr(char *str);
void	ft_putstr_error(char *str);
int		ft_atoi(char *str);
void	*philo_thread(void *main_s);
void	*main_thread(void *main_s);

#endif
