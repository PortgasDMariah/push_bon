/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 22:23:06 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/22 20:17:58 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "struct.h"

void	init(t_data*list, t_data*listb)
{
	list->fin = 0;
	list->tot = 0;
	listb->count = 0;
	list->min = NULL;
	list->chef = NULL;
	listb->push = NULL;
	listb->tmp = NULL;
	listb->tmp2 = NULL;
	list->head = NULL;
	list->before = NULL;
	list->last = NULL;
	list->node = NULL;
	list->tmp = NULL;
	list->maxi = NULL;
	listb->head = NULL;
	listb->min = NULL;
	listb->chef = NULL;
	list->tmp2 = malloc(sizeof(t_node));
	list->test = NULL;
	list->test = list->tmp2;
	list->i = 1;
	list->val = 0;
	list->j = 0;
	list->who = 0;
	list->max = 0;
}

void	create_stack_a(t_data*list, char *av, int tmp)
{
	int	val;

	val = 0;
	if (tmp == 1)
	{
		list->head = ft_lstnew(ft_parsing(av, list));
		list->head->prev = NULL;
		list->min = list->head;
	}
	else
	{
		val = ft_parsing(av, list);
		ft_lstadd_back(&list->head, ft_lstnew(val), list);
		if (val < list->min->data)
			list->min = list->last;
	}
}

void	firsti(t_data*list, t_node *c)
{
	position(list);
	if (c->mouv < 0)
	{
		while (list->head->data != c->data)
			ft_rrotate(list, 1);
	}
	else if (c->mouv > 0)
	{
		while (list->head->data != c->data)
			ft_rotate(list, 1);
	}
//	if (sorted_or_not(list) != 0)
	//	quit_well(list, 3);
}

void	lets_sort(t_data*list, t_data*listb)
{
	if (sorted_or_not(list) == 0)
	{
		listmax(list);
		if (list->tot == 4 || list->tot == 6)
			three_to_five(list, listb);
		firsti(list, list->min);
		lis(list, listb);
		organisation(list, listb);
		firsti(list, list->min);
		quit_well(list, 2);
	}
}
