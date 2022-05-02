/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:31:51 by lbastian          #+#    #+#             */
/*   Updated: 2022/02/22 17:06:13 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
int		ft_get_content_index(void *main_s, int index, int content, int fact)
{
	pthread_mutex_lock(&(((t_main_s *)main_s)->mutex.change));
	if (fact == 0)
	{
		if (index == ft_lstsize((t_main_s *)main_s)->list)
		{
			return (ft_lstlast((t_main_s *)main_s)->list->content);
		}
		else
		{
			while (lst->index != index)
			{
				lst = lst->next;
			}
			return (lst->content);
		}
	}
	else
	{
		if (index == ft_lstsize(((t_main_s *)main_s)->list))
			ft_lstlast(((t_main_s *)main_s)->list)->content = content;
		else
		{
			while (((t_main_s *)main_s)->list->index != index)
				((t_main_s *)main_s)->list = (*lst)->next;
			((t_main_s *)main_s)->list->content = content;
		}
		return (0);
	}
	pthread_mutex_unlock(&(((t_main_s *)main_s)->mutex.change));
}*/

/* void	ft_change_content_index(void *main_s, t_list **lst, int index, int content)
{
	pthread_mutex_lock(&(((t_main_s *)main_s)->mutex.change));

	pthread_mutex_unlock(&(((t_main_s *)main_s)->mutex.change));
}

t_list	*ft_lstnew(int content)
{
	t_list *lst;
	lst	= malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->prev = NULL;
	lst->next = NULL;
	lst->index = 0;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = ft_lstlast((*lst));
	if (lst && (*lst))
	{
		ft_lstfront(*lst)->prev = new;
		new->prev = ft_lstlast(*lst);
		new->next = ft_lstfront(*lst);
		if (ft_lstsize(*lst) != 0)
			ft_lstlast(*lst)->index = ft_lstsize((*lst));
		new->index = -1;
		temp->next = new;
	}
	else
		(*lst) = new;
}



   void	ft_lstdelone(t_list *lst)
   {
   }

   void	ft_lstclear(t_list **lst)
   {
   }
  

void	ft_print_list(t_list *lst)
{
	lst = ft_lstfront(lst);
	while (lst->index != -1)
	{
		printf("%d-%d\n", lst->content, lst->index);
		lst = lst->next;
	}
	printf("%d-%d\n", lst->content, lst->index);
}
*/
