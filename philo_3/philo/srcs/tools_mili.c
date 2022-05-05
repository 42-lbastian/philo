/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_mili.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:43:50 by lbastian          #+#    #+#             */
/*   Updated: 2022/05/05 21:40:44 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

unsigned long	ft_get_mili(struct timeval time)
{
	return ((time.tv_sec) * 1000 + (time.tv_usec) / 1000);
}

unsigned int	ft_get_timestamp(t_main *main)
{
	struct timeval actual;

	gettimeofday(&(actual), NULL);
	return ((unsigned int)(ft_get_mili(actual)
		- main->time.start));
}

unsigned int	ft_get_timedie(t_main *main, int id)
{
	struct timeval actual;

	gettimeofday(&(actual), NULL);
	return (ft_get_mili(actual) - main->time.die[id]);
}

int	ft_wait(t_main *main, unsigned int time, int id)
{
	unsigned int	i;

	i = ft_get_timestamp(main);
	while (ft_get_death(main, id) == 0)
	{
		if (ft_get_timestamp(main) - i > time)
			return (0);
		usleep(1000);
	}
	return (1);
}
