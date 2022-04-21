/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:23:11 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/21 22:21:12 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "struct.h"
#include <stdio.h>

int	ft_parsing(char *str, bon *list)
{
	int			i;
	long int	a;
	long int	b;

	i = -1;
	a = 1;
	b = 0;
	if (!str || !str[0])
		quit_well(list, 1);
	while (str[++i])
	{
		if (!((ft_num(str[i]) == 1) || (str[i] == '-') || (str[i] == ' ')))
			quit_well(list, 1);
		else if (str[i] == '-' && (!(ft_num(str[i + 1]) == 1)
				|| (ft_num(str[i - 1]) == 1)))
			quit_well(list, 1);
		else if (str[i] == '-')
			a = -a;
		if (ft_num(str[i]) == 1)
			b = b * 10 + str[i] - 48;
	}
	if (((a * b) > (2147483647)) || ((a * b) < (-2147483648)))
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


int	main(int ac, char **av)
{
	bon	stack_b = {0};
	bon	stack_a = {0};

	init(&stack_a, &stack_b);
	if (ac <= 2)
		quit_well(&stack_a, 1);
	stack_a.tot = ac;
	while (av[stack_a.i] && ((ft_parsing(av[stack_a.i], &stack_a) == 0)
			|| ft_parsing((av[stack_a.i]), &stack_a)))
	{
		stack_a.val = ft_parsing(av[stack_a.i], &stack_a);
		stack_a.j = (stack_a.i) + 1;
		while (av[stack_a.j])
		{
			if (stack_a.val == ft_parsing((av[(stack_a.j)++]), &stack_a))
				quit_well(&stack_a, 1);
		}
		create_stack_a(&stack_a, av[stack_a.i], stack_a.i);
		(stack_a.i)++;
	}
	lets_sort(&stack_a, &stack_b);
}
