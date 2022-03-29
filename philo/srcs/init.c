/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:23:53 by lbastian          #+#    #+#             */
/*   Updated: 2022/03/29 16:10:29 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_start_mutex(void	*main_s)
{
	int	i;

	i = 0;
	((t_main_s *)main_s)->mutex.forks = malloc(sizeof(pthread_mutex_t)
			* ((t_main_s *)main_s)->info_p.nb_philo);
	if (!((t_main_s *)main_s)->mutex.forks)
	{
		ft_putstr_error("Error Malloc mutex forks\n");
		return (1);
	}
	while (i < ((t_main_s *)main_s)->info_p.nb_philo)
	{
		pthread_mutex_init(&(((t_main_s *)main_s)->mutex.forks[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(((t_main_s *)main_s)->mutex.id), NULL);
	pthread_mutex_init(&(((t_main_s *)main_s)->mutex.time), NULL);
//	pthread_mutex_init(&(((t_main_s *)main_s)->mutex.fork), NULL);
	pthread_mutex_init(&(((t_main_s *)main_s)->mutex.array), NULL);
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
