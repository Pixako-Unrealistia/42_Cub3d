/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 07:31:03 by tnualman          #+#    #+#             */
/*   Updated: 2022/09/19 03:42:38 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;
	size_t	len_cat;

	if (!dstsize)
		return (ft_strlen(src));
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize <= len_dst)
		return (dstsize + len_src);
	len_cat = dstsize - 1;
	if (len_cat > len_dst + len_src)
		len_cat = len_dst + len_src;
	i = len_dst;
	dst += i;
	while (i < len_cat)
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	return (len_dst + len_src);
}
