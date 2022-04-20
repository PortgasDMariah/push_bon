/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:24:36 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/14 17:04:27 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "struct.h"
#include <stdlib.h>

void    firstone(bon *list, bon *listb, t_node *c)
{
        position(list);
        if( c->mouv < 0)
        {
                while(list->head->data != c->data)
		{
                        ft_rrotate(list);
			list->action++;
		}
        }
        else if(c->mouv > 0)
	{
                while(list->head->data != c->data)
		{
                        ft_rotate(list);
			list->action++;
		}
	}
    pb(list, listb);//c'est un pa
	list->action++;
}

void ft_continu(bon *list)
{
	while(1 != list->tot)
	{
		while(list->tmp->data != list->tmp2->data)
		{
			if(list->tmp->data < list->tmp2->data)
			{
				if(list->tmp2->lis <= (list->tmp->lis + 1))
					list->tmp2->lis = list->tmp->lis + 1;

				if((list->tmp->lis + 1) >= list->max)
				{
					list->max = list->tmp2->lis;
					list->who = list->tmp2->data;
				}
			}
			list->tmp = list->tmp->next;
			if(list->tmp->data == list->tmp2->data)
			{
				list->tmp = list->head;
				break;
			}
		}
		if(list->tmp2->data == list->last->data)
			break;
		else
		{
			list->tmp2 = list->tmp2->next;
			list->tot--;
		}
	}
}

void	ft_create_lis(bon *list, bon *listb)
{
	while(list->tmp2->prev != NULL)
	{
		if(list->tmp2->data != list->head->data)
		{
			if(((list->max - 1) != 1) && list->tmp2->lis == (list->max - 1) && list->tmp2->data > list->head->data)
				list->max = list->tmp2->lis;
			else 
				list->tmp2->lis = -1;
		}
		list->tmp2 = list->tmp2->prev;
		if(list->tmp2->data == list->head->data)
			break;
	}
	list->tmp = list->head;
	while(list->tmp2)
	{
		if(list->tmp2->lis == -1)
		{
			firstone(list, listb, list->tmp2);
			list->tmp2 = list->head;
		}
		else
			list->tmp2 = list->tmp2->next;
	}
}



void	lis_organisation(bon *list, bon *listb)
{
	while(list->tmp2->data != list->who)
	{
		list->tmp2 = list->tmp2->prev;
		if(list->tmp2->data == list->who )
			break;
	}
	list->tmp = list->tmp2;
    while(list->tmp2)
	{
		if(list->tmp2->data != list->who)
			list->tmp2->lis = -1;
		list->tmp2 = list->tmp2->next;
	}
	list->tmp2 = list->tmp;
	list->tmp2 = list->tmp2->prev;
	ft_create_lis(list, listb);
}



void	bienfait(bon *list, bon *listb)
{
	int i;
	int j;
	int max;
	int who;

	i = 1;
	list->tmp2 = NULL;
	list->tmp = list->head;
	list->tmp2 = list->head;
	list->tmp2 = list->tmp2->next;
	ft_continu(list);
	lis_organisation(list, listb);

}

