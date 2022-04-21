/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:21:13 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/21 22:06:55 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "struct.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void	doublerotate(bon *list, bon *listb)
{
	ft_printf("rr \n");
	ft_rotate(list, 3);
	ft_rotate(listb, 3);
}

void	rrr(bon *list, bon *listb)
{
	ft_printf("rrr \n");
	ft_rrotate(list, 3);
	ft_rrotate(listb, 3);
}

void	ft_delete(bon *list)
{
	t_node	*head;

	head = list->head;
	list->head = list->head->next;
	free(head);
	if (list->head != NULL)
		list->head->prev = NULL;
}

void	pa(bon *list, bon *listb)
{
	ft_printf("pa \n");
	if (listb->head)
		pb(listb, list, 2);
}

void	pb(bon *list, bon *listb, int m)
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
		ft_printf("pb \n");
}
