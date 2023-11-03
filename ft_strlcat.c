/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-tole <ede-tole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:33:13 by ede-tole          #+#    #+#             */
/*   Updated: 2023/10/26 14:57:30 by ede-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index_d;
	unsigned int	index_s;
	unsigned int	size_d;

	size_d = ft_strlen(dest);
	index_d = ft_strlen(dest);
	index_s = 0;
	if (size < ft_strlen(dest))
		return (size + ft_strlen(src));
	if (size == 0)
		return (ft_strlen(src));
	while (src[index_s] && index_d < size - 1)
	{
		dest[index_d] = src[index_s];
		index_d++;
		index_s++;
	}
	dest[index_d] = '\0';
	return (ft_strlen(src) + size_d);
}
