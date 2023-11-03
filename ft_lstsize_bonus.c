/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-tole <ede-tole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 07:28:07 by ede-tole          #+#    #+#             */
/*   Updated: 2023/10/19 07:28:09 by ede-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		num;
	t_list	*aux;

	aux = lst;
	num = 1;
	if (!lst)
		return (0);
	while (aux->next != NULL)
	{
		num ++;
		aux = aux->next;
	}
	return (num);
}
