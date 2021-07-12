/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 12:13:15 by jsiller           #+#    #+#             */
/*   Updated: 2021/07/02 13:52:46 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
