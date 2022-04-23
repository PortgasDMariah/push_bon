/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:10:26 by mdouiri           #+#    #+#             */
/*   Updated: 2022/01/11 21:12:57 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"
#include <stdio.h>

int	ft_strleno(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*start_buffer;
	char	*res;
	int		v;

	start_buffer = s1;
	res = malloc((ft_strleno(s1) + ft_strleno(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	v = 0;
	while (s1 && *s1)
		res[v++] = *s1++;
	while (s2 && *s2)
		res[v++] = *s2++;
	res[v] = '\0';
	if (start_buffer)
		free(start_buffer);
	return (res);
}
