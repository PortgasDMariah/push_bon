/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 22:45:22 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/21 22:47:00 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "struct.h"

int	ft_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	max(int maxi, int nodi)
{
	sign(&maxi, &nodi);
	if (maxi > nodi)
		return (maxi);
	else if (nodi > maxi)
		return (nodi);
	else if (nodi == maxi)
		return (nodi);
	return (0);
}

int	min(int a, int b)
{
	sign(&a, &b);
	if (a > b)
		return (b);
	else if (a < b)
		return (a);
	else
		return (a);
}

int	ft_strleni(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (0);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
