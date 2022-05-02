/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:08:05 by lbastian          #+#    #+#             */
/*   Updated: 2022/05/02 17:51:07 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_parse(char **argv, t_main *main)
{
	main->info_p.nb_philo = ft_atoi(argv[1]);
	main->info_p.time_die = ft_atoi(argv[2]);
	main->info_p.time_eat = ft_atoi(argv[3]);
	main->info_p.time_sleep = ft_atoi(argv[4]);
	if (main->info_p.nb_philo < 0)
		ft_putstr_fd("Error Arg Number of Philo\n", 2);
	else if (main->info_p.nb_philo == 0)
		return (0);
	else if (main->info_p.time_die <= 0)
		ft_putstr_fd("Error Arg Time to Die\n", 2);
	else if (main->info_p.time_eat <= 0)
		ft_putstr_fd("Error Arg Time to Eat\n", 2);
	else if (main->info_p.time_sleep <= 0)
		ft_putstr_fd("Error Arg Time to Sleep\n", 2);
	else if (main->info_p.nb_to_eat == -1)
		ft_putstr_fd("Error Arg Number to Eat\n", 2);
	else
		return (1);
	return (0);
}

/*
int	ft_init_lst(t_main *main)
{
	int i;

	i = 0;
	main->list = ft_lstnew(0);
	if (main->list == NULL)
		return (1);
	while (i < (main->info_p.nb_philo - 1))
	{
		ft_lstadd_back(&(main->list), ft_lstnew(0));
		i++;
	}
	return (0);
}*/

int	ft_start_thread(t_main *main)
{
	main->thread.tids = malloc(sizeof(pthread_t)
			* (main->info_p.nb_philo + 1));
	main->time.time_die = malloc(sizeof(unsigned long)
			* main->info_p.nb_philo);
	main->info_p.forks = malloc(sizeof(char) * main->info_p.nb_philo);
	if (!main->thread.tids)
	{
		ft_putstr_fd("Error Malloc tids\n", 2);
		return (1);
	}
	if (!main->info_p.forks)
	{
		ft_putstr_fd("Error Malloc forks\n", 2);
		return (1);
	}
	if (!main->time.time_die)
	{
		ft_putstr_fd("Error Malloc time die\n", 2);
		return (1);
	}
	memset((void *)main->info_p.forks, 0, main->info_p.nb_philo);
	pthread_create(&(main->thread.tids[0]), NULL,
		ft_main_thread, (void *)main);
	pthread_join(main->thread.tids[0], NULL);
	return (0);
}

int	main(int argc, char **argv)
{
	t_main	*main;

	if (argc == 5 || argc == 6)
	{
		main = malloc(sizeof(t_main));
		if (!main)
		{
			ft_putstr_fd("Error Malloc Main Struct\n", 2);
			return (1);
		}
		if (argc == 6)
			main->info_p.nb_to_eat = ft_atoi(argv[5]);
		else if (argc == 5)
			main->info_p.nb_to_eat = -2;
		if (ft_parse(argv, main) == 0)
			return (1);
		return (ft_start_thread(main));
	}
	else
	{
		ft_putstr_fd("Error Argument\n", 2);
		return (1);
	}
	return (0);
}
