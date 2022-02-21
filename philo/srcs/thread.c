/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:24:00 by lbastian          #+#    #+#             */
/*   Updated: 2022/02/21 17:09:57 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ft_philo_thread(void *main_s)
{
	int	id;
	int next;
	int prev;

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
		usleep(2000);
	if (id % 2 == 0)
	{	
		((t_main_s *)main_s)->info_p.forks[prev] = 1;
		((t_main_s *)main_s)->info_p.forks[next] = 1;
	}
	printf("I'm %d \t Next:%d-%d \t Prev%d-%d\n", id, next, ((t_main_s *)main_s)->info_p.forks[next], prev, ((t_main_s *)main_s)->info_p.forks[prev]);
	return (NULL);
}

int	ft_start_mutex(void	*main_s)
{
	int i;

	i = 0;
	while (i < ((t_main_s *)main_s)->info_p.nb_philo)
	{
		((t_main_s *)main_s)->mutex.forks = malloc(sizeof(pthread_mutex_t)
			* ((t_main_s *)main_s)->info_p.nb_philo);
		if (!((t_main_s *)main_s)->mutex.forks)
		{
			ft_putstr_error("Error Malloc mutex forks\n");
			return (1);
		}
		pthread_mutex_init(&(((t_main_s *)main_s)->mutex.forks[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(((t_main_s *)main_s)->mutex.id), NULL);
	return (0);
}

int	ft_start_philo(void *main_s)
{
	int	i;

	i = 0;
	((t_main_s *)main_s)->info_p.id = 0;
	if (ft_start_mutex(main_s))
			return (1);
	while (i < ((t_main_s *)main_s)->info_p.nb_philo)
	{
		pthread_create(&(((t_main_s *)main_s)->thread.tids
			[i + 1]), NULL, ft_philo_thread, main_s);
		i++;
	}
	return (0);
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
