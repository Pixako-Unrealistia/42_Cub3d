/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:35:15 by schongte          #+#    #+#             */
/*   Updated: 2022/10/17 00:21:00 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	descount;
	size_t	srccount;

	descount = ft_strlen(dest);
	srccount = ft_strlen(src);
	if (descount > n)
		descount = n;
	if (!n || descount == n)
		return (descount + srccount);
	if (srccount < n - descount)
		ft_memcpy(dest + descount, src, srccount + 1);
	else
	{
		ft_memcpy(dest + descount, src, n - descount - 1);
		dest[n - 1] = '\0';
	}
	return (descount + srccount);
}
