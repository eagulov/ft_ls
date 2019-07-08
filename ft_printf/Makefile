# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/16 13:26:18 by eagulov           #+#    #+#              #
#    Updated: 2019/06/11 15:31:39 by eagulov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = $(wildcard *.c)
LIBFT = libft/libft.a
OBJ = $(patsubst %.c,%.o,$(wildcard *.c))
LIBFT_OBJ = $(wildcard ./libft/*.o)
INCLUDE = ft_printf.h
ALL_OBJ = $(OBJ) $(LIBFT_OBJ)
DAMN = \033[0;92m

all : $(NAME)

$(NAME):$(LIBFT) $(OBJ)
			@ar rc $(NAME) $(ALL_OBJ)
			@ranlib $(NAME)
			@echo "$(DAMN)Daaaaamn, it's compiled"

$(LIBFT) :
			@make -C libft
			@echo "$(DAMN)Yo, libft was compiled"

%.o : %.c
			@gcc -c $< -o $@ -Wall -Wextra -Werror -g  -I $(INCLUDE)

clean :
			@rm -rf $(OBJ)
			@make clean -C libft
			@echo "$(DAMN)Wow, all obj is deleted"

fclean : clean
			@rm -rf $(NAME)
			@make fclean -C libft
			@echo "$(DAMN)No way, everything is cleaned"

re : fclean all

.PHONY : all clean fclean re
