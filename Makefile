# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/07 16:03:24 by eagulov           #+#    #+#              #
#    Updated: 2019/07/07 16:49:58 by eagulov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = $(wildcard *.c)

OBJ = $(patsubst %.c,%.o,$(wildcard *.c))

INC = -I includes

LIBFT =	ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		gcc -Wall -Wextra -Werror -g $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT)
		gcc -Wall -Wextra -Werror -g $(FLAGS) -c $(SRC)

$(LIBFT):
		make -C ./ft_printf/

clean:
		rm -f $(OBJ)
			make clean -C ./ft_printf/

fclean: clean
		rm -f $(NAME)
			make fclean -C ./ft_printf/

re: fclean all

.PHONY : all, re, clean, flcean
