/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_5numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:08:26 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/21 21:12:04 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "struct.h"

void	firstone(bon *list, bon *listb, t_node *c)
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
	pb(list, listb, 1);
}

void	listmin(bon *list)
{
	t_node	*tmp2;

	tmp2 = list->head;
	list->min = list->head;
	while   (tmp2)
	{
		if  (list->min->data > tmp2->data)
			list->min = tmp2;
		tmp2 = tmp2->next;
	}
}

void	five(bon *list, bon *listb)
{
	t_node	*min2;

	min2 = found_your_place(list, list->min->data);
	firsti(list, list->min);
	pb(list, listb, 1);
	firsti(list, min2);
	pb(list, listb, 1);
	listmin(list);
	three(list);
	pa(listb, list);
	pa(listb, list);
}

void	three(bon *list)
{
	list->maxi = list->chef;
	position(list);
	list->chef = list->maxi;
	if  (!(list->min->mouv == 0 && list->chef->mouv == list->fin))
	{
		if  ((list->min->mouv == list->fin && list->chef->mouv == 0)
			|| (list->chef->mouv != 0 && list->min->mouv == 1))
			ft_swap(list);
		else if  (list->chef->mouv == 0 && list->min->mouv == 1)
			ft_rotate(list, 1);
		else if  ((list->min->mouv == 0 && list->chef->mouv == 1)
			|| list->min->mouv == list->fin)
			ft_rrotate(list, 1);
		three(list);
	}
	else
		return  ;
}

void	three_to_five(bon *list, bon *listb)
{
	if  (list->tot == 4)
		three(list);
	else if  (list->tot == 6)
		five(list, listb);
	quit_well(list, 2);
}
