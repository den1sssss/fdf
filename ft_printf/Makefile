# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 16:43:03 by dshirely          #+#    #+#              #
#    Updated: 2021/12/10 16:43:04 by dshirely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		=	ft_pointer.c ft_printf.c \
				ft_putchar.c ft_putnbr_fd.c \
				ft_putstr.c ft_xX.c \
				ft_putnbru.c
				
OBJS		= ${SRCS:.c=.o}

CC			= cc
AR			= ar rcs
FLAGS		= -Wall -Wextra -Werror
RM			= rm -f
HEADER		= ft_printf.h

all:	${NAME}

${NAME}:	${OBJS}
			${AR} ${NAME} $?

${OBJS} : ${HEADER} Makefile

.c.o:	
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

clean:	
		${RM} ${OBJS}
		
fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
