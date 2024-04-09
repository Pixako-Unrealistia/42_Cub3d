/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:17:16 by tnualman          #+#    #+#             */
/*   Updated: 2022/09/19 03:42:22 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*uchar_s;
	unsigned char		uchar_c;
	size_t				i;

	if (n == 0)
		return (NULL);
	uchar_s = s;
	uchar_c = c;
	i = 0;
	while (i < n)
	{
		if (uchar_s[i] == uchar_c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
