NAME      = libftprintf.a
CC        = cc
CFLAGS    = -Wall -Wextra -Werror -g3 #-fsanitize=address

LIBFT_DIR = lib/libft
LIBFT     = $(LIBFT_DIR)/libft.a

SRC_DIR   = srcs
SRCS      = ft_countdigit.c ft_decimal.c ft_hex.c ft_pointeurhex.c \
            ft_printchar.c ft_printf.c ft_putnbr_u.c ft_putstr.c \
            ft_selector.c ft_string.c ft_uint.c
OBJS      = $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))

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

.PHONY: all clean fclean re