/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:24:28 by tnualman          #+#    #+#             */
/*   Updated: 2022/09/19 03:42:23 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*uchar_s1;
	const unsigned char	*uchar_s2;
	unsigned char		uchar_s1_i;
	unsigned char		uchar_s2_i;
	size_t				i;

	if (s1 == s2 || n == 0)
		return (0);
	uchar_s1 = s1;
	uchar_s2 = s2;
	i = 0;
	while (i < n)
	{
		uchar_s1_i = uchar_s1[i];
		uchar_s2_i = uchar_s2[i];
		if (uchar_s1_i != uchar_s2_i)
			return (uchar_s1_i - uchar_s2_i);
		i++;
	}
	return (0);
}
