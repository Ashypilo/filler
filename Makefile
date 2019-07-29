#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/19 16:06:40 by ashypilo          #+#    #+#              #
#    Updated: 2019/04/19 16:06:41 by ashypilo         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ashypilo.filler
LIBFT = ./libft/
LIB = $(LIBFT)libtf.a
SRCS = filler.c ft_calculation.c ft_search_coordinate.c get_next_line.c\
ft_free.c
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIB)
	@gcc $(FLAGS) $(SRCS) -o $(NAME) libft/libft.a

$(LIB): 
	@make -C $(LIBFT)

clean:
	@make -C $(LIBFT) clean
	@rm -f $(NAME)

fclean: clean
	@make -C $(LIBFT) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean clean