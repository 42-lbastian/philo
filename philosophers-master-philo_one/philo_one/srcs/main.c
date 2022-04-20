/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:58:43 by ybayart           #+#    #+#             */
/*   Updated: 2019/12/18 17:13:22 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		endofprog(void)
{
	if (g_data.state >= 1)
		free(g_data.philo);
	return (0);
}

int		main_do(int argc)
{
	int					i;
	char				eat;
	unsigned long long	time;

	i = -1;
	time = gettime();
	eat = 1;
	while (++i < g_data.nb)
	{
		if (argc == 6 && eat == 1 &&
			g_data.philo[i].total_eat < g_data.must_eat)
			eat = 0;
		if (g_data.philo[i].last_eat + g_data.time_die < time)
		{
			msg(time, i, " died\n", 6);
			return (endofprog());
		}
	}
	pthread_mutex_lock(&g_data.write);
	if (argc == 6 && eat == 1)
		return (endofprog());
	pthread_mutex_unlock(&g_data.write);
	return (1);
}

int		main(int argc, char **argv)
{
	int					i;

	g_data.state = 0;
	if ((argc != 5 && argc != 6) || init(argc, argv) == 0)
	{
		write(1, "error\n", 6);
		return (EXIT_FAILURE);
	}
	i = -1;
	while (++i < g_data.nb)
		pthread_create(&g_data.philo[i].thread, NULL,
				thread, (void *)&g_data.philo[i].id);
	i = -1;
	while (1)
	{
		if (main_do(argc) == 0)
			break ;
	}
	return (0);
}
