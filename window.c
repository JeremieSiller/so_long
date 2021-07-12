/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 22:36:53 by jsiller           #+#    #+#             */
/*   Updated: 2021/07/08 13:10:28 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "img_stuff/img.h"

void	get_img_addr(t_init *data)
{
	data->player.addr = mlx_get_data_addr(data->player.img,
			&data->player.bits_per_pixel,
			&data->player.line_length, &data->player.endian);
	data->wall.addr = mlx_get_data_addr(data->wall.img,
			&data->wall.bits_per_pixel,
			&data->wall.line_length, &data->wall.endian);
	data->background.addr = mlx_get_data_addr(data->background.img,
			&data->background.bits_per_pixel,
			&data->background.line_length, &data->background.endian);
	data->cocllect.addr = mlx_get_data_addr(data->cocllect.img,
			&data->cocllect.bits_per_pixel,
			&data->cocllect.line_length, &data->cocllect.endian);
	data->exit.addr = mlx_get_data_addr(data->exit.img,
			&data->exit.bits_per_pixel,
			&data->exit.line_length, &data->exit.endian);
}

int	ft_open_imgs(t_init *data)
{
	data->player.img = mlx_xpm_file_to_image(data->mlx, PLAYER_PATH,
			&data->player.width, &data->player.height);
	data->wall.img = mlx_xpm_file_to_image(data->mlx, WALL_PATH,
			&data->wall.width, &data->wall.height);
	data->background.img = mlx_xpm_file_to_image(data->mlx, BACKGROUND_PATH,
			&data->background.width, &data->background.height);
	data->cocllect.img = mlx_xpm_file_to_image(data->mlx, COLLECT_PATH,
			&data->cocllect.width, &data->cocllect.height);
	data->exit.img = mlx_xpm_file_to_image(data->mlx, EXIT_PATH,
			&data->exit.width, &data->exit.height);
	if (!data->exit.img || !data->cocllect.img || !data->wall.img
		|| !data->player.img || !data->background.img)
		return (-1);
	get_img_addr(data);
	return (0);
}

void	ft_free_stuff(t_init *data)
{
	mlx_destroy_image(data->mlx, data->player.img);
	mlx_destroy_image(data->mlx, data->wall.img);
	mlx_destroy_image(data->mlx, data->background.img);
	mlx_destroy_image(data->mlx, data->exit.img);
	mlx_destroy_image(data->mlx, data->cocllect.img);
	free(data->line);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	keys(int key, t_init *data)
{
	if (key == KEY_ESC)
		ft_free_stuff(data);
	if (data->ret == EXIT)
		return (1);
	if (key == KEY_W)
		data->ret = ft_make_move('W', data->line, data);
	if (key == KEY_A)
		data->ret = ft_make_move('A', data->line, data);
	if (key == KEY_D)
		data->ret = ft_make_move('D', data->line, data);
	if (key == KEY_S)
		data->ret = ft_make_move('S', data->line, data);
	put_images(data);
	if (data->ret != -1 && (key == KEY_W
			|| key == KEY_A || key == KEY_D || key == KEY_S))
	{
		data->moves++;
		ft_putnbr_fd(data->moves, 1);
		ft_putchar_fd('\n', 1);
	}
	return (1);
}

int	window(t_init *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (-1);
	data->field = STANDARD;
	while (data->field * ft_strlen(data->line[0]) > 2560
		|| data->field * ft_height(data->line) > 1440)
		data->field /= 2;
	if (ft_open_imgs(data) == -1)
		return (-1);
	ft_find_player(data->line, data);
	while (data->player.height > data->field)
	{
		if (!img_half(data, &data->player) || !img_half(data, &data->wall)
			|| !img_half(data, &data->background)
			|| !img_half(data, &data->cocllect)
			|| !img_half(data, &data->exit))
			return (-1);
	}
	data->win = mlx_new_window(data->mlx, data->field
			* ft_strlen(data->line[0]), data->field
			* ft_height(data->line), "so_long");
	put_images(data);
	mlx_hook(data->win, 2, 1L << 0, keys, data);
	mlx_hook(data->win, 17, 1L << 0, mouse, data);
	return (mlx_loop(data->mlx));
}
