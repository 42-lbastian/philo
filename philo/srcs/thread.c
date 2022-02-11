/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:24:00 by lbastian          #+#    #+#             */
/*   Updated: 2022/02/11 14:56:28 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_thread(void *main_s)
{
	while (1)
	{
		printf("%d\n", ((t_main_s *)main_s)->philo_time.i);
		sleep(1);
	}
		sleep(1);
	return (NULL);
}

void	*main_thread(void *main_s)
{
	while (1 && ((t_main_s *)main_s)->info_philo.nb_to_eat != 0)
	{
		usleep(1);
	}
	return (NULL);
}
