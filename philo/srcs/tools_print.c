/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:43:29 by lbastian          #+#    #+#             */
/*   Updated: 2022/05/03 17:59:32 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	ret_write;

	ret_write = write(fd, str, ft_strlen(str));
}

void	ft_putchar(char c)
{
	int	ret_write;

	ret_write = write(1, &c, 1);
}

void	ft_putnbr(unsigned int nb)
{
	unsigned long	size;
	char			str[11];
	int				i;
	int				ret_write;

	i = 0;
	size = 1;
	if (nb == 0)
		ret_write = write(1, "0", 1);
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
		ret_write = write(1, str, ft_strlen(str));
	}
}

void	ft_write_status(char *str, unsigned int id, t_main *main)
{
	int	ret_write;

	pthread_mutex_lock(&(main->mutex.print));
	ft_putnbr(ft_get_timestamp(main));
	ret_write = write(1, " ", 1);
	ft_putnbr(id);
	ret_write = write(1, str, ft_strlen(str));
	pthread_mutex_unlock(&(main->mutex.print));
}

void	ft_write_status_solo(char *str, int time)
{
	int	ret_write;

	ft_putnbr(time);
	ret_write = write(1, " ", 1);
	ft_putnbr(0);
	ret_write = write(1, str, ft_strlen(str));
}
