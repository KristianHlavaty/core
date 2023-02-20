# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khlavaty <khlavaty@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 18:10:45 by khlavaty          #+#    #+#              #
#    Updated: 2023/02/20 18:33:31 by khlavaty         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_utils.c
INC = ft_printf.h
OBJ = $(SRC:.c=.o)
RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INC}

all: $(NAME)

${NAME}: ${OBJ}
	ar rcs $(NAME) $(OBJS)

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all
