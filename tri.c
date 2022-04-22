/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:23:49 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/22 11:17:29 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "struct.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

void	actiona_drotate(t_data*list, t_data*listb, int push, int maxi)
{
	int	doub;
	int	simple;

	doub = min(push, maxi);
	simple = max(push, maxi) - doub;
	while (doub != 0)
	{
		doublerotate(list, listb);
		doub--;
	}
	while (push > maxi && simple != 0)
	{
		ft_rotate(listb, 2);
		simple--;
	}
	while (push < maxi && simple != 0)
	{
		ft_rotate(list, 1);
		simple--;
	}
}

void	actiona_rrr(t_data*list, t_data*listb, int push, int maxi)
{
	int	doub;
	int	simple;

	doub = min(push, maxi);
	simple = max(push, maxi) - doub;
	while (doub != 0)
	{
		rrr(list, listb);
		doub--;
	}
	while (push < maxi && simple != 0)
	{
		ft_rrotate(listb, 2);
		simple--;
	}
	while (maxi < push && simple != 0)
	{
		ft_rrotate(list, 1);
		simple--;
	}
}

void	actiona_else(t_data*list, t_data*listb, int push, int maxi)
{
	while (push > 0)
	{
		ft_rotate(listb, 2);
		push--;
	}
	while (maxi > 0)
	{
		ft_rotate(list, 1);
		maxi--;
	}
	while (maxi < 0)
	{
		ft_rrotate(list, 1);
		maxi++;
	}
	while (push < 0)
	{
		ft_rrotate(listb, 2);
		push++;
	}
}

void	actiona(t_data*list, t_data*listb)
{
	int	push;
	int	maxi;

	found_your_place(list, listb->push->data);
	push = listb->push->mouv;
	if (list->maxi)
		maxi = list->maxi->mouv;
	if (listb->push->data > list->chef->data)
	{
		maxi = list->chef->mouv;
		maxi++;
	}
	if (push > 0 && maxi > 0)
		actiona_drotate(list, listb, push, maxi);
	else if (push < 0 && maxi < 0)
		actiona_rrr(list, listb, push, maxi);
	else
		actiona_else(list, listb, push, maxi);
	pa(list, listb);
}

void	organisation(t_data*list, t_data*listb)
{
	int	len;

	len = ft_listlen(listb);
	listmax(list);
	while (len != 0)
	{
		position(list);
		position(listb);
		foundit(list, listb);
		actiona(list, listb);
		len = len - 1;
	}	
}
