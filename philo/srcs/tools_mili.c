/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_mili.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:43:50 by lbastian          #+#    #+#             */
/*   Updated: 2022/05/02 18:51:01 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

unsigned long	ft_get_mili(struct timeval time)
{
	return ((time.tv_sec) * 1000 + (time.tv_usec) / 1000);
}

unsigned int	ft_get_timestamp(t_main *main)
{
	gettimeofday(&(main->time.s_time_actual), NULL);
	return ((unsigned int)(ft_get_mili(main->time.s_time_actual)
		- main->time.time_start));
}

unsigned int	ft_get_timedie(t_main *main, int id)
{
	gettimeofday(&(main->time.s_time_actual), NULL);
	return (ft_get_mili(main->time.s_time_actual) - main->time.time_die[id]);
}

void	ft_wait(t_main *main, unsigned int time)
{
	unsigned int	i;

	i = ft_get_timestamp(main);
	while (1)
	{
		if (ft_get_timestamp(main) - i > time)
			break ;
		usleep(50);
	}
}
