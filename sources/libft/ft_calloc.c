/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:11:31 by schongte          #+#    #+#             */
/*   Updated: 2022/10/16 15:39:12 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*tempo;

	if (!nitems || !size)
		return (malloc(0));
	if (nitems == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	tempo = malloc(nitems * size);
	if (!tempo)
		return (NULL);
	ft_memset((unsigned char *)tempo, 0, nitems * size);
	return (tempo);
}
