/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:24:00 by lbastian          #+#    #+#             */
/*   Updated: 2022/05/02 21:16:33 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_take_fork(int id, int prev, t_main *main)
{
	struct timeval	time_die;

	while (ft_change_get_array(main, prev, 0, 0) == 1
		|| ft_change_get_array(main, id, 0, 0) == 1)
	{
		if ((ft_get_timedie(main, id)) > (unsigned int)main->info_p.time_die)
		{
			ft_write_status(" DIE THINK\n\n", id, main);
			return (1);
		}
		usleep(1000);
	}
	ft_change_get_array(main, prev, 1, 1);
	ft_change_get_array(main, id, 1, 1);
	pthread_mutex_lock(&(main->mutex.forks[id]));
	ft_write_status(" has taken a fork\n", id, main);
	pthread_mutex_lock(&(main->mutex.forks[prev]));
	ft_write_status(" has taken a fork\n", id, main);
	ft_write_status(" is eating\n", id, main);
	main->info_p.eat[id]--;
	gettimeofday(&(time_die), NULL);
	main->time.time_die[id] = ft_get_mili(time_die);
	ft_wait(main, main->info_p.time_eat - 1);
	pthread_mutex_unlock(&(main->mutex.forks[prev]));
	pthread_mutex_unlock(&(main->mutex.forks[id]));
	ft_change_get_array(main, prev, 0, 1);
	ft_change_get_array(main, id, 0, 1);
	return (0);
}

int	ft_sleep(int id, t_main	*main)
{
	ft_write_status(" is sleeping\n", id, main);
	if (main->info_p.time_sleep + main->info_p.time_eat < main->info_p.time_die)
		usleep(main->info_p.time_sleep * 1000);
	else
	{
		ft_wait(main, main->info_p.time_die - main->info_p.time_eat);
		ft_write_status(" DIE SLEEP\n", id, main);
		return (1);
	}
	ft_write_status(" is thinking\n", id, main);
	return (0);
}

void	*ft_philo_action(int id, int prev, void *main_s)
{
	t_main	*main;

	main = ((t_main *)main_s);
	while (1)
	{
		if (ft_take_fork(id, prev, main))
			return (NULL);
		if (main->info_p.eat[id] == 0)
			return (NULL);
		if (ft_sleep(id, main))
			return (NULL);
	}
}

void	*ft_philo_thread(void *main)
{
	int				id;
	int				prev;
	struct timeval	time_die;

	pthread_mutex_lock(&(((t_main *)main)->mutex.id));
	id = ((t_main *)main)->info_p.id;
	if (id == 0)
		prev = ((t_main *)main)->info_p.nb_philo - 1;
	else
		prev = id - 1;
	((t_main *)main)->info_p.id++;
	pthread_mutex_unlock(&(((t_main *)main)->mutex.id));
	gettimeofday(&(time_die), NULL);
	if (id % 2)
		usleep((((t_main *)main)->info_p.time_eat / 2) *1000);
//		usleep((((t_main *)main)->info_p.time_eat  / ((t_main
//	*)main)->info_p.nb_philo));
	((t_main *)main)->time.time_die[id] = ft_get_mili(time_die);
	ft_philo_action(id, prev, main);
	return (NULL);
}

void	*ft_main_thread(void *main)
{
	int	count_join;

	count_join = 0;
	if (ft_start_philo(main))
		return (NULL);
	while (count_join < ((t_main *)main)->info_p.nb_philo)
	{
		pthread_join(((t_main *)main)->thread.tids[count_join], NULL);
		count_join++;
	}
	return (NULL);
}
