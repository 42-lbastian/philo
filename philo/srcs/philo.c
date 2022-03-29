/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:08:05 by lbastian          #+#    #+#             */
/*   Updated: 2022/03/29 16:28:19 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_parse(char **argv, t_main_s *main_s)
{
	main_s->info_p.nb_philo = ft_atoi(argv[1]);
	main_s->info_p.time_die = ft_atoi(argv[2]);
	main_s->info_p.time_eat = ft_atoi(argv[3]);
	main_s->info_p.time_sleep = ft_atoi(argv[4]);
	if (main_s->info_p.nb_philo < 0)
		ft_putstr_error("Error Arg Number of Philo\n");
	else if (main_s->info_p.nb_philo == 0)
		return (0);
	else if (main_s->info_p.time_die <= 0)
		ft_putstr_error("Error Arg Time to Die\n");
	else if (main_s->info_p.time_eat <= 0)
		ft_putstr_error("Error Arg Time to Eat\n");
	else if (main_s->info_p.time_sleep <= 0)
		ft_putstr_error("Error Arg Time to Sleep\n");
	else if (main_s->info_p.nb_to_eat == -1)
		ft_putstr_error("Error Arg Number to Eat\n");
	else
		return (1);
	return (0);
}

/*
int	ft_init_lst(t_main_s *main_s)
{
	int i;

	i = 0;
	main_s->list = ft_lstnew(0);
	if (main_s->list == NULL)
		return (1);
	while (i < (main_s->info_p.nb_philo - 1))
	{
		ft_lstadd_back(&(main_s->list), ft_lstnew(0));
		i++;
	}
	return (0);
}*/

int	ft_start_thread(t_main_s *main_s)
{
	main_s->thread.tids = malloc(sizeof(pthread_t)
			* (main_s->info_p.nb_philo + 1));
	main_s->time_die = malloc(sizeof(struct timeval) * main_s->info_p.nb_philo);
	main_s->info_p.forks = malloc(sizeof(char) * main_s->info_p.nb_philo);
	if (!main_s->thread.tids)
	{
		ft_putstr_error("Error Malloc tids\n");
		return (1);
	}
	if (!main_s->info_p.forks)
	{
		ft_putstr_error("Error Malloc forks\n");
		return (1);
	}
	if (!main_s->time_die)
	{
		ft_putstr_error("Error Malloc time die\n");
		return (1);
	}
	memset((void *)main_s->info_p.forks, 0, main_s->info_p.nb_philo);
	pthread_create(&(main_s->thread.tids[0]), NULL,
		ft_main_thread, (void *)main_s);
	pthread_join(main_s->thread.tids[0], NULL);
	return (0);
}

int	main(int argc, char **argv)
{
	t_main_s	*main_s;

	if (argc == 5 || argc == 6)
	{
		main_s = malloc(sizeof(t_main_s));
		if (!main_s)
		{
			ft_putstr_error("Error Malloc Main Struct\n");
			return (1);
		}
		if (argc == 6)
			main_s->info_p.nb_to_eat = ft_atoi(argv[5]);
		else if (argc == 5)
			main_s->info_p.nb_to_eat = -2;
		if (ft_parse(argv, main_s) == 0)
			return (1);
		return (ft_start_thread(main_s));
	}
	else
	{
		ft_putstr_error("Error Argument\n");
		return (1);
	}
	return (0);
}
