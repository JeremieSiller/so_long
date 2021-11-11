/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:34:18 by jsiller           #+#    #+#             */
/*   Updated: 2021/11/11 20:29:36 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	ft_is_str_in_str(char *line, char *map)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(map, line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_not_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

void	*ft_realloc(void *ptr, size_t size, size_t old_size)
{
	void	*tmp;

	if (size == 0 || !ptr)
		return (0);
	tmp = malloc(size);
	if (!tmp)
		return (0);
	ft_memcpy(tmp, ptr, old_size);
	free(ptr);
	return (tmp);
}

void	free_line(char **line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		free(line[i]);
		i++;
	}
}
