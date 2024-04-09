/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:14:15 by tnualman          #+#    #+#             */
/*   Updated: 2022/09/19 03:42:24 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*uchar_dst;
	const unsigned char	*uchar_src;
	size_t				i;

	if (dst == src)
		return (dst);
	uchar_dst = dst;
	uchar_src = src;
	i = 0;
	while (i < n)
	{
		uchar_dst[i] = uchar_src[i];
		i++;
	}
	return (dst);
}
