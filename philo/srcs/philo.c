/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:08:05 by lbastian          #+#    #+#             */
/*   Updated: 2022/02/11 14:56:32 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_parse(char **argv, t_main_s *main_s)
{
	main_s->info_philo.nb_philo = ft_atoi(argv[1]);
	main_s->info_philo.time_die = ft_atoi(argv[2]);
	main_s->info_philo.time_eat = ft_atoi(argv[3]);
	main_s->info_philo.time_sleep = ft_atoi(argv[4]);
	if (main_s->info_philo.nb_philo < 0)
		ft_putstr_error("Error Arg Number of Philo\n");
	else if (main_s->info_philo.nb_philo == 0)
		return (0);
	else if (main_s->info_philo.time_die <= 0)
		ft_putstr_error("Error Arg Time to Die\n");
	else if (main_s->info_philo.time_eat <= 0)
		ft_putstr_error("Error Arg Time to Eat\n");
	else if (main_s->info_philo.time_sleep <= 0)
		ft_putstr_error("Error Arg Time to Sleep\n");
	else if (main_s->info_philo.nb_to_eat == -1)
		ft_putstr_error("Error Arg Number to Eat\n");
	else
		return (1);
	return (0);
}

void	ft_init(t_main_s *main_s)
{
	main_s->thread.tid = malloc(sizeof(pthread_t) * main_s->info_philo.nb_philo);
	main_s->philo_time.i = 0;
}

int	ft_start_thread(t_main_s *main_s)
{
	ft_init(main_s);
	pthread_create(&(main_s->thread.tid[0]), NULL, main_thread, (void *)main_s);	
	pthread_create(&(main_s->thread.tid[1]), NULL, philo_thread, (void *)main_s);	

	pthread_join(main_s->thread.tid[0], NULL);
	pthread_join(main_s->thread.tid[1], NULL);
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
			main_s->info_philo.nb_to_eat = ft_atoi(argv[5]);
		else if (argc == 5)
			main_s->info_philo.nb_to_eat = -2;
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
