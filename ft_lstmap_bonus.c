/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-tole <ede-tole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 07:27:54 by ede-tole          #+#    #+#             */
/*   Updated: 2023/10/19 07:27:56 by ede-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*temp;
	t_list	*set;

	if (!f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		set = (*f)(lst->content);
		temp = ft_lstnew(set);
		if (!temp)
		{
			del(set);
			ft_lstclear(&first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, temp);
		lst = lst->next;
	}
	return (first);
}
