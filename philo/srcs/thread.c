/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:24:00 by lbastian          #+#    #+#             */
/*   Updated: 2022/04/19 19:04:29 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_take_fork(int id, int prev, t_main_s *main)
{
//	while (ft_change_get_array(main, prev, 0, 0) == 1)
//	{
//		if (ft_get_timedie(main, id) > (unsigned int)main->info_p.time_die)
//		{
//			printf("\n\n%d-%d-%d DIE THINK\n\n", ft_get_timedie(main, id), ft_get_timestamp(main), id);
//			return (1);
//		}
//	}
//	ft_change_get_array(main, id, 1, 1);
//	ft_change_get_array(main, prev, 1, 1);
	pthread_mutex_lock(&(main->mutex.forks[id]));
//	ft_change_get_array(main_s, id, 1, 1);
	ft_write_status(" has taken a fork\n", id, main);
//	printf("%u %d has taken a fork\n", ft_get_timestamp(main), id);
	pthread_mutex_lock(&(main->mutex.forks[prev]));
	if (ft_get_timedie(main, id)  > (unsigned int)(main->info_p.time_die))
	{
		ft_write_status(" DIED THINK\n", id, main);
		return (1);
	}
	ft_write_status(" has taken a fork\n", id, main);
//	printf("%d %d has taken a fork\n", ft_get_timestamp(main), id);
	ft_write_status(" is eating\n", id, main);
//	printf("%d %d is eating\n", ft_get_timestamp(main), id);

	ft_fuck_sleep(main, main->info_p.time_eat);
//	usleep((main->info_p.time_eat) * 1000);

	pthread_mutex_unlock(&(main->mutex.forks[prev]));
	pthread_mutex_unlock(&(main->mutex.forks[id]));
//	ft_change_get_array(main, prev, 0, 1);
//	ft_change_get_array(main, id, 0, 1);

	return (0);
}

int		ft_sleep(int id, t_main_s	*main)
{
	int i;
	struct timeval time_die;

	i = 0;
	ft_write_status(" is sleeping\n", id, main);
//	printf("%d %d is sleeping\n", ft_get_timestamp(main), id);
	gettimeofday(&(time_die), NULL);
	main->time_die[id] = ft_get_mili(time_die);
	if (main->info_p.time_sleep < main->info_p.time_die)
		usleep(main->info_p.time_sleep * 1000);
	else
	{
		ft_fuck_sleep(main, main->info_p.time_sleep);
	//	usleep(main->info_p.time_die * 1000);
		printf("\n\n%d-%d-%d DIE SLEEP\n\n", ft_get_timedie(main, id), ft_get_timestamp(main), id);
		return (1);
	}
//	while (i < main->info_p.time_sleep /* || signal  */)
//	{
//		if (ft_get_timedie(main, id) > (unsigned int)main->info_p.time_die)
//		{
//			printf("\n\n%d-%d-%d DIE SLEEP\n\n", ft_get_timedie(main, id), ft_get_timestamp(main), id);
//			return (1);
//		}
//		usleep(1000);
//		i++;
//	}
	ft_write_status(" is thinking\n", id, main);
	//printf("%d %d is thinking\n", ft_get_timestamp(main), id);
	return (0);
}

void	*ft_philo_action(int id, int prev, void *main_s)
{
	t_main_s	*main = ((t_main_s *)main_s);
	while (1)
	{
		if (ft_take_fork(id, prev, main) || ft_sleep(id, main))
		{
			exit(0);
		}
	}
	return (NULL);
}

void	*ft_philo_thread(void *main_s)
{
	int	id;
	int	prev;
	struct timeval time_die;

	pthread_mutex_lock(&(((t_main_s *)main_s)->mutex.id));
	id = ((t_main_s *)main_s)->info_p.id;
	if (id == 0)
		prev = ((t_main_s *)main_s)->info_p.nb_philo - 1;
	else
		prev = id - 1;
	((t_main_s *)main_s)->info_p.id++;
	pthread_mutex_unlock(&(((t_main_s *)main_s)->mutex.id));
	gettimeofday(&(time_die), NULL);
	if (id % 2)
		usleep(((t_main_s *)main_s)->info_p.time_eat * 1000); //change
	((t_main_s *)main_s)->time_die[id] = ft_get_mili(time_die);
	ft_philo_action(id, prev, main_s);
	return (NULL);
}

void	*ft_main_thread(void *main_s)
{
	unsigned int i;

	i = 0;
//	gettimeofday(&(((t_main_s *)main_s)->time_start), NULL);
	if (ft_start_philo(main_s))
		return (NULL);
	while (1 && ((t_main_s *)main_s)->info_p.nb_to_eat != 0)
	{
		//if (ft_get_timestamp(main_s) > 500)

	}
	return (NULL);
}
