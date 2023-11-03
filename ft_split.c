/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-tole <ede-tole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 07:29:05 by ede-tole          #+#    #+#             */
/*   Updated: 2023/10/19 07:29:06 by ede-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_matrix(char const **dst, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)dst[j]);
	}
	free(dst);
	return (NULL);
}

static int	n_cols(char const *s2, char c, int i)
{
	int	lenght;

	lenght = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static int	n_strings(char const *s1, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			i = 0;
		else if (i == 0)
		{
			i = 1;
			count++;
		}
		s1++;
	}
	return (count);
}

static char	**split_aux(char const *s, char **dst, char c, int l)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < l)
	{
		k = 0;
		while (s[i] == c)
			i++;
		dst[j] = (char *)malloc((n_cols(s, c, i) + 1) * sizeof(char));
		if (dst[j] == NULL)
			return (free_matrix((const char **)dst, j));
		while (s[i] != '\0' && s[i] != c)
			dst[j][k++] = s[i++];
		dst[j][k] = '\0';
		j++;
	}
	dst[j] = 0;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**m;
	int		rows;

	if (s == NULL)
		return (NULL);
	rows = n_strings(s, c);
	m = (char **)malloc((rows + 1) * sizeof(char *));
	if (m == NULL)
		return (NULL);
	return (split_aux(s, m, c, rows));
}
