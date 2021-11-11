/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:34:26 by jsiller           #+#    #+#             */
/*   Updated: 2021/11/11 20:35:12 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <img.h>

void	put_images(t_init *data)
{
	int	y;
	int	x;

	y = ft_height(data->line);
	while (y--)
	{
		x = ft_strlen(*(data->line));
		while (x--)
			put_images_b(data, x, y);
	}
}

int	mouse(t_init *data)
{
	ft_free_stuff(data);
	exit(0);
	return (1);
}

void	put_images_b(t_init *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->background.img, x * data->field, y * data->field);
	if ((data->line)[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->player.img,
			x * data->field, y * data->field);
	if ((data->line)[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->exit.img, x * data->field, y * data->field);
	if ((data->line)[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall.img,
			x * data->field, y * data->field);
	if ((data->line)[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->cocllect.img, x * data->field, y * data->field);
}
