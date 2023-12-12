# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cde-la-c <cde-la-c@student.42adel.org.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 18:54:34 by cde-la-c          #+#    #+#              #
#    Updated: 2023/11/28 18:54:41 by cde-la-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

SRCS =  $(wildcard srcs/*.c utils/*.c)

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean: 
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re