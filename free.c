/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:00:38 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/21 22:16:50 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "struct.h"
#include <unistd.h>
#include <stdlib.h>

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

void	freeall(bon *list, int tmp)
{
	free_list(list->head);
	free(list->tmp2);
	if (tmp != 1)
		free(list->test);
}

void	quit_well(bon *list, int tmp)
{
	freeall(list, tmp);
	if (tmp == 1)
		ft_printf("Error \n");
	exit(0);
}
