/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:18:24 by schongte          #+#    #+#             */
/*   Updated: 2022/10/16 22:12:56 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*em(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*res;

	if (!del || !f || !lst)
		return (NULL);
	res = ft_lstnew(f(lst->content));
	if (!res)
		return (NULL);
	return (res);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*c1;
	t_list		*c2;
	t_list		*res;

	res = em(lst, f, del);
	if (!res)
		return (NULL);
	c1 = NULL;
	ft_lstadd_back(&c1, res);
	c2 = c1;
	lst = lst->next;
	while (lst)
	{
		res = ft_lstnew(f(lst->content));
		if (!res)
		{
			ft_lstclear(&c1, del);
			return (NULL);
		}
		ft_lstadd_back(&c2, res);
		c2 = c2->next;
		lst = lst->next;
	}
	return (c1);
}
