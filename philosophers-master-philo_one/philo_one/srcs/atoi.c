/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:58:34 by ybayart           #+#    #+#             */
/*   Updated: 2019/12/18 16:58:35 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (-1);
}

int		ft_atoi(char *str)
{
	int		n;
	int		mult;
	int		i;

	i = 0;
	n = 0;
	mult = 1;
	if (str[i] == '-')
	{
		mult *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]) != -1)
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * mult);
}
