/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:47:39 by jsiller           #+#    #+#             */
/*   Updated: 2021/11/10 13:29:05 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_find_player(char **line, t_init *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < (int)ft_strlen(line[y]))
	{
		y = 0;
		while (y < ft_height(line) - 1)
		{
			if (line[y][x] == 'P')
			{
				data->x_player = x;
				data->y_player = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

int	ft_find_collect(char **line)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < ft_height(line))
	{
		x = 0;
		while (x < (int)ft_strlen(line[0]))
		{
			if (line[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_check_sorrounding(char **line)
{
	int	i;

	i = 0;
	if (!ft_not_strchr(line[0], '1'))
		return (-1);
	while (line[i])
	{
		if (line[i][0] != '1' || line[i][ft_strlen(line[i]) - 1] != '1')
			return (-1);
		i++;
	}
	if (!ft_not_strchr(line[i - 1], '1'))
		return (-1);
	return (0);
}

int	ft_height(char **line)
{
	int	i;

	i = 0;
	while (line[i] != 0)
		i++;
	return (i);
}

int	ft_put_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (-1);
}
