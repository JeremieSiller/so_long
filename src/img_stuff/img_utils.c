/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:34:39 by jsiller           #+#    #+#             */
/*   Updated: 2021/11/10 13:34:39 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <img.h>

/*
**puts pixel with color to coordinates x t of data
*/

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}
