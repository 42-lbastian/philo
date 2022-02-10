/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:18:56 by lbastian          #+#    #+#             */
/*   Updated: 2022/02/10 19:21:00 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_info_philo
{
	int	nb_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	nb_to_eat;
}				t_info_philo;

typedef struct s_main_struct
{
	t_info_philo	info_philo;
}				t_main_struct;

void	ft_putstr(char *str);
void	ft_putstr_error(char *str);
int		ft_atoi(char *str);

#endif
