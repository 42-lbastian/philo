/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:18:30 by lbastian          #+#    #+#             */
/*   Updated: 2022/02/25 11:20:23 by Bastian          ###   ########.fr       */
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

void	ft_putstr_error(char *str)
{
	write(2, str, ft_strlen(str));
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	ft_change_get_array(void *main_s, int index, int content, int fact)
{
	int ret;

	pthread_mutex_lock(&(((t_main_s *)main_s)->mutex.array));
	ret = (((t_main_s *)main_s)->info_p.forks[index]);
	if (fact == 1)
		((t_main_s *)main_s)->info_p.forks[index] = content;
	pthread_mutex_unlock(&(((t_main_s *)main_s)->mutex.array));
	return (ret);
}

/*
int	ft_change_get_time(void *main_s, int fact)
{
	int ret;

	pthread_mutex_lock(&(((t_main_s *)main_s)->mutex.time));
	ret = (((t_main_s *)main_s)->time.i);
	if (fact == 1)
		((t_main_s *)main_s)->time.i++;
	pthread_mutex_unlock(&(((t_main_s *)main_s)->mutex.time));
	return (ret);
}*/

suseconds_t	ft_gettime(void * main_s)
{
	return ((((t_main_s *)main_s)->time.tv_usec - ((t_main_s *)main_s)->start_t.us));
}
