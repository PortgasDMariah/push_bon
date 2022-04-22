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

SRCS = action.c action2.c utils.c bestmove.c bouge.c ft_printf.c free.c \
			init.c 3_5numbers.c lis.c tri.c main.c list.c 
OBJS 		= ${SRCS:.c=.o}

CC 			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= push_swap
#INCL		= ./struct.h
all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
					${CC} $(CFLAGS) -o $(NAME) $(OBJS)

#$(OBJS):    $(INCL)
clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re: 		fclean all