/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 07:31:03 by tnualman          #+#    #+#             */
/*   Updated: 2022/09/19 03:42:39 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_src;
	size_t	len_cpy;

	len_src = ft_strlen(src);
	if (dstsize == 0)
		return (len_src);
	i = 0;
	len_cpy = dstsize - 1;
	if (len_src < len_cpy)
		len_cpy = len_src;
	while (i < len_cpy)
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	return (len_src);
}
