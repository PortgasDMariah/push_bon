#include <stdio.h>
#include "struct.h"
#include <stdlib.h>

void	found_lis(t_data *list)
{
	while (list->tmp2->data != list->min->data)
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
				list->tmp = list->min;
				break ;
			}
		}
		list->tmp2 = list->tmp2->next;
	}
}

void	firstone(t_data*list, t_data*listb, t_node *c)
{
    list->head->prev = NULL;
    list->last->next = NULL; 
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

void	ft_create_lis(t_data*list, t_data*listb)
{
	while (list->tmp2->data != list->min->data)
	{
		if (list->tmp2->data != list->min->data)
		{
			if (((list->max - 1) != 1) && list->tmp2->lis == (list->max - 1)
				&& list->tmp2->data > list->min->data)
				list->max = list->tmp2->lis;
			else
				list->tmp2->lis = -1;
		}
		list->tmp2 = list->tmp2->prev;
		if (list->tmp2->data == list->min->data)
			break ;
	}
    list->head->prev = NULL;
    list->last->next = NULL;
	list->tmp2 = list->head;
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
	while (list->tmp2->data != list->min->data)
	{
		if (list->tmp2->data != list->who)
			list->tmp2->lis = -1;
		list->tmp2 = list->tmp2->next;
	}
	list->tmp2 = list->tmp;
	list->tmp2 = list->tmp2->prev;
	ft_create_lis(list, listb);
}

void	listmino(t_data*list)
{
	t_node	*tmp2;

	tmp2 = list->head->next;
    list->head->prev = list->last;
    list->last->next = list->head;
	list->min = list->head;
	while (tmp2->data != list->head->data)
	{
		if (list->min->data > tmp2->data)
			list->min = tmp2;
		tmp2 = tmp2->next;
	}
}

void	lis(t_data*list, t_data*listb)
{
	list->tmp2 = NULL;
    listmino(list);
	list->tmp = list->min;
	list->tmp2 = list->min;
	list->tmp2 = list->tmp2->next;
	found_lis(list);
	lis_organisation(list, listb);
}