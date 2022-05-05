/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:13:32 by lbastian          #+#    #+#             */
/*   Updated: 2022/05/05 16:26:50 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_lock_forks(int id, int prev, t_main *main)
{
	if (id % 2)
	{
		pthread_mutex_lock(&(main->mutex.forks[id]));
		pthread_mutex_lock(&(main->mutex.forks[prev]));
	}
	else
	{
		pthread_mutex_lock(&(main->mutex.forks[prev]));
		pthread_mutex_lock(&(main->mutex.forks[id]));
	}
}

void	ft_unlock_forks(int id, int prev, t_main *main)
{
	if (id % 2)
	{
		pthread_mutex_unlock(&(main->mutex.forks[id]));
		pthread_mutex_unlock(&(main->mutex.forks[prev]));
	}
	else
	{
		pthread_mutex_unlock(&(main->mutex.forks[prev]));
		pthread_mutex_unlock(&(main->mutex.forks[id]));
	}
}
