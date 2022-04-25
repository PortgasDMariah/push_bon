/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainbon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:06:07 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/25 20:23:35 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "struct.h"

int	main(int ac, char **av)
{
	t_data	stack_b;
	t_data	stack_a;

	init(&stack_a, &stack_b);
	stack_a.tot = ac;
	if (ac <= 2)
		one_arg(&stack_a, av[1]);
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
