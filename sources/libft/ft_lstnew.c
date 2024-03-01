/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:29:00 by schongte          #+#    #+#             */
/*   Updated: 2022/10/16 15:45:39 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tempo;

	tempo = (t_list *)malloc(sizeof(*tempo));
	if (!tempo)
		return (NULL);
	tempo->content = content;
	tempo->next = NULL;
	return (tempo);
}
