/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:24:00 by lbastian          #+#    #+#             */
/*   Updated: 2022/02/21 18:30:49 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_take_fork(int next, int prev, void *main_s)
{
	int	i;

	pthread_mutex_lock(&(((t_main_s *)main_s)->mutex.fork));
	i = 0;
	printf("%d %d has taken a fork\n", ((t_main_s *)main_s)->time.i, prev);
	printf("%d %d has taken a fork\n", ((t_main_s *)main_s)->time.i, prev);
	((t_main_s *)main_s)->info_p.forks[prev] = 1;
	((t_main_s *)main_s)->info_p.forks[next] = 1;
	printf("%d %d is eating\n", ((t_main_s *)main_s)->time.i, prev);
	while (i < ((t_main_s *)main_s)->info_p.time_eat /* || signal  */)
	{
		usleep(1);
		i++;
	}
	((t_main_s *)main_s)->info_p.forks[prev] = 0;
	((t_main_s *)main_s)->info_p.forks[next] = 0;
	pthread_mutex_unlock(&(((t_main_s *)main_s)->mutex.fork));
}

void	*ft_philo_action(int next, int prev, void *main_s)
{
	while (1)
	{
		if (((t_main_s *)main_s)->info_p.forks[prev] == 0
			&& ((t_main_s *)main_s)->info_p.forks[next] == 0)
			ft_take_fork(next, prev, main_s);
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
		if (((t_main_s *)main_s)->time.i == 1000)
			break ;
		usleep(1);
		((t_main_s *)main_s)->time.i++;
	}
	return (NULL);
}
