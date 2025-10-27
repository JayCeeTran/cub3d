NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = -Llibft -lft
MINILIB = -Lminilibx -lmlx -lXext -lX11 -lm -lz
SRCS = main.c validate_args.c error_functions.c ft_mod_strnstr.c
INC = cub3d.h

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIB) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
re: fclean all

.PHONY: re clean fclean all
