/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tp.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:59:01 by ybayart           #+#    #+#             */
/*   Updated: 2019/12/18 17:07:34 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TP_H
# define PHILO_TP_H

typedef struct	s_philo
{
	int					id;
	unsigned long long	last_eat;
	int					total_eat;
	pthread_mutex_t		lock;
	pthread_t			thread;
}				t_philo;

typedef struct	s_data
{
	int				nb;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	char			state;
	pthread_mutex_t	write;
	pthread_mutex_t	lock;
	t_philo			*philo;

}				t_data;

#endif
