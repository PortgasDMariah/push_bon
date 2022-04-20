# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 18:21:22 by mdouiri           #+#    #+#              #
#    Updated: 2021/12/03 18:25:22 by mdouiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_num.c lis.c list.c tri.c free.c bouge.c bestmove.c action.c \
    
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
OBJS = $(SRCS:.c=.o)
NAME = libft.a

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

all : $(NAME)

bonus : $(OBJS) 
	ar rc $(NAME) $(OBJS) 

clean :
	$(RM)   $(OBJS)

fclean :   clean
	$(RM) $(NAME)

re : fclean all

.PHONY = re all clean fclean