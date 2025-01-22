/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:06:36 by lbastian          #+#    #+#             */
/*   Updated: 2022/05/06 16:34:31 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_end_forks(t_main *main, int prev, int id)
{
	pthread_mutex_unlock(&(main->mutex.forks[prev]));
	pthread_mutex_unlock(&(main->mutex.forks[id]));
	return (1);
}

int	ft_wait_forks(int id, int prev, t_main *main)
{
	while (ft_change_get_array(main, prev, 0, READ) == 1
		|| ft_change_get_array(main, id, 0, READ) == 1
		|| ((unsigned int)main->info_p.time_die
			>= (ft_get_timedie(main, id) + main->info_p.time_eat)))
	{
		if ((ft_get_timedie(main, id)) > (unsigned int)main->info_p.time_die)
		{
			ft_write_status(" died\n", id, main, DEATH);
			ft_change_death(main);
			return (1);
		}
		if (ft_wait(main, 1, id))
			return (1);
	}
	return (0);
}

int	ft_take_fork(int id, int prev, t_main *main)
{
	struct timeval	time_die;

	if (ft_wait_forks(id, prev, main))
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

int	ft_sleep(int id, t_main	*main)
{
	if (ft_get_death(main, id) == 1)
		return (1);
	ft_write_status(" is sleeping\n", id, main, PRINT);
	if (main->info_p.time_sleep + main->info_p.time_eat < main->info_p.time_die)
		ft_wait(main, main->info_p.time_sleep - 1, id);
	else
	{
		if (ft_wait(main, main->info_p.time_die
				- main->info_p.time_eat, id))
			return (1);
		ft_write_status(" died\n", id, main, DEATH);
		ft_change_death(main);
		return (1);
	}
	if (ft_get_death(main, id) == 1)
		return (1);
	ft_write_status(" is thinking\n", id, main, PRINT);
	return (0);
}

void	*ft_philo_action(int id, int prev, void *main_s)
{
	t_main	*main;

	main = ((t_main *)main_s);
	if (ft_take_fork_init(id, prev, main))
		return (NULL);
	if (main->info_p.eat[id] == 0)
		return (NULL);
	while (1)
	{
		if (ft_sleep(id, main))
			return (NULL);
		if (ft_take_fork(id, prev, main))
			return (NULL);
		if (main->info_p.eat[id] == 0)
			return (NULL);
	}
}
