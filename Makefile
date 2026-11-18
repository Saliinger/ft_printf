NAME      = libftprintf.a
CC        = cc
CFLAGS    = -Wall -Wextra -Werror

LIBFT_DIR = lib/libft
LIBFT     = $(LIBFT_DIR)/libft.a

SRCS      =		srcs/ft_countdigit.c \
			 	srcs/ft_decimal.c \
			 	srcs/ft_hex.c \
			 	srcs/ft_pointeurhex.c \
            	srcs/ft_printchar.c \
				srcs/ft_printf.c \
				srcs/ft_putnbr_u.c \
				srcs/ft_putstr.c \
            	srcs/ft_selector.c \
			 	srcs/ft_string.c \
			  	srcs/ft_uint.c 
OBJS      = $(SRCS:.c=.o)

INC       = -Iincludes -I$(LIBFT_DIR)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: $(NAME) all clean fclean re