# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 17:10:26 by anoukan           #+#    #+#              #
#    Updated: 2024/06/15 18:30:14 by anoukan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address
NAME = libgnl.a

INCDIR = includes

SRC =		get_next_line.c\
			get_next_line_utils.c

BONUS =		get_next_line_bonus.c\
			get_next_line_utils_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

INC = -I$(INCDIR)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

bonus: $(BONUS) $(OBJ_BONUS)
	ar rc $(NAME) $(OBJ_BONUS)


$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all