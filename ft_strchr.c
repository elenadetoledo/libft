/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-tole <ede-tole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:04:28 by ede-tole          #+#    #+#             */
/*   Updated: 2023/10/26 17:05:17 by ede-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	l;
	char	*str;

	l = (char)c;
	str = (char *)s;
	if (l == 0)
	{
		while (*str != '\0')
			str++;
		return (str);
	}
	while (*str != '\0')
	{
		if (*str == l)
			return (str);
		str++;
	}
	return (NULL);
}
