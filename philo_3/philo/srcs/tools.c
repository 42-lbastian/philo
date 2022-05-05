/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:18:30 by lbastian          #+#    #+#             */
/*   Updated: 2022/05/05 21:39:03 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	neg;
	int	res;
	int	index;

	index = 0;
	neg = 1;
	res = 0;
	if (ft_strlen(str) == 0)
		return (-1);
	if (str[0] == '-')
	{
		index = 1;
		neg = -1;
	}
	while (index < ft_strlen(str))
	{
		if (str[index] > '9' || str[index] < '0')
			return (-1);
		res = (res * 10) + ((int)(str[index] - '0'));
		index++;
	}
	res *= neg;
	return (res);
}

int	ft_change_get_array(t_main *main, int index, int content, int fact)
{
	int	ret;

	pthread_mutex_lock(&(main->mutex.array[index]));
	ret = (main->info_p.forks[index]);
	if (fact == 1)
		main->info_p.forks[index] = content;
	pthread_mutex_unlock(&(main->mutex.array[index]));
	return (ret);
}

int	ft_get_death(t_main *main, int id)
{
	int	ret;

	pthread_mutex_lock(&(main->mutex.death[id]));
	ret = main->info_p.death[id];
	pthread_mutex_unlock(&(main->mutex.death[id]));
	return (ret);
}

void	ft_change_death(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->info_p.nb_philo)
	{
		pthread_mutex_lock(&(main->mutex.death[i]));
		main->info_p.death[i] = 1;
		pthread_mutex_unlock(&(main->mutex.death[i]));
		i++;
	}
}
