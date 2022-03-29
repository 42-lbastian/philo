/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:24:00 by lbastian          #+#    #+#             */
/*   Updated: 2022/03/28 15:04:08 by Bastian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_take_fork(int next, int prev, void *main_s)
{
	while (ft_change_get_array(main_s, prev, 0, 0) == 1 || ft_change_get_array(main_s, next, 0, 0) == 1)
	{}
	ft_change_get_array(main_s, next, 1, 1);
	ft_change_get_array(main_s, prev, 1, 1);
	pthread_mutex_lock(&(((t_main_s *)main_s)->mutex.forks[next]));
	printf("%d %d has taken a fork\n", ft_gettime(main_s), next);
	pthread_mutex_lock(&(((t_main_s *)main_s)->mutex.forks[prev]));
	printf("%d %d has taken a fork\n", ft_gettime(main_s), next);
	printf("%d %d is eating\n", ft_gettime(main_s), next);

	usleep(((t_main_s *)main_s)->info_p.time_eat * 1000);

	pthread_mutex_unlock(&(((t_main_s *)main_s)->mutex.forks[prev]));
	pthread_mutex_unlock(&(((t_main_s *)main_s)->mutex.forks[next]));
	ft_change_get_array(main_s, prev, 0, 1);
	ft_change_get_array(main_s, next, 0, 1);	

	return (0);
}

int	ft_take_fork_1(int next, int prev, void *main_s)
{
//	while (ft_change_get_array(main_s, prev, 0, 0) == 1 || ft_change_get_array(main_s, next, 0, 0) == 1)
//	{}
//	ft_change_get_array(main_s, next, 1, 1);
//	ft_change_get_array(main_s, prev, 1, 1);
	pthread_mutex_lock(&(((t_main_s *)main_s)->mutex.forks[prev]));
	printf("%d %d has taken a fork\n", ft_gettime(main_s), next);
	pthread_mutex_lock(&(((t_main_s *)main_s)->mutex.forks[next]));
	printf("%d %d has taken a fork\n", ft_gettime(main_s), next);
	printf("%d %d is eating\n", ft_gettime(main_s), next);

	usleep(((t_main_s *)main_s)->info_p.time_eat * 1000);

	pthread_mutex_unlock(&(((t_main_s *)main_s)->mutex.forks[next]));
	pthread_mutex_unlock(&(((t_main_s *)main_s)->mutex.forks[prev]));
//	ft_change_get_array(main_s, prev, 0, 1);
//	ft_change_get_array(main_s, next, 0, 1);	

	return (0);
}

int		ft_sleep(int next, void	*main_s)
{
	int i;

	i = 0;
	printf("%d %d is sleeping\n", ft_gettime(main_s), next);
//	while (i <= ((t_main_s *)main_s)->info_p.time_eat /* || signal  */)
//	{
//		usleep(1000);
//		i++;
//	}
	usleep(((t_main_s *)main_s)->info_p.time_sleep * 1000);
	printf("%d %d is thinking\n", ft_gettime(main_s), next);
	return (0);
}

void	*ft_philo_action(int next, int prev, void *main_s)
{
	while (1)
	{
	//	if (next % 2)
	//		ft_take_fork_1(next, prev, main_s);
	//	else
	//		ft_take_fork_0(next, prev, main_s);
		if (ft_take_fork(next, prev, main_s) || ft_sleep(next, main_s))
		{
			printf("%d %d died\n", ft_gettime(main_s), next);
			exit(0);
		}
	//	usleep(1000);
//		exit(0);
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
//	if (id % 2 == 1)
//		usleep(1000);
//	if (id % 2 == 0)
//		ft_take_fork(next, prev, main_s);
	ft_philo_action(next, prev, main_s);
	return (NULL);
}

void	*ft_main_thread(void *main_s)
{
	gettimeofday(&(((t_main_s *)main_s)->time_start), NULL);
	if (ft_start_philo(main_s))
		return (NULL);
	while (1 && ((t_main_s *)main_s)->info_p.nb_to_eat != 0)
	{
//		if (((t_main_s *)main_s)->time.i == 1000)
//			break ;
	//	usleep(1);
//		ft_change_get_time(main_s, 1);
	}
	return (NULL);
}
