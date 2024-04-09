/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:14:15 by tnualman          #+#    #+#             */
/*   Updated: 2022/09/19 03:42:28 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*uchar_b;
	unsigned char	uchar_c;
	size_t			i;

	uchar_b = b;
	uchar_c = c;
	i = 0;
	while (i < len)
		uchar_b[i++] = uchar_c;
	return (b);
}
