/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 20:59:22 by mdouiri           #+#    #+#             */
/*   Updated: 2022/01/20 11:20:43 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include <stddef.h>

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (&s[i]);
}

char	*get_my_line(char *str)
{
	char	*final;
	int		i;
	int		j;

	i = 0;
	if (!str)
		return (NULL);
	if (ft_strleno(str) == 0)
	{
		free(str);
		return (NULL);
	}
	while (str[i] && str[i] != '\n')
		i++;
	final = malloc((i + 2) * sizeof(char));
	if (!final)
		return (NULL);
	*final = '\0';
	j = -1;
	while (++j <= i && str[j])
		final[j] = str[j];
	final[j] = '\0';
	return (final);
}

char	*upgradebuffer(char *myline, char *buffertot)
{
	char	*newbuffer;
	char	*start_buffer;
	int		j;

	j = -1;
	if (!myline || !buffertot)
		return (NULL);
	newbuffer = malloc((ft_strleno(myline) + 2) * sizeof(char));
	if (!newbuffer)
		return (NULL);
	start_buffer = buffertot;
	if (ft_strleno(buffertot) == 0)
	{
		free(buffertot);
		free(newbuffer);
		return (NULL);
	}
	while (++j <= ft_strleno(buffertot) && myline[j])
		newbuffer[j] = myline[j];
	if (start_buffer)
		free(start_buffer);
	newbuffer[j] = '\0';
	return (newbuffer);
}

char	*ft_continu(char *buffer, char *final, int numb, int fd)
{
	static char	*line = NULL;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!(ft_strchr(line, 10)) && numb != 0)
	{
		numb = read(fd, buffer, BUFFER_SIZE);
		buffer[numb] = 0;
		if (numb == -1 || numb == 0)
			break ;
		line = ft_strjoin(line, buffer);
	}
	if (buffer)
		free(buffer);
	final = get_my_line(line);
	if (final)
		line = upgradebuffer(line + ft_strleno(final), line);
	return (final);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*final;
	int		numb;

	buffer = NULL;
	if (read(fd, "", 0) != -1)
	{
		final = NULL;
		numb = 1;
		final = ft_continu(buffer, final, numb, fd);
		return (final);
	}
	return (buffer);
}
