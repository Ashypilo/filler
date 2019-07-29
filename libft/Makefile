#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/28 14:51:07 by ashypilo          #+#    #+#              #
#    Updated: 2018/11/20 16:32:10 by ashypilo         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
INCLUDES = ./
SRCS = ft_isalpha.c ft_lstmap.c ft_memset.c ft_strcat.c ft_striteri.c\
ft_strnequ.c ft_toupper.c ft_isascii.c ft_lstnew.c ft_putchar.c ft_strchr.c\
ft_strjoin.c ft_strnew.c ft_isdigit.c ft_memalloc.c	ft_putchar_fd.c	ft_strclr.c\
ft_strlcat.c ft_strnstr.c ft_isprint.c ft_memccpy.c	ft_putendl.c ft_strcmp.c\
ft_strlen.c	ft_strrchr.c ft_itoa.c ft_memchr.c	ft_putendl_fd.c	ft_strcpy.c\
ft_strmap.c	ft_strsplit.c ft_lstadd.c ft_memcmp.c ft_putnbr.c ft_strdel.c\
ft_strmapi.c ft_strstr.c ft_atoi.c ft_lstdel.c ft_memcpy.c ft_putnbr_fd.c\
ft_strdup.c ft_strncat.c ft_strsub.c ft_bzero.c	ft_lstdelone.c ft_memdel.c\
ft_putstr.c	ft_strequ.c	ft_strncmp.c ft_strtrim.c ft_isalnum.c ft_lstiter.c\
ft_memmove.c ft_putstr_fd.c	ft_striter.c ft_strncpy.c ft_tolower.c\
ft_printf.c ft_type.c ft_type_d_i_c_s_f.c ft_float_conversion.c ft_format.c\
ft_output.c ft_string_float.c ft_flagg_zero.c ft_itoa_base.c
BINAR = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRCS) -I $(INCLUDES) 
	@ar rc $(NAME) $(BINAR)

clean:
	@rm -f $(BINAR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean clean
