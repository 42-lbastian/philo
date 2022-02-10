/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:18:30 by lbastian          #+#    #+#             */
/*   Updated: 2022/02/10 19:21:02 by lbastian         ###   ########.fr       */
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
