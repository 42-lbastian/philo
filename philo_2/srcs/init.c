/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:23:53 by lbastian          #+#    #+#             */
/*   Updated: 2022/05/03 15:42:17 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_start_mutex(void	*main)
{
	int	i;

	i = 0;
	((t_main *)main)->mutex.forks = malloc(sizeof(pthread_mutex_t)
			* ((t_main *)main)->info_p.nb_philo);
	((t_main *)main)->mutex.array = malloc(sizeof(pthread_mutex_t)
			* ((t_main *)main)->info_p.nb_philo);
	((t_main *)main)->mutex.death = malloc(sizeof(pthread_mutex_t)
			* ((t_main *)main)->info_p.nb_philo);
	if (!((t_main *)main)->mutex.forks
		|| !((t_main *)main)->mutex.array || !((t_main *)main)->mutex.death)
	{
		ft_putstr_fd("Error Malloc Mutex\n", 2);
		return (1);
	}
	while (i < ((t_main *)main)->info_p.nb_philo)
	{
		pthread_mutex_init(&(((t_main *)main)->mutex.array[i]), NULL);
		pthread_mutex_init(&(((t_main *)main)->mutex.death[i]), NULL);
		pthread_mutex_init(&(((t_main *)main)->mutex.forks[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(((t_main *)main)->mutex.id), NULL);
	pthread_mutex_init(&(((t_main *)main)->mutex.print), NULL);
	return (0);
}

int	ft_malloc_eat(void *main)
{
	int	i;

	i = 0;
	((t_main *)main)->info_p.eat = malloc(sizeof(int)
			* ((t_main *)main)->info_p.nb_philo);
	if (!((t_main *)main)->info_p.eat)
	{
		ft_putstr_fd("Error Malloc Eat\n", 2);
		return (1);
	}
	while (i < ((t_main *)main)->info_p.nb_philo)
	{
		((t_main *)main)->info_p.eat[i] = ((t_main *)main)->info_p.nb_to_eat;
		i++;
	}
	return (0);
}

int	ft_start_philo(void *main)
{
	int				i;
	struct timeval	s_time_start;

	i = 0;
	((t_main *)main)->info_p.id = 0;
	if (ft_start_mutex(main) || ft_malloc_eat(main))
		return (1);
	gettimeofday(&(s_time_start), NULL);
	((t_main *)main)->time.start = ft_get_mili(s_time_start);
	while (i < ((t_main *)main)->info_p.nb_philo)
	{
		pthread_create(&(((t_main *)main)->thread.tids
			[i + 1]), NULL, ft_philo_thread, main);
		i++;
	}
	return (0);
}
