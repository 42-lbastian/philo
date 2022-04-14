/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:18:30 by lbastian          #+#    #+#             */
/*   Updated: 2022/04/01 16:57:30 by Bastian          ###   ########.fr       */
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

unsigned long	ft_get_mili(struct timeval time)
{
	return ((time.tv_sec) * 1000 + (time.tv_usec) / 1000);
}

unsigned int	ft_get_timestamp(void * main_s)
{
	gettimeofday(&(((t_main_s *)main_s)->time_actual), NULL);
	return ((unsigned int)(ft_get_mili(((t_main_s *)main_s)->time_actual) - ft_get_mili(((t_main_s *)main_s)->time_start)));
}

unsigned int	ft_get_timedie(void * main_s, int id)
{
	gettimeofday(&(((t_main_s *)main_s)->time_actual), NULL);
	return (ft_get_mili(((t_main_s *)main_s)->time_actual) - ft_get_mili(((t_main_s *)main_s)->time_die[id]));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(unsigned int nb)
{
	unsigned int	size;
	int 			res;

	size = 1;
	if (nb == 0)
		write(1, "0", 1);
	else
	{
		while (size <= nb)
			size *= 10;
		size /= 10;
		while (size != 0)
		{
			res = nb / size % 10;
			ft_putchar(res + '0');
			size /= 10;
		}
	}
}

void	ft_write_status(char *str, unsigned int next, void *main_s)
{
	pthread_mutex_lock(&(((t_main_s *)main_s)->mutex.print));
	ft_putnbr(ft_get_timestamp(main_s));
	write(1, " ", 1);
	ft_putnbr(next);
	write(1, str, ft_strlen(str));
	pthread_mutex_unlock(&(((t_main_s *)main_s)->mutex.print));
}
