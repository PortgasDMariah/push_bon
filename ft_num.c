/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:23:11 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/09 18:34:38 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "struct.h"
#include <stdio.h>

int ft_num(char c)
{
	if(c >='0' && c <= '9')
		return(1);
	return(0);
}

void	quit_well(bon *list, int tmp)
{
	freeall(list, tmp);
	exit(0);
}

int	ft_ato(char *str, bon *list)
{
	int	i;
	long int	a;
	long int	b;

	i = -1;
	a = 1;
	b = 0;
	if(!str)
		quit_well(list, 1);
	while (str[++i])
	{
		if(!((ft_num(str[i]) == 1) || (str[i] == '-') || (str[i] == ' ')))
			quit_well(list, 1);
		else if(str[i] == '-' && (!(ft_num(str[i + 1]) == 1) || (ft_num(str[i - 1]) == 1)))
			quit_well(list, 1);
		else if(str[i] == '-')
			a = -a;
		if(ft_num(str[i]) == 1)
			b = b * 10 + str[i] - 48;
	}
	if(((a * b) > (2147483647)) || ((a * b) < (-2147483648)) )
		quit_well(list, 1);
	return (a * b);
}

void    printnode(t_node *start)
{
        t_node *temp;

        temp = start;
        while(temp)
        {
                printf("%ld \n", (long int)temp->data);
                temp = temp->next;
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

void	three(bon *list)
{
	list->maxi = list->chef;
	position(list);
	list->chef = list->maxi;
	if(!(list->min->mouv == 0 && list->chef->mouv == list->fin))
	{
		if((list->min->mouv == list->fin && list->chef->mouv == 0) || (list->chef->mouv != 0 && list->min->mouv == 1))
	       		ft_swap(list);
		else if(list->chef->mouv == 0 && list->min->mouv == 1)
			ft_rotate(list);
		else if((list->min->mouv == 0 && list->chef->mouv == 1) || list->min->mouv == list->fin)
			ft_rrotate(list);
		list->action++;
		three(list);
	}
	else
		return;
}

void	three_to_five(bon *list)
{
	three(list);
	quit_well(list, 1);
}


void    firsti(bon *list, t_node *c)
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
}

void init(bon *list, bon *listb)
{
	list->fin = 0;
	list->tot = 0;
	listb->count = 0;
	list->action = 0;
	list->min = NULL;
	list->chef = NULL;
	listb->push = NULL;
	listb->tmp = NULL;
	listb->tmp2 = NULL;
	list->head = NULL;
	list->before = NULL;
	list->last = NULL;
	list->node = NULL;
	list->tmp = NULL;
	list->maxi = NULL;
	listb->head = NULL;
	listb->maxi = NULL;
	listb->min = NULL;
	listb->chef = NULL;
	list->tmp2 = malloc(sizeof(t_node));
	list->test = NULL;
	list->test = list->tmp2;
}

void	create_stack_a(bon *list, char *av, int tmp)
{
	int val;

	val = 0;
	if(tmp == 1)
	{
		list->head = ft_lstnew(ft_ato(av, list));
		list->head->prev = NULL;
		list->min = list->head;
	}
	else
	{
		val = ft_ato(av, list);
		ft_lstadd_back(&list->head, ft_lstnew(val), list);
		if(val < list->min->data)
			list->min = list->last;	
	}
}

void	lets_sort(bon *list, bon *listb)
{
	listmax(list);
	if(list->tot == 4)
		three_to_five(list);
	firsti(list, list->min);
	bienfait(list, listb);
	organisation(list, listb);
	firsti(list, list->min);
	printnode(list->head);
	 printf("action = %d \n", list->action);
	 quit_well(list, 2);

}

#include <stdio.h>

int main(int ac, char **av)
{
	bon list = {0};
	bon listb = {0};
	int i;
	int val;
	int j;

	init(&list, &listb);
	if(ac <= 2)
		return(0);
	list.tot = ac;
	i = 1;
	while(av[i] && ((ft_ato(av[i], &list) == 0) || ft_ato((av[i]), &list)))
	{
		val = ft_ato(av[i], &list);
		j = i + 1;
		while(av[j])
		{
			if(val == ft_ato((av[j++]), &list))
				goto next;
		}
		create_stack_a(&list, av[i], i);
		i++;
	}
	next : if(i != ac )
		quit_well(&list, 1);
	lets_sort(&list, &listb);
}

