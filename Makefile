# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mirnavar <mirnavar@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 15:07:42 by mirnavar          #+#    #+#              #
#    Updated: 2022/11/23 17:54:49 by mirnavar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 

OBJ = $(SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

HDR = libftprintf.h libft.h

all:		$(NAME)

$(NAME):	$(OBJ) $(HDR)
			ar -rcs	$(NAME) $(OBJ)

%.o:		%.c $(HDR)
			$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean:
			rm -f $(OBJ)

fclean:
			$(MAKE) clean
			rm -f $(NAME)

re:
			$(MAKE) fclean
			$(MAKE) all

.PHONY: all clean fclean re
