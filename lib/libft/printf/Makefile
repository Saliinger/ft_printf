# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 11:38:23 by anoukan           #+#    #+#              #
#    Updated: 2024/09/14 14:19:59 by anoukan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=addresrs
NAME = libprintf.a

INCDIR = includes

# Printf
PTF_SRCS =		ft_countdigit.c \
				ft_decimal.c\
				ft_hex.c \
				ft_pointeurhex.c \
				ft_printchar.c\
				ft_printf.c \
				ft_putnbr_u.c \
				ft_putstr.c\
				ft_selector.c\
				ft_string.c\
				ft_uint.c \
				utils.c

PTF_OBJ = $(PTF_SRCS:%.c=%.o)

# Makefile Command
OBJ = $(PTF_OBJ)
INC = -I$(INCDIR)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(PTF_OBJ): %.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

