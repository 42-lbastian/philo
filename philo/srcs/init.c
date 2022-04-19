/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:23:53 by lbastian          #+#    #+#             */
/*   Updated: 2022/04/19 18:36:10 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_start_mutex(void	*main_s)
{
	int	i;

	i = 0;
	((t_main_s *)main_s)->mutex.forks = malloc(sizeof(pthread_mutex_t)
			* ((t_main_s *)main_s)->info_p.nb_philo);
	((t_main_s *)main_s)->mutex.array = malloc(sizeof(pthread_mutex_t)
			* ((t_main_s *)main_s)->info_p.nb_philo);
	if (!((t_main_s *)main_s)->mutex.forks || !((t_main_s *)main_s)->mutex.array)
	{
		ft_putstr_fd("Error Malloc mutex forks/array\n", 2);
		return (1);
	}
	while (i < ((t_main_s *)main_s)->info_p.nb_philo)
	{
		pthread_mutex_init(&(((t_main_s *)main_s)->mutex.array[i]), NULL);
		pthread_mutex_init(&(((t_main_s *)main_s)->mutex.forks[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(((t_main_s *)main_s)->mutex.id), NULL);
	pthread_mutex_init(&(((t_main_s *)main_s)->mutex.print), NULL);
	return (0);
}

int	ft_start_philo(void *main_s)
{
	int	i;
	struct timeval time_start;

	i = 0;
	((t_main_s *)main_s)->info_p.id = 0;
	if (ft_start_mutex(main_s))
		return (1);
	gettimeofday(&(time_start), NULL);
	((t_main_s *)main_s)->time_start = ft_get_mili(time_start);
	while (i < ((t_main_s *)main_s)->info_p.nb_philo)
	{
		pthread_create(&(((t_main_s *)main_s)->thread.tids
			[i + 1]), NULL, ft_philo_thread, main_s);
		i++;
	}
	return (0);
}
