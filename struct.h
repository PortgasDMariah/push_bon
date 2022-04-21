/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:51:42 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/21 22:51:25 by mdouiri          ###   ########.fr       */
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
	int			data;
	int			lis;
	int			mouv;
	struct s_node	*prev;
	struct s_node	*next;
}               t_node;

typedef struct bon
{
	t_node *head;
	t_node *before;
	t_node *last;
	t_node *node;
	t_node *tmp;
	t_node *push;
	t_node *maxi;
	t_node *test;
	t_node *tmp2;
	t_node*	min;
	t_node 	*chef;
	int 	tot;
	int 	fin;
	int max;
	int who;
	int count;
	int	i;
	int j;
	int val;
}       bon;

int	ft_parsing(char *str, bon *list);
int	ft_num(char c);
int     ft_lstsize(t_node *lst);
int	ft_listlen(bon *list);
int	counti(bon *list, bon *listb);
int	max(int maxi, int nodi);
int	ft_putchar(char c);
int	ft_printf(char *bon, ...);
int	ft_strleni(char *str);
int	min(int a, int b);
t_node  *ft_lstnew(int content);
t_node  *ft_lstlast(t_node *lst);
t_node	*listmax(bon *list);
t_node	*found_your_place(bon *list, int c);
void    printnode(t_node *start);
void    ft_lstadd_back(t_node **alst, t_node *new, bon *list);
void	front(bon *list, t_node *new);
void	ft_delete(bon *list);
void    ft_swap(bon *list);
void     ft_rrotate(bon *list, int m);
void	ft_rotate(bon *list, int m);
void	pb(bon *list, bon *listb, int m);
void	pa(bon *list, bon *listb);
void	rrr(bon *list, bon *listb);
void	doublerotate(bon *list, bon *listb);
void	free_list(t_node *node);
void	position(bon *list);
void	foundit(bon *list, bon *listb);
void	organisation(bon *list, bon *listb);
void	firstone(bon *list, bon *listb, t_node *c);
void    lis(bon *list, bon *listb);
void	who(bon *list);
void	sign(int *maxi, int *nodi);
void    freeall(bon *list, int tmp);
void	deleteallnodes(t_node *start);
void	create_stack_a(bon *list, char *av, int tmp);
void    firsti(bon *list, t_node *c);
void	lets_sort(bon *list, bon *listb);
void	init(bon *list, bon *listb);
void	three_to_five(bon *list, bon *listb);
void	three(bon *list);
void	five(bon *list, bon *listb);
void	listmin(bon *list);
void	quit_well(bon *list, int tmp);

#endif 

