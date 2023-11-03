/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-tole <ede-tole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 07:29:25 by ede-tole          #+#    #+#             */
/*   Updated: 2023/10/19 07:29:27 by ede-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*aux;
	size_t	i;
	size_t	j;

	aux = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!aux)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		aux[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		aux[j++] = s2[i];
		i++;
	}
	aux[j] = 0;
	return (aux);
}
