/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestmove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:21:50 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/22 11:30:10 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "struct.h"
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_listlen(t_data*list)
{
	t_node	*tmp2;	
	int		i;

	i = 0;
	tmp2 = list->head;
	while (tmp2)
	{
		tmp2 = tmp2->next;
		i++;
	}
	return (i);
}

void	alone_in_my_stack(t_data*list)
{
	list->tmp2->mouv = 0;
	list->maxi = list->tmp2;
	list->fin = 0;
}

void	position(t_data*list)
{
	int	limite;
	int	i;
	int	j;

	i = ft_listlen(list);
	limite = i / 2;
	list->tmp2 = list->head;
	j = -1;
	if (i == 1)
	{
		alone_in_my_stack(list);
		return ;
	}
	while (++j < (i - limite))
	{
		list->tmp2->mouv = j;
		list->tmp2 = list->tmp2->next;
	}
	j = -(i / 2);
	while (limite-- >= 0 && list->tmp2)
	{
		list->tmp2->mouv = j++;
		list->fin = list->tmp2->mouv;
		list->tmp2 = list->tmp2->next;
	}
}

t_node	*listmax(t_data*list)
{
	t_node	*tmp2;

	tmp2 = list->head;
	list->chef = list->head;
	while (tmp2)
	{
		if (tmp2->data > list->chef->data)
			list->chef = tmp2;
		tmp2 = tmp2->next;
	}
	return (list->chef);
}

t_node	*found_your_place(t_data*list, int c)
{
	t_node	*tmp2;
	int		i;

	i = ft_listlen(list);
	listmax(list);
	if (list->chef->data < c)
		return (NULL);
	list->maxi = list->chef;
	tmp2 = list->head;
	while (i-- != 0)
	{
		if ((tmp2->data < list->maxi->data) && (tmp2->data > c))
			list->maxi = tmp2;
		tmp2 = tmp2->next;
	}
	return (list->maxi);
}
