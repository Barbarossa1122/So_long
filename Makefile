NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = ./mlx
MLX = $(MLX_DIR)/libmlx.a
MLXFLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

LIBFT = ./libft/libft.a

SRCS = src/main.c \
	   src/errors.c \
	   src/map_read.c \
	   src/map_parse.c \
	   src/map_parse_2.c \
	   src/map_check.c \
	   src/map_player.c \
	   src/mlx_setup.c \
	   src/textures.c \
	   src/render.c \
	   src/hooks.c \
	   src/moves.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft --no-print-directory
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)
	@echo "so_long compiled successfully!"

%.o: %.c
	$(CC) $(CFLAGS) -I includes -I libft -I mlx -c $< -o $@

clean:
	rm -f $(OBJS)
	@make clean -C libft --no-print-directory
	@echo "Objects removed."

fclean: clean
	rm -f $(NAME)
	@make fclean -C libft --no-print-directory
	@echo "Full clean completed."

re: fclean all

.PHONY: all clean fclean re bonus
