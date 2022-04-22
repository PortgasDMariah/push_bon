/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:21:13 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/22 20:18:40 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "struct.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void	doublerotate(t_data*list, t_data*listb)
{
	ft_printf("rr\n");
	ft_rotate(list, 3);
	ft_rotate(listb, 3);
}

void	rrr(t_data*list, t_data*listb)
{
	ft_printf("rrr\n");
	ft_rrotate(list, 3);
	ft_rrotate(listb, 3);
}

void	ft_delete(t_data*list)
{
	t_node	*head;

	head = list->head;
	list->head = list->head->next;
	free(head);
	if (list->head != NULL)
		list->head->prev = NULL;
}

void	pa(t_data*list, t_data*listb)
{
	ft_printf("pa\n");
	if (listb->head)
		pb(listb, list, 2);
}

void	pb(t_data*list, t_data*listb, int m)
{
	int	tmp;

	if (list->head)
		tmp = list->head->data;
	ft_delete(list);
	if (listb->head != NULL)
		front(listb, ft_lstnew(tmp));
	else
		listb->head = ft_lstnew(tmp);
	if (m == 1)
		ft_printf("pb\n");
}
