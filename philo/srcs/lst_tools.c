/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:50:43 by lbastian          #+#    #+#             */
/*   Updated: 2022/02/22 17:03:32 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_list	*ft_lstfront(t_list *lst)
{
	while (lst->index != 0)
		lst = lst->prev;
	return (lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst->index == 0 && lst->next == NULL)
		return (lst);
	while (lst->index != -1)
		lst = lst->next;
	return (lst);
}

int		ft_lstsize(t_list *lst)
{
	int i;

	i = 0;
	while (lst->index != 0)
		lst = lst->prev;
	if (lst->next == NULL)
		return (0);
	else
	{
		while (lst->index != -1)
		{
			lst = lst->next;
			i++;
		}
	}
	return (i);
}
