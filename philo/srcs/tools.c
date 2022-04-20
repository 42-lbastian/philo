/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:18:30 by lbastian          #+#    #+#             */
/*   Updated: 2022/04/20 14:16:44 by lbastian         ###   ########.fr       */
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

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

int	ft_change_get_array(t_main_s *main, int index, int content, int fact)
{
	int	ret;

	pthread_mutex_lock(&(main->mutex.array[index]));
	ret = (main->info_p.forks[index]);
	if (fact == 1)
		main->info_p.forks[index] = content;
	pthread_mutex_unlock(&(main->mutex.array[index]));
	return (ret);
}

unsigned long	ft_get_mili(struct timeval time)
{
	return ((time.tv_sec) * 1000 + (time.tv_usec) / 1000);
}

unsigned int	ft_get_timestamp(t_main_s *main)
{
	gettimeofday(&(main->time_actual), NULL);
	return ((unsigned int)(ft_get_mili(main->time_actual) - main->time_start));
}

unsigned int	ft_get_timedie(t_main_s *main, int id)
{
	gettimeofday(&(main->time_actual), NULL);
	return (ft_get_mili(main->time_actual) - main->time_die[id]);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(unsigned int nb)
{
	unsigned long	size;
	char			str[11];
	int				i;

	i = 0;
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
			str[i] = ((nb / size % 10) + '0');
			size /= 10;
			i++;
		}
		str[i] = '\0';
		write(1, str, ft_strlen(str));
	}
}

void	ft_write_status(char *str, unsigned int id, t_main_s *main)
{
	pthread_mutex_lock(&(main->mutex.print));
	ft_putnbr(ft_get_timestamp(main));
	write(1, " ", 1);
	ft_putnbr(id);
	write(1, str, ft_strlen(str));
	pthread_mutex_unlock(&(main->mutex.print));
}

void	ft_wait(t_main_s *main, unsigned int time)
{
	unsigned int i;

	i = ft_get_timestamp(main);
	while (1)
	{
		if (ft_get_timestamp(main) - i > time)
			break;
		usleep(50);
	}
}
