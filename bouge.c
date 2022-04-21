/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bouge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:22:24 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/21 22:15:49 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

void	sign(int *maxi, int *nodi)
{
	if (*maxi < 0)
		*maxi = -(*maxi);
	if (*nodi < 0)
		*nodi = -(*nodi);
}

void	goodmouv(t_node *tmp, bon *list)
{
	t_node	*tmp2;

	tmp2 = list->head;
	while (tmp && (tmp->data != tmp2->data))
		tmp2 = tmp2->next;
	tmp = tmp2;
}

void	who(bon *list)
{
	goodmouv(list->maxi, list);
	goodmouv(list->min, list);
	goodmouv(list->chef, list);
}

int	counti(bon *list, bon *listb)
{
	int	maxi;
	int	nodi;

	who(list);
	nodi = listb->tmp->mouv;
	if (listb->tmp->data > list->chef->data)
	{
		maxi = list->chef->mouv;
		maxi++;
	}
	else
		maxi = list->tmp->mouv;
	if (maxi > 0 && nodi > 0)
		return (max(maxi, nodi) + 1);
	else if (maxi < 0 && nodi < 0)
		return (max(maxi, nodi) + 1);
	else if ((maxi > 0 && nodi < 0) || (maxi < 0 && nodi > 0))
	{
		sign(&maxi, &nodi);
		return ((maxi + nodi) + 1);
	}
	else if ((maxi == 0 || nodi == 0) || (maxi == 0 && nodi == 0))
		return (max(maxi, nodi) + 1);
	return (0);
}

void	foundit(bon *list, bon *listb)
{
	int	count;

	count = 0;
	listb->tmp = listb->head;
	list->tmp = found_your_place(list, listb->tmp->data);
	listb->count = counti(list, listb);
	listb->push = listb->tmp;
	while (listb->tmp)
	{
		list->tmp = found_your_place(list, listb->tmp->data);
		count = counti(list, listb);
		if (count <= listb->count)
		{
			listb->count = count;
			listb->push = listb->tmp;
		}
		listb->tmp = listb->tmp->next;
		if (!listb)
			break ;
	}
}
