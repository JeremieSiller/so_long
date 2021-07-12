#include "so_long.h"
#include "img_stuff/img.h"

int	ft_memchr_2(char **line, int c)
{
	int	x;
	int	count;
	int	y;

	x = ft_strlen(line[0]);
	count = 0;
	while (x--)
	{
		y = ft_height(line);
		while (y--)
		{
			if (line[y][x] == (char)c)
				count++;
		}
	}
	return (count);
}

int	ft_check_input(char **line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if ((line[i] && line[i + 1] && ft_strlen(line[i]) != ft_strlen
				(line[i + 1])) || !ft_is_str_in_str(line[i], MAP))
		{
			ft_putstr_fd("Error\nnot a valid map\n", 2);
			return (-1);
		}
		i++;
	}
	if (!ft_memchr_2(line, '1')
		|| !ft_memchr_2(line, 'C')
		|| !ft_memchr_2(line, 'E')
		|| (ft_memchr_2(line, 'P') != 1))
		i = -1;
	if (i == -1 || ft_check_sorrounding(line) == -1)
	{
		ft_putstr_fd("Error\nnot a valid map\n", 2);
		return (-1);
	}
	return (0);
}

int	ft_create_array(t_init *data)
{
	int	i;
	int	ret;

	data->line = malloc(2 * sizeof(char *));
	if (!data->line)
		return (-2);
	i = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(data->fd, &(data->line[i]));
		if (ret < 0)
		{
			free(data->line);
			return (-3);
		}
		if (ret != 0)
			data->line = ft_realloc(data->line, sizeof(char *)
					* (i + 3), sizeof(char *) * (i + 1));
		if (!data->line)
			return (-2);
		i++;
	}
	data->line[i] = 0;
	return (ft_check_input(data->line));
}

int	ft_handle_errors(int argc, char **argv)
{
	char	*str;

	if (argc != 2)
		ft_putstr_fd("Error\nnot the correct amount of arguements\n", 2);
	if (argc != 2)
		return (-1);
	if (ft_strlen(argv[1]) < 4)
	{
		ft_putstr_fd("Error\nnot a .ber file\n", 2);
		return (-1);
	}
	str = ft_substr(argv[1], ft_strlen(argv[1]) - 4, 4);
	if (!str)
	{
		ft_putstr_fd("Error\nmalloc error\n", 2);
		return (-1);
	}
	if (ft_strncmp(str, ".ber", 4))
	{
		free(str);
		ft_putstr_fd("Error\nnot a .ber file\n", 2);
		return (-1);
	}
	free(str);
	return (0);
}

int	main(int argc, char **argv)
{
	t_init	data;
	int		ret;

	if (ft_handle_errors(argc, argv) == -1)
		return (-1);
	data.fd = open(argv[1], O_RDONLY);
	if (data.fd < 0)
		return (ft_put_error("Error\nnot a valid file\n"));
	ret = ft_create_array(&data);
	close(data.fd);
	if (ret == -1)
		return (-1);
	if (ret == -2)
		return (ft_put_error("Error\nmalloc error\n"));
	if (ret == -3)
		return (ft_put_error("Error\nread error\n"));
	data.moves = 0;
	data.ret = MOVE;
	if (window(&data) == -1)
		ft_put_error(("Error\ninitialzing error in window\n"));
	return (1);
}
