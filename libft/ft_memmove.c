/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 23:09:45 by schongte          #+#    #+#             */
/*   Updated: 2022/10/14 11:40:26 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*tempo;
	char		*tempo2;
	size_t		counter;

	if (!dest && !src)
		return (NULL);
	counter = 0;
	tempo = dest;
	tempo2 = (void *)src;
	if (tempo >= tempo2)
		while (++counter <= n)
			tempo[n - counter] = tempo2[n - counter];
	else
	{
		while (n-- > 0)
		{
			*tempo = *tempo2;
			tempo++;
			tempo2++;
		}
	}
	return (dest);
}
