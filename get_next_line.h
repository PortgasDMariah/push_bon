/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 20:00:31 by mdouiri           #+#    #+#             */
/*   Updated: 2022/01/12 17:11:41 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 1
# endif

char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_strleno(char	*str);
char	*ft_continu(char *buffer, char *final, int numb, int fd);
char	*get_my_line(char *str);
char	*ft_strchr(char *s, int c);
char	*upgradebuffer(char *myline, char *buffertot);

#endif
