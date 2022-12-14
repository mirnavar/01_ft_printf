# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mirnavar <mirnavar@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 13:43:10 by mirnavar          #+#    #+#              #
#    Updated: 2022/12/14 12:18:20 by mirnavar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRC_DIR		= srcs
OBJ_DIR		= obj

SRC 		= ft_printf.c	ft_putchar.c	ft_putstr.c	ft_itoa.c	ft_unsitoa.c \
				ft_hexa.c	ft_void.c
INC			= -I ./
OBJ			= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o)) #probar con %.c=%.o tendria que funcionar 
DEP			= $(addsuffix .d,$(basename$(OBJ))) #basename extrae sin sufijo
LIB			= srcs/ft_printf.h

CC			= gcc
CFLAGS		= -Werror -Wextra -Wall -MMD $(INC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIB)
			mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

-include $(DEP) 
$(NAME):	$(OBJ) $(LIB)
			ar -rcs $(NAME) $(OBJ)

clean:
			rm -f $(OBJ)
			#rm -f $(DEP)
			rm -rf $(OBJ_DIR)

fclean:
			$(MAKE) clean
			rm -f $(NAME)

re:
			$(MAKE) fclean
			$(MAKE) all

.PHONY: all clean fclean re
