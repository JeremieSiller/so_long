/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:34:15 by jsiller           #+#    #+#             */
/*   Updated: 2021/11/11 20:29:43 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <libft.h>
# include <stdlib.h>
# include <fcntl.h>

# define PLAYER_PATH "./xpm/player.xpm"
# define BACKGROUND_PATH "./xpm/background.xpm"
# define EXIT_PATH "./xpm/exit.xpm"
# define WALL_PATH "./xpm/wall.xpm"
# define COLLECT_PATH "./xpm/collect.xpm"
# define STANDARD 64
# define EXIT 2
# define MOVE 1
# define COLLECT 3

# define W 0
# define A 1
# define S 2
# define D 3

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_H 4
# define KEY_G 5
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_Y 16
# define KEY_T 17
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define KEY_FOUR 21
# define KEY_SIX 22
# define KEY_FIVE 23
# define KEY_NINE 25
# define KEY_SEVEN 26
# define KEY_EIGHT 28
# define KEY_ZERO 29
# define KEY_BRACE_R 30
# define KEY_O 31
# define KEY_U 32
# define KEY_BRACE_L 33
# define KEY_I 34
# define KEY_P 35
# define KEY_L 37
# define KEY_J 38
# define KEY_K 40
# define KEY_SEMI 41
# define KEY_N 45
# define KEY_M 46
# define KEY_TAB 48
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_ESC 0x35

# define MAP "01CEP"

typedef struct s_img {
	void	*img;
	int		width;
	int		height;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_init {
	char	**line;
	int		fd;
	int		x_player;
	int		y_player;
	void	*mlx;
	int		field;
	t_img	player;
	t_img	wall;
	t_img	background;
	t_img	cocllect;
	t_img	exit;
	int		moves;
	int		ret;
	void	*win;
}				t_init;

int		ft_height(char **line);
int		ft_check_sorrounding(char **line);
void	ft_find_player(char **line, t_init *data);
int		ft_find_collect(char **line);
int		window(t_init *data);
void	ft_print_game(char **line);
int		ft_make_move(char c, char **line, t_init *data);
void	put_images_b(t_init *data, int x, int y);
void	put_images(t_init *data);
int		ft_put_error(char *str);
void	ft_free_stuff(t_init *data);
int		mouse(t_init *data);
void	*ft_realloc(void *ptr, size_t size, size_t old_size);
int		ft_not_strchr(char *str, char c);
int		ft_is_str_in_str(char *line, char *map);
void	free_line(char **line);
#endif