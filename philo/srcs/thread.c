/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:24:00 by lbastian          #+#    #+#             */
/*   Updated: 2022/02/22 17:24:28 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_take_fork(int next, int prev, void *main_s)
{
	int	i;
	int y;

	y = 0;
/*	while (ft_get_content_index(main_s, ((t_main_s *)main_s)->list, next == 1)
			&& y < ((t_main_s *)main_s)->info_p.time_die - ((t_main_s *)main_s)->info_p.time_sleep)
	{
		usleep(1);
		y++;
	}
	if (y >= ((t_main_s *)main_s)->info_p.time_die - ((t_main_s *)main_s)->info_p.time_sleep)
	{
		printf("%d Mort\n", next);
		return (1);
	}*/
	pthread_mutex_lock(&(((t_main_s *)main_s)->mutex.forks[next]));
//	ft_change_get_array(main_s, next, 1, 1);
	printf("%d %d has taken a fork\n", ft_change_get_time(main_s, 0), next);
	pthread_mutex_lock(&(((t_main_s *)main_s)->mutex.forks[prev]));
//	ft_change_get_array(main_s, prev, 1, 1);
//	printf("%d has taken a fork\n", ((t_main_s *)main_s)->time.i, next);
	printf("%d %d has taken a fork\n", ft_change_get_time(main_s, 0), next);
	printf("%d %d is eating\n", ft_change_get_time(main_s, 0), next);
//	ft_change_get_array(main_s, prev, 0, 1);
//	ft_change_get_array(main_s, next, 0, 1);
//	printf("%d %d is eating\n", ((t_main_s *)main_s)->time.i, next);
	pthread_mutex_unlock(&(((t_main_s *)main_s)->mutex.forks[prev]));
	pthread_mutex_unlock(&(((t_main_s *)main_s)->mutex.forks[next]));
	i = 0;
	while (i <= ((t_main_s *)main_s)->info_p.time_eat /* || signal  */)
	{
		usleep(1);
		i++;
	}
	printf("%d %d is sleeping\n", ft_change_get_time(main_s, 0), next);
	return (0);
}

void	*ft_philo_action(int next, int prev, void *main_s)
{
	while (1)
	{
		if (ft_take_fork(next, prev, main_s) == 1)
		usleep(1000);
		exit(0);
	}
	return (NULL);
}

void	*ft_philo_thread(void *main_s)
{
	int	id;
	int	next;
	int	prev;

	pthread_mutex_lock(&(((t_main_s *)main_s)->mutex.id));
	id = ((t_main_s *)main_s)->info_p.id;
	if (id == 0)
		prev = ((t_main_s *)main_s)->info_p.nb_philo - 1;
	else
		prev = id - 1;
	next = id;
	((t_main_s *)main_s)->info_p.id++;
	pthread_mutex_unlock(&(((t_main_s *)main_s)->mutex.id));
	if (id % 2 == 1)
		usleep(1000);
	if (id % 2 == 0)
		ft_take_fork(next, prev, main_s);
	ft_philo_action(next, prev, main_s);
	return (NULL);
}

void	*ft_main_thread(void *main_s)
{
	((t_main_s *)main_s)->time.i = 0;
	if (ft_start_philo(main_s))
		return (NULL);
	while (1 && ((t_main_s *)main_s)->info_p.nb_to_eat != 0)
	{
//		if (((t_main_s *)main_s)->time.i == 1000)
//			break ;
		usleep(1);
		ft_change_get_time(main_s, 1);
	}
	return (NULL);
}
