/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:04:06 by mpedraza          #+#    #+#             */
/*   Updated: 2025/11/17 18:20:22 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*new_item;
	void	*result;

	if (!lst || !f || !del)
		return (NULL);
	map = NULL;
	while (lst)
	{
		result = (*f)(lst->content);
		new_item = ft_lstnew(result);
		if (!new_item)
		{
			del(result);
			ft_lstclear(&map, del);
			return (NULL);
		}
		ft_lstadd_back(&map, new_item);
		lst = lst->next;
	}
	return (map);
}
