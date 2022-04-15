/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:24:00 by lbastian          #+#    #+#             */
/*   Updated: 2022/04/15 16:27:51 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_take_fork(int id, int prev, void *main_s)
{
	while (ft_change_get_array(main_s, prev, 0, 0) == 1)
	{
		if (ft_get_timedie(main_s, id) >= ((t_main_s *)main_s)->info_p.time_die)
		{
			printf("\n\n%d-%d-%d DIE THINK\n\n", ft_get_timedie(main_s, id), ft_get_timestamp(main_s), id);
			return (1);
		}
	}
	ft_change_get_array(main_s, prev, 1, 1);
	pthread_mutex_lock(&(((t_main_s *)main_s)->mutex.forks[id]));
//	ft_change_get_array(main_s, id, 1, 1);
//	ft_write_status(" has taken a fork\n", id, main_s);
	printf("%u %d has taken a fork\n", ft_get_timestamp(main_s), id);
	pthread_mutex_lock(&(((t_main_s *)main_s)->mutex.forks[prev]));
//	ft_write_status(" has taken a fork\n", id, main_s);
	printf("%d %d has taken a fork\n", ft_get_timestamp(main_s), id);
//	ft_write_status(" is eating\n", id, main_s);
	printf("%d %d is eating\n", ft_get_timestamp(main_s), id);

	usleep(((t_main_s *)main_s)->info_p.time_eat * 1000);

	pthread_mutex_unlock(&(((t_main_s *)main_s)->mutex.forks[prev]));
	pthread_mutex_unlock(&(((t_main_s *)main_s)->mutex.forks[id]));
	ft_change_get_array(main_s, prev, 0, 1);
//	ft_change_get_array(main_s, id, 0, 1);	

	return (0);
}

int		ft_sleep(int id, void	*main_s)
{
	int i;

	i = 0;
//	ft_write_status(" is sleeping\n", id, main_s);
	printf("%d %d is sleeping\n", ft_get_timestamp(main_s), id);
	gettimeofday(&(((t_main_s *)main_s)->time_die[id]), NULL);
	while (i <= ((t_main_s *)main_s)->info_p.time_sleep /* || signal  */)
	{
		if (ft_get_timedie(main_s, id) > ((t_main_s *)main_s)->info_p.time_die)
		{
			printf("\n\n%d DIE SLEEP\n\n", id);
			return (1);
		}
		usleep(1000);
		i++;
	}
//	ft_write_status(" is thinking\n", id, main_s);
	printf("%d %d is thinking\n", ft_get_timestamp(main_s), id);
	return (0);
}

void	*ft_philo_action(int id, int prev, void *main_s)
{
	while (1)
	{
		if (ft_take_fork(id, prev, main_s) || ft_sleep(id, main_s))
			break;
	}
	return (NULL);
}

void	*ft_philo_thread(void *main_s)
{
	int	id;
	int	prev;

	pthread_mutex_lock(&(((t_main_s *)main_s)->mutex.id));
	id = ((t_main_s *)main_s)->info_p.id;
	if (id == 0)
		prev = ((t_main_s *)main_s)->info_p.nb_philo - 1;
	else
		prev = id - 1;
	((t_main_s *)main_s)->info_p.id++;
	pthread_mutex_unlock(&(((t_main_s *)main_s)->mutex.id));
	gettimeofday(&(((t_main_s *)main_s)->time_die[id]), NULL);
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
