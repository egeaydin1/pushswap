NAME = main_project
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = lib/libft
PRINTF_DIR = lib/ft_printf

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRC_DIR = src
INCLUDES = -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(SRC_DIR)

SRC = push_swap.c parser.c operations.c utils.c sort.c
OBJ = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))

vpath %.c $(SRC_DIR)

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) bonus

$(PRINTF):
	@make -C $(PRINTF_DIR)

$(SRC_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
	rm -f $(OBJ)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
