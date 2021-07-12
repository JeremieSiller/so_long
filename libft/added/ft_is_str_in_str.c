/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_in_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:10:30 by jsiller           #+#    #+#             */
/*   Updated: 2021/07/02 14:45:54 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Checks if all chars of str are in find
*/

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
