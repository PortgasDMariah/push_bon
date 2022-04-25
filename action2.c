/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 22:04:59 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/25 20:05:36 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "struct.h"

void	ft_swap(t_data *list, int m)
{
	t_node	*tmp;

	if (m == 1)
		ft_printf("sa\n");
	else if (m == 2)
		ft_printf("sb\n");
	if (!list->head || !list->head->next)
		return ;
	tmp = list->head;
	tmp->prev = tmp->next;
	if (!tmp->next->next)
		tmp->next = NULL;
	else
		tmp->next = tmp->next->next;
	tmp = tmp->prev;
	tmp->next = tmp->prev;
	tmp->prev = NULL;
	list->head = tmp;
}

void	ft_rrotate(t_data *list, int m)
{
	if (m == 1)
		ft_printf("rra\n");
	else if (m == 2)
		ft_printf("rrb\n");
	if (!list->head->next)
		return ;
	list->before = list->last->prev;
	list->before->next = NULL;
	list->last->prev = NULL;
	list->last->next = list->head;
	list->head->prev = list->last;
	list->head = list->head->prev;
	list->last = list->before;
	list->before = list->before->prev;
}

void	rotate_continu(t_node *tmp, t_node *node, t_data*list)
{
	while (node->next != NULL)
	{
		node = node->next;
		if (node->next == NULL)
		{
			tmp->prev = node;
			node->next = tmp;
			list->before = node;
			list->last = node->next;
			return ;
		}
	}
}

void	ft_rotate(t_data*list, int m)
{
	t_node	*tmp;
	t_node	*node;

	if (m == 1)
		ft_printf("ra\n");
	else if (m == 2)
		ft_printf("rb\n");
	node = list->head;
	tmp = list->head;
	if (node->next == NULL)
	{
		tmp->prev = node;
		node->next = tmp;
		list->last = node->next;
		list->head = node;
		return ;
	}
	node = node->next;
	node->prev = NULL;
	tmp->next = NULL;
	list->head = node;
	rotate_continu(tmp, node, list);
}
