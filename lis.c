/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:24:36 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/22 11:19:48 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "struct.h"
#include <stdlib.h>

void	found_lis(t_data*list)
{
	while (list->tmp2->data != list->last->data)
	{
		while (list->tmp->data != list->tmp2->data)
		{
			if (list->tmp->data < list->tmp2->data)
			{
				if (list->tmp2->lis <= (list->tmp->lis + 1))
					list->tmp2->lis = list->tmp->lis + 1;
				if ((list->tmp->lis + 1) >= list->max)
				{
					list->max = list->tmp2->lis;
					list->who = list->tmp2->data;
				}
			}
			list->tmp = list->tmp->next;
			if (list->tmp->data == list->tmp2->data)
			{
				list->tmp = list->head;
				break ;
			}
		}
		list->tmp2 = list->tmp2->next;
	}
}

void	ft_create_lis(t_data*list, t_data*listb)
{
	while (list->tmp2->prev != NULL)
	{
		if (list->tmp2->data != list->head->data)
		{
			if (((list->max - 1) != 1) && list->tmp2->lis == (list->max - 1)
				&& list->tmp2->data > list->head->data)
				list->max = list->tmp2->lis;
			else
				list->tmp2->lis = -1;
		}
		list->tmp2 = list->tmp2->prev;
		if (list->tmp2->data == list->head->data)
			break ;
	}
	list->tmp = list->head;
	while (list->tmp2)
	{
		if (list->tmp2->lis == -1)
		{
			firstone(list, listb, list->tmp2);
			list->tmp2 = list->head;
		}
		else
			list->tmp2 = list->tmp2->next;
	}
}

void	lis_organisation(t_data*list, t_data*listb)
{
	while (list->tmp2->data != list->who)
	{
		list->tmp2 = list->tmp2->prev;
		if (list->tmp2->data == list->who)
			break ;
	}
	list->tmp = list->tmp2;
	while (list->tmp2)
	{
		if (list->tmp2->data != list->who)
			list->tmp2->lis = -1;
		list->tmp2 = list->tmp2->next;
	}
	list->tmp2 = list->tmp;
	list->tmp2 = list->tmp2->prev;
	ft_create_lis(list, listb);
}

void	lis(t_data*list, t_data*listb)
{
	list->tmp2 = NULL;
	list->tmp = list->head;
	list->tmp2 = list->head;
	list->tmp2 = list->tmp2->next;
	found_lis(list);
	lis_organisation(list, listb);
}
