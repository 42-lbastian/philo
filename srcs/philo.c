/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:08:05 by lbastian          #+#    #+#             */
/*   Updated: 2022/05/06 18:12:52 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_parse(char **argv, t_main *main, int argc)
{
	main->info_p.nb_philo = ft_atoi(argv[1]);
	main->info_p.time_die = ft_atoi(argv[2]);
	main->info_p.time_eat = ft_atoi(argv[3]);
	main->info_p.time_sleep = ft_atoi(argv[4]);
	main->info_p.dont_print = 0;
	if (main->info_p.nb_philo < 0 || main->info_p.nb_philo > 200)
		ft_putstr_fd("Error Arg Number of Philo\n", 2);
	else if (main->info_p.nb_philo == 0)
		return (0);
	else if (main->info_p.time_die < 60)
		ft_putstr_fd("Error Arg Time to Die\n", 2);
	else if (main->info_p.time_eat < 60)
		ft_putstr_fd("Error Arg Time to Eat\n", 2);
	else if (main->info_p.time_sleep < 60)
		ft_putstr_fd("Error Arg Time to Sleep\n", 2);
	else if (argc == 6 && main->info_p.nb_to_eat < 0)
		ft_putstr_fd("Error Arg Number to Eat\n", 2);
	else
		return (1);
	return (0);
}

int	ft_start_thread(t_main *main)
{
	int	i;

	i = 0;
	main->thread.tids = malloc(sizeof(pthread_t)
			* (main->info_p.nb_philo + 1));
	main->time.die = malloc(sizeof(unsigned long) * main->info_p.nb_philo);
	main->info_p.forks = malloc(sizeof(int) * main->info_p.nb_philo);
	main->info_p.death = malloc(sizeof(int) * main->info_p.nb_philo);
	if (!main->thread.tids || !main->info_p.forks || !main->time.die
		|| !main->info_p.death)
	{
		ft_putstr_fd("Error Malloc tids | forks | die | death\n", 2);
		return (1);
	}
	while (i < main->info_p.nb_philo)
	{
		main->info_p.forks[i] = 0;
		main->info_p.death[i] = 0;
		i++;
	}
	pthread_create(&(main->thread.tids[0]), NULL,
		ft_main_thread, (void *)main);
	pthread_join(main->thread.tids[0], NULL);
	ft_free_all(main);
	return (0);
}

int	ft_one_philo(t_main *main)
{
	ft_write_status_solo(" has taken a fork\n", 0);
	usleep(main->info_p.time_die * 1000);
	ft_write_status_solo(" die\n", main->info_p.time_die);
	free(main);
	return (1);
}

int	ft_ret_free(t_main *main)
{
	free(main);
	return (1);
}

int	main(int argc, char **argv)
{
	t_main	*main;

	if (argc == 5 || argc == 6)
	{
		main = malloc(sizeof(t_main));
		if (!main)
			return (1);
		if (argc == 6)
			main->info_p.nb_to_eat = ft_atoi(argv[5]);
		else if (argc == 5)
			main->info_p.nb_to_eat = -2;
		if (ft_parse(argv, main, argc) == 0 || main->info_p.nb_to_eat == 0)
			return (ft_ret_free(main));
		if (main->info_p.nb_philo == 1)
			return (ft_one_philo(main));
		return (ft_start_thread(main));
	}
	else
	{
		ft_putstr_fd("Error Argument\n", 2);
		return (1);
	}
	return (0);
}
