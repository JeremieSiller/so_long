#include "img.h"

/*
** helper function for img_half which assigns all values of the new
**image to its corresponding specifier.
*/

static int	assign_data_to_img(t_img *img, t_img *tmp, t_init *data, int d_or_h)
{
	mlx_destroy_image(data->mlx, img->img);
	img->img = tmp->img;
	if (d_or_h)
	{
		img->height /= 2;
		img->width /= 2;
	}
	else
	{
		img->height *= 2;
		img->width *= 2;
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (1);
}

/*
** img_half creates an Image which is half as big as the input image.
** It will destroy the old image and assign the new one to the img pointer.
*/

int	img_half(t_init *data, t_img *img)
{
	int		x;
	int		y;
	t_img	tmp;
	char	*dst;

	x = img->width;
	tmp.img = mlx_new_image(data->mlx, img->width / 2, img->height / 2);
	if (!tmp.img)
		return (0);
	tmp.addr = mlx_get_data_addr(tmp.img, &tmp.bits_per_pixel,
			&tmp.line_length, &tmp.endian);
	while (x--)
	{
		y = img->height;
		while (y--)
		{
			if (y % 2 == 0 && x % 2 == 0)
			{
				dst = img->addr + (y * img->line_length
						+ x * (img->bits_per_pixel / 8));
				my_mlx_pixel_put(&tmp, x / 2, y / 2, *(int *)dst);
			}
		}
	}
	return (assign_data_to_img(img, &tmp, data, 1));
}

int	img_double(t_init *data, t_img *img)
{
	int		x;
	int		y;
	t_img	tmp;
	char	*dst;

	x = img->width;
	tmp.img = mlx_new_image(data->mlx, img->width * 2, img->height * 2);
	if (!tmp.img)
		return (0);
	tmp.addr = mlx_get_data_addr(tmp.img, &tmp.bits_per_pixel,
			&tmp.line_length, &tmp.endian);
	while (x--)
	{
		y = img->height;
		while (y--)
		{
			dst = img->addr + (y * img->line_length
					+ x * (img->bits_per_pixel / 8));
			my_mlx_pixel_put(&tmp, x * 2, y * 2, *(int *)dst);
			my_mlx_pixel_put(&tmp, (x * 2) + 1, (y * 2) + 1, *(int *)dst);
			my_mlx_pixel_put(&tmp, (x * 2) + 1, (y * 2), *(int *)dst);
			my_mlx_pixel_put(&tmp, (x * 2), (y * 2) + 1, *(int *)dst);
		}
	}
	return (assign_data_to_img(img, &tmp, data, 0));
}
