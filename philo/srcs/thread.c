/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:24:00 by lbastian          #+#    #+#             */
/*   Updated: 2022/05/03 18:49:20 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ft_philo_thread(void *main)
{
	int				id;
	int				prev;
	struct timeval	time_die;

	pthread_mutex_lock(&(((t_main *)main)->mutex.id));
	id = ((t_main *)main)->info_p.id;
	if (id == 0)
		prev = ((t_main *)main)->info_p.nb_philo - 1;
	else
		prev = id - 1;
	((t_main *)main)->info_p.id++;
	pthread_mutex_unlock(&(((t_main *)main)->mutex.id));
	gettimeofday(&(time_die), NULL);
	if (id % 2)
		usleep(30000);
	((t_main *)main)->time.die[id] = ft_get_mili(time_die);
	ft_philo_action(id, prev, main);
	return (NULL);
}

void	*ft_main_thread(void *main)
{
	int	count_join;

	count_join = 1;
	if (ft_start_philo(main))
		return (NULL);
	while (count_join <= ((t_main *)main)->info_p.nb_philo)
	{
		pthread_join(((t_main *)main)->thread.tids[count_join], NULL);
		count_join++;
	}
	return (NULL);
}
