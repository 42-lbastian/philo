/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:58:56 by ybayart           #+#    #+#             */
/*   Updated: 2019/12/18 16:58:57 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# include "philo_tp.h"

t_data	g_data;

int					ft_atoi(char *str);
int					init(int argc, char **argv);
void				*thread(void *arg);
unsigned long long	gettime(void);
void				ft_putnbr(unsigned long long n);
void				msg(unsigned long long time, int act, char *text, int len);
int					ft_str_is_numeric(char *str);

#endif
