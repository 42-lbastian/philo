/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:31:51 by lbastian          #+#    #+#             */
/*   Updated: 2022/02/21 19:58:16 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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


/*
void	ft_lstdelone(t_list *lst)
{
}

void	ft_lstclear(t_list **lst)
{
}
*/

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
