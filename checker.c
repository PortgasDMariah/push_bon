/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:46:12 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/25 21:05:36 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "struct.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <fcntl.h>

void	ss(t_data *list, t_data *listb, int tmp)
{
	if (tmp == 1)
		ft_printf("ss\n");
	if (list->head && listb->head)
	{
		ft_swap(list, 0);
		ft_swap(listb, 0);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	apply_move(char *str, t_data *list, t_data *listb)
{
	if (ft_strcmp(str, "ra\n") == 0)
		ft_rotate(list, 0);
	else if (ft_strcmp(str, "rb\n") == 0)
		ft_rotate(listb, 0);
	else if (ft_strcmp(str, "rra\n") == 0)
		ft_rrotate(list, 0);
	else if (ft_strcmp(str, "rrb\n") == 0)
		ft_rrotate(listb, 0);
	else if (ft_strcmp(str, "sa\n") == 0)
		ft_swap(list, 0);
	else if (ft_strcmp(str, "sb\n") == 0)
		ft_swap(listb, 0);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(list, listb, 0);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(list, listb, 0);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(list, listb, 0);
	else if (ft_strcmp(str, "rr\n") == 0)
		doublerotate(list, listb, 0);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(list, listb, 0);
	else
		quit_well(list, 1);
}

void	org(char **av, int ac, t_data *list)
{
	if (ac <= 2)
		one_arg(list, av[1]);
	while (av[list->i] && ((ft_parsing(av[list->i], list) == 0)
			|| ft_parsing((av[list->i]), list)))
	{
		list->val = ft_parsing(av[list->i], list);
		list->j = (list->i) + 1;
		while (av[list->j])
		{
			if (list->val == ft_parsing((av[(list->j)++]), list))
			{
				quit_well(list, 1);
			}
		}
		create_stack_a(list, av[list->i], list->i);
		(list->i)++;
	}
}

int	main(int ac, char **av)
{
	t_data	stack_a;
	t_data	stack_b;
	char	*line;

	line = "bonjour";
	init(&stack_a, &stack_b);
	stack_a.tot = ac;
	org(av, ac, &stack_a);
	while (line != NULL)
	{
		line = get_next_line(0);
		if (line == NULL || (ft_num(line[0]) == 1))
			break ;
		apply_move(line, &stack_a, &stack_b);
		free(line);
	}
	if (sorted_or_not(&stack_a) == 0)
		ft_printf("KO\n");
	else
	{
		if (!stack_b.head)
			ft_printf("OK\n");
	}
	quit_well(&stack_a, 3);
	return (0);
}
