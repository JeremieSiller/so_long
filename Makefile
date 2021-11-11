CC = gcc
CFLAGS = -Wall -Werror -Wextra -I ./inc -I ./mlx -I ./libft
LFLAGS = -L mlx/ -lmlx -framework OpenGL -framework AppKit -L libft/ -lft

SOURCES =	src/main.c \
			src/img_stuff/img_utils.c\
			src/utils.c\
			src/img_stuff/resize.c\
			src/window.c \
			src/win_utils.c \
			src/moves.c \
			src/helper.c

OBJECTS = $(SOURCES:.c=.o)

LIBFTDIR = ./libft/

LIBFT = $(LIBFTDIR)libft.a

MLXDIR = ./mlx/

MLX = $(MLXDIR)libmlx.a

NAME = so_long

COUNT := 0

COUNT_SRC := $(shell ls -R src | grep -E "\.c" | wc -l)

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
BLACK = "\033[38;2;52;52;52m"
UP = "\033[A"
CUT = "\033[K"

%.o : %.c
	@rm -f $@
	@tput civis
	@if [ $(COUNT) -eq 0 ] ; then\
		printf $(Y)"Compiling $(NAME):\n";\
		fi;
	@$(eval COUNT := $(shell ls -R src | grep -E "\.o" | wc -w))
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@$(CC) $(CFLAGS) -o $@ -c $<
	@if [ $(COUNT) -ne $$(($(COUNT_SRC) + 1)) ]; then\
		printf "\r"; \
		x=0 ; \
		while [ $$x -ne $(COUNT) ]; do \
			printf $(G)"▇"; \
			let "x+=1"; \
		done ; \
		y=0; \
		for x in $(SOURCES); do \
			let "y+=1"; \
		done ; \
		x=$(COUNT); \
		while [ $$x -ne $$y ] ; do \
			printf " "; \
			let "x+=1"; \
		done; \
		x=$(COUNT); \
		let "x*=100"; \
		printf $(X)"| "; \
		printf $$((x / y)); \
		printf "%%"; \
	else \
		printf $(G)"▇"; \
	fi

all:
	@bash -c "trap 'trap - SIGINT SIGTERM ERR; tput cnorm --normal; exit 1' SIGINT SIGTERM ERR; $(MAKE) $(NAME)"

$(NAME): $(LIBFT) $(MLX) $(OBJECTS)
	@$(CC) $(OBJECTS) $(CFLAGS) $(LFLAGS) -o $@
	@echo
	@tput cnorm

$(LIBFT):
	@make --directory=$(LIBFTDIR)

$(MLX):
	@make --directory=$(MLXDIR)

internal-clean:
	@$(eval OBJECTS := $(shell find $(PWD) | grep -E "\.o" ))
	@tput civis;\
		size=0; \
		for d in $(OBJECTS); do\
			let "size+=1";\
		done;\
		y=0;\
		for x in $(OBJECTS); do\
			let "y+=1"; \
			i=0; \
			printf "\r";\
			while [ $$i -ne $$y ]; do \
				printf $(G)"▇"; \
				let "i+=1"; \
			done; \
			while [ $$i -ne $$size ]; do \
				let "i+=1"; \
				printf " "; \
			done; \
			printf $(X)"| ";\
			printf $$((y * 100 / i)); \
			printf "%%";\
			sleep 0.1; \
			rm -f $$x; \
		done;\
		printf $(X)"\n";\
		tput cnorm --normal

clean:
	@make fclean --directory=./libft
	@make clean --directory=./mlx
	@bash -c "trap 'trap - SIGINT SIGTERM ERR; tput cnorm --normal; exit 1' SIGINT SIGTERM ERR; $(MAKE) internal-clean"

fclean:
	@make fclean --directory=./libft
	@make clean --directory=./mlx
	@printf $(Y)"Cleaning object-files and removing $(NAME):\n"
	@bash -c "trap 'trap - SIGINT SIGTERM ERR; tput cnorm --normal; exit 1' SIGINT SIGTERM ERR; $(MAKE) internal-clean"
	@rm -f $(NAME)


re: fclean $(NAME)