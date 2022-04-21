/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 22:04:59 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/21 22:06:06 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "struct.h"

void	ft_swap(bon *list)
{
	ft_printf("sa \n");
	list->node = list->head;
	list->node->prev = list->node->next;
	list->node->next = list->node->next->next;
	list->node = list->node->next;
	list->node = list->node->prev;
	list->node->next = list->node->prev;
	list->node->prev = NULL;
	list->node = list->node->next->next;
	list->node->prev = (list->node->prev)->next;
	list->node = list->node->prev->prev;
	list->head = list->node;
}

void	ft_rrotate(bon *list, int m)
{
	if (m == 1)
		ft_printf("rra \n");
	else if (m == 2)
		ft_printf("rrb \n");
	list->before = list->last->prev;
	list->before->next = NULL;
	list->last->prev = NULL;
	list->last->next = list->head;
	list->head->prev = list->last;
	list->head = list->head->prev;
	list->last = list->before;
	list->before = list->before->prev;
}

void	rotate_continu(t_node *tmp, t_node *node, bon *list, int m)
{
	if (m == 1)
		ft_printf("ra \n");
	else if (m == 2)
		ft_printf("rb \n");
	while   (node->next != NULL)
	{
		node = node->next;
		if (node->next == NULL)
		{
			tmp->prev = node;
			node->next = tmp;
			list->before = node;
			list->last = node->next;
			return  ;
		}
	}
}

void	ft_rotate(bon *list, int m)
{
	t_node	*tmp;
	t_node	*node;

	node = list->head;
	tmp = list->head;
	node = node->next;
	node->prev = NULL;
	tmp->next = NULL;
	list->head = node;
	if (node->next == NULL)
	{
		tmp->prev = node;
		node->next = tmp;
		list->last = node->next;
		list->head = node;
		return  ;
	}
	rotate_continu(tmp, node, list, m);
}
