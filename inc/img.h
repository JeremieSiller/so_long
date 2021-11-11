#ifndef IMG_H
# define IMG_H

# include <mlx.h>
# include <so_long.h>

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
//int		img_double(t_init *data, t_img *img);
int		img_half(t_init *data, t_img *img);

#endif