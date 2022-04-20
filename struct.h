/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:51:42 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/09 17:42:05 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

typedef struct s_node
{
        int data;
		int lis;
		int mouv;
        struct s_node *prev;
        struct s_node *next;
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
		int action;
}       bon;

void ft_create();
void    ft_swap(bon *list);
void    printnode(t_node *start);

int ft_good(char *str);
int ft_num(char c);
t_node  *ft_lstnew(int content);
int     ft_lstsize(t_node *lst);
t_node  *ft_lstlast(t_node *lst);
void    ft_lstadd_back(t_node **alst, t_node *new, bon *list);
long int     ft_atoi(char *nptr);
void	ft_lstadd_front(t_node **alst, t_node *new, bon *list);
void	front(bon *list, t_node *new);
void     ft_rrotate(bon *list);
void	ft_rotate(bon *list);
void	pb(bon *list, bon *listb);
void	ft_delete(bon *list);
void	pa(bon *list, bon *listb);
void	ft_lis(bon *list, bon *listtmp, bon *listb);
int	ft_listlen(bon *list);
void	position(bon *list);
int	 count(bon *list, bon *listb, t_node *node);
t_node	*found_your_place(bon *list, int c);
void	ft_bestmove(bon *list, bon *listb);

void	foundit(bon *list, bon *listb);
int counti(bon *list, bon *listb);
t_node *listmax(bon *list);
void	action(bon *list, bon *listb);

void	rrr(bon *list, bon *listb);
void	doublerotate(bon *list, bon *listb);

void organisation(bon *list, bon *listb);
void	actionmax(bon *list, bon *listb);

void	firstone(bon *list, bon *listb, t_node *c);
void    bienfait(bon *list, bon *listb);

void reverse(bon *list);
int max(int maxi, int nodi);
void sign(int *maxi, int *nodi);

void    freeall(bon *list, int tmp);
void deleteallnodes(t_node *start);
void	begin(t_node *node);
#endif

