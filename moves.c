#include "so_long.h"

int	ft_move_right(char **line, t_init *data)
{
	char	safe;

	safe = line[data->y_player][data->x_player + 1];
	line[data->y_player][data->x_player] = '0';
	line[data->y_player][data->x_player + 1] = 'P';
	data->x_player = data->x_player + 1;
	if (safe == 'E')
		return (EXIT);
	if (safe == 'C')
		return (COLLECT);
	return (MOVE);
}

int	ft_move_left(char **line, t_init *data)
{
	char	safe;

	safe = line[data->y_player][data->x_player - 1];
	line[data->y_player][data->x_player] = '0';
	line[data->y_player][data->x_player - 1] = 'P';
	data->x_player = data->x_player - 1;
	if (safe == 'E')
		return (EXIT);
	if (safe == 'C')
		return (COLLECT);
	return (MOVE);
}

int	ft_move_up(char **line, t_init *data)
{
	char	safe;

	safe = line[data->y_player - 1][data->x_player];
	line[data->y_player][data->x_player] = '0';
	line[data->y_player - 1][data->x_player] = 'P';
	data->y_player = data->y_player - 1;
	if (safe == 'E')
		return (EXIT);
	if (safe == 'C')
		return (COLLECT);
	return (MOVE);
}

int	ft_move_down(char **line, t_init *data)
{
	char	safe;

	safe = line[data->y_player + 1][data->x_player];
	line[data->y_player][data->x_player] = '0';
	line[data->y_player + 1][data->x_player] = 'P';
	data->y_player = data->y_player + 1;
	if (safe == 'E')
		return (EXIT);
	if (safe == 'C')
		return (COLLECT);
	return (MOVE);
}

int	ft_make_move(char c, char **line, t_init *data)
{
	if (c == 'D' && line[data->y_player][data->x_player + 1] != '1')
		return (ft_move_right(line, data));
	if (c == 'A' && line[data->y_player][data->x_player - 1] != '1')
		return (ft_move_left(line, data));
	if (c == 'W' && line[data->y_player - 1][data->x_player] != '1')
		return (ft_move_up(line, data));
	if (c == 'S' && line[data->y_player + 1][data->x_player] != '1')
		return (ft_move_down(line, data));
	return (-1);
}
