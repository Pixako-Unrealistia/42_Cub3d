/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:50:34 by schongte          #+#    #+#             */
/*   Updated: 2022/10/16 11:30:19 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			counter;
	unsigned char	*tempo;

	tempo = (unsigned char *)str;
	counter = 0;
	while (counter < n)
	{
		if (*tempo == (unsigned char)c)
			return (tempo);
		counter++;
		tempo++;
	}
	return (NULL);
}
