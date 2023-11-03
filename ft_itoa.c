/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-tole <ede-tole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 08:03:05 by ede-tole          #+#    #+#             */
/*   Updated: 2023/10/17 08:03:07 by ede-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	length(long n, int base)
{
	int	x;

	x = 0;
	if (!base)
		base = 10;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		x++;
		n /= base;
	}
	return (x);
}

static char	*aux1(char *str, int len, int n, int n_new)
{
	str[len] = '\0';
	while (len-- > 0)
	{
		if (len > 0 || n_new >= 0)
			str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

static char	*alloc(char *str, int len, int n, int n_new)
{
	if (n >= 0)
	{
		str = (char *)malloc(len + 1);
		if (str == NULL)
			return (NULL);
	}
	else if (n < 0 && n != -2147483648)
	{
		str = (char *)malloc(++len + 1);
		if (str == NULL)
			return (NULL);
		str[0] = '-';
		n = -n;
	}
	else
	{
		str = (char *)malloc(12);
		if (str == NULL)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	return (aux1(str, len, n, n_new));
}

char	*ft_itoa(int n)
{
	char	*aux;
	int		len;
	int		n_new;

	n_new = n;
	len = length(n, 10);
	aux = NULL;
	aux = alloc(aux, len, n, n_new);
	if (aux == NULL)
		return (NULL);
	return (aux);
}
