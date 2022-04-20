/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:00:38 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/18 17:00:43 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "struct.h"
#include <unistd.h>
#include <stdlib.h>

void    begin(t_node *node)
{
    if(node)
    {
        while(node->prev != NULL)
            node = node->prev;
    deleteallnodes(node);
    }
}

void    freeall(bon *list, int tmp)
{
    begin(list->head);
    free(list->tmp2);
    if(tmp != 1)
        free(list->test);
}