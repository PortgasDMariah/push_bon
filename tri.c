/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:23:49 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/09 19:36:52 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int	min(int a, int b)
{
	sign(&a, &b);
	if( a > b)
		return(b);
	else if(a < b)
		return(a);
	else
		return(a);
}

void	actiona_drotate(bon *list, bon *listb, int doub, int simple, int push, int maxi)
{
	doub = min(push, maxi);
	simple = max(push, maxi) - doub;
		while(doub != 0)
		{
			doublerotate(list, listb); list->action++;
			doub--;
		}
		while(push > maxi && simple != 0)
		{
				ft_rotate(listb);
				list->action++;
				simple--;
		}
		while(push < maxi && simple != 0)
		{
				ft_rotate(list);
				list->action++;
				simple--;
		}

}

void	actiona_rrr(bon *list, bon *listb, int doub, int simple, int push, int maxi)
{
	doub = min(push, maxi);
	simple = max(push, maxi) - doub;
		while(doub != 0)
		{
			rrr(list, listb); list->action++;
			doub--;
		}
		while( push < maxi && simple != 0)
		{
				ft_rrotate(listb);  
				list->action++;
				simple--;
		}
		while( maxi < push && simple != 0)
		{
				ft_rrotate(list); 
				list->action++;
				simple--;
		}
}


void	actiona_else(bon *list, bon *listb, int push, int maxi)
{
	while (push > 0)
	{
		ft_rotate(listb); 
		(list->action)++; 
		push--;
	}
	while(maxi > 0 )
	{
		ft_rotate(list);
		(list->action)++;
		maxi--;
	}
	while(maxi < 0 )
	{
		ft_rrotate(list);
		(list->action)++;
		maxi++;
	}
	while(push < 0)
	{
		ft_rrotate(listb); 
		(list->action)++;
		push++;
	}
}




void	actiona(bon *list, bon *listb)
{
	found_your_place(list, listb->push->data); 
	int doub;
	int simple;
	int push;
	int maxi;

	doub = 0;
	simple = 0;
	push = listb->push->mouv;
	if(list->maxi)
		maxi = list->maxi->mouv;
	if(listb->push->data > list->chef->data)
	{
		maxi = list->chef->mouv;
		maxi++; 
	}
	if(push > 0 && maxi > 0)
		actiona_drotate(list, listb, doub, simple, push, maxi);
	else if( push < 0 && maxi < 0)
		actiona_rrr(list, listb, doub, simple, push, maxi);
	else
		actiona_else(list, listb, push, maxi);
	pb(listb, list); list->action++;
}

void	organisation(bon *list, bon *listb)
{
	int len;

	len = ft_listlen(listb);
	listmax(list);
	while(len != 0)
	{
			position(list);
			position(listb);
			foundit(list, listb);
			actiona(list, listb);
		len = len - 1;
	}	
}

