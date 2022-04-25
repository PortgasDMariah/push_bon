/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:00:38 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/25 20:25:02 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "struct.h"
#include <unistd.h>
#include <stdlib.h>

void	listmin_circular(t_data*list)
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

void	deleteallnodes(t_node *start)
{
	t_node	*temp;

	while (start != NULL)
	{
		temp = start;
		start = start -> next;
		free(temp);
	}
}

void	free_list(t_node *node)
{
	if (node)
	{
		while (node->prev != NULL)
			node = node->prev;
		deleteallnodes(node);
	}
}

void	freeall(t_data*list, int tmp)
{
	free_list(list->head);
	free(list->tmp2);
	if (tmp != 1)
		free(list->test);
}

void	quit_well(t_data*list, int tmp)
{
	if (tmp == 0)
	{
		free(list->tmp2);
		exit(0);
	}
	else if (tmp == 1)
		write(2, "Error\n", 7);
	else if (tmp == 3)
			tmp = 1;
	freeall(list, tmp);
	exit(0);
}
