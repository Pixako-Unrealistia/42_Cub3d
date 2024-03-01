/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 23:09:45 by schongte          #+#    #+#             */
/*   Updated: 2022/10/14 00:17:10 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*tempo;
	const unsigned char	*tempo2;

	if (!dest && !src)
		return (NULL);
	tempo = dest;
	tempo2 = src;
	while (n-- > 0)
	{
		*tempo = *tempo2;
		tempo++;
		tempo2++;
	}
	return (dest);
}
