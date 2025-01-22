/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:46:41 by lbastian          #+#    #+#             */
/*   Updated: 2022/05/03 18:04:52 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_destroy_mutex(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->info_p.nb_philo)
	{
		pthread_mutex_destroy(&(main->mutex.array[i]));
		pthread_mutex_destroy(&(main->mutex.death[i]));
		pthread_mutex_destroy(&(main->mutex.forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(main->mutex.id));
	pthread_mutex_destroy(&(main->mutex.print));
}

void	ft_free_all(t_main *main)
{
	ft_destroy_mutex(main);
	free(main->mutex.array);
	free(main->mutex.death);
	free(main->mutex.forks);
	free(main->time.die);
	free(main->info_p.eat);
	free(main->info_p.forks);
	free(main->info_p.death);
	free(main->thread.tids);
	free(main);
}
