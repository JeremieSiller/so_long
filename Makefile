CC = gcc
CFLAGS = -Wall -Werror -Wextra -L mlx/ -lmlx -framework OpenGL -framework AppKit -L libft/ -lft

SOURCES =	main.c \
			img_stuff/img_utils.c\
			utils.c\
			img_stuff/resize.c\
			window.c \
			win_utils.c \
			moves.c

NAME = so_long

$(NAME):
	make --directory=./libft
	make --directory=./mlx
	$(CC) $(SOURCES) $(CFLAGS) -o $(NAME)

clean:
	make clean --directory=./libft
	make clean --directory=./mlx

fclean:
	rm -f $(NAME)
	make fclean --directory=./libft
	make clean --directory=./mlx

re: fclean $(NAME)
	make re --directory=./mlx
	make re --directory=./libft