/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:00:24 by lbastian          #+#    #+#             */
/*   Updated: 2022/05/06 13:27:24 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_wait_forks_init(int id, int prev, t_main *main)
{
	while (ft_change_get_array(main, prev, 0, READ) == 1
		|| ft_change_get_array(main, id, 0, READ) == 1)
	{
		if ((ft_get_timedie(main, id)) > (unsigned int)main->info_p.time_die)
		{
			ft_write_status(" die\n", id, main, DEATH);
			ft_change_death(main);
			return (1);
		}
		if (ft_wait(main, 1, id))
			return (1);
	}
	return (0);
}

int	ft_take_fork_init(int id, int prev, t_main *main)
{
	struct timeval	time_die;

	if (ft_wait_forks_init(id, prev, main))
		return (1);
	ft_change_get_array(main, prev, 1, CHANGE);
	ft_change_get_array(main, id, 1, CHANGE);
	ft_lock_forks(id, prev, main);
	if (ft_get_death(main, id) == 1)
		return (ft_end_forks(main, prev, id));
	ft_write_status(" has taken a fork\n", id, main, PRINT);
	ft_write_status(" has taken a fork\n", id, main, PRINT);
	ft_write_status(" is eating\n", id, main, PRINT);
	main->info_p.eat[id]--;
	gettimeofday(&(time_die), NULL);
	main->time.die[id] = ft_get_mili(time_die);
	if (ft_wait(main, main->info_p.time_eat - 1, id))
		return (ft_end_forks(main, prev, id));
	ft_unlock_forks(id, prev, main);
	ft_change_get_array(main, prev, 0, CHANGE);
	ft_change_get_array(main, id, 0, CHANGE);
	return (0);
}
