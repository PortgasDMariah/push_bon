/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:51:42 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/22 20:19:07 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STRUCT_H
# define STRUCT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "struct.h"

typedef struct s_node
{
	int				data;
	int				lis;
	int				mouv;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_data
{
	t_node	*head;
	t_node	*before;
	t_node	*last;
	t_node	*node;
	t_node	*tmp;
	t_node	*push;
	t_node	*maxi;
	t_node	*test;
	t_node	*tmp2;
	t_node	*min;
	t_node	*chef;
	int		tot;
	int		fin;
	int		max;
	int		who;
	int		count;
	int		i;
	int		j;
	int		val;
}	t_data;

int		sorted_or_not(t_data *list);
int		ft_parsing(char *str, t_data*list);
int		ft_num(char c);
int		ft_lstsize(t_node *lst);
int		ft_listlen(t_data*list);
int		counti(t_data*list, t_data*listb);
int		max(int maxi, int nodi);
int		ft_putchar(char c);
int		ft_printf(char *bon, ...);
int		ft_strleni(char *str);
int		min(int a, int b);
t_node	*ft_lstnew(int content);
t_node	*ft_lstlast(t_node *lst);
t_node	*listmax(t_data*list);
t_node	*found_your_place(t_data*list, int c);
void	ft_lstadd_back(t_node **alst, t_node *new, t_data*list);
void	front(t_data*list, t_node *new);
void	ft_delete(t_data*list);
void	ft_swap(t_data*list);
void	ft_rrotate(t_data*list, int m);
void	ft_rotate(t_data*list, int m);
void	pb(t_data*list, t_data*listb, int m);
void	pa(t_data*list, t_data*listb);
void	rrr(t_data*list, t_data*listb);
void	doublerotate(t_data*list, t_data*listb);
void	free_list(t_node *node);
void	position(t_data*list);
void	foundit(t_data*list, t_data*listb);
void	organisation(t_data*list, t_data*listb);
void	firstone(t_data*list, t_data*listb, t_node *c);
void	lis(t_data*list, t_data*listb);
void	who(t_data*list);
void	sign(int *maxi, int *nodi);
void	freeall(t_data*list, int tmp);
void	deleteallnodes(t_node *start);
void	create_stack_a(t_data*list, char *av, int tmp);
void	firsti(t_data*list, t_node *c);
void	lets_sort(t_data*list, t_data*listb);
void	init(t_data*list, t_data*listb);
void	three_to_five(t_data*list, t_data*listb);
void	three(t_data*list);
void	five(t_data*list, t_data*listb);
void	listmin(t_data*list);
void	quit_well(t_data*list, int tmp);

#endif 
