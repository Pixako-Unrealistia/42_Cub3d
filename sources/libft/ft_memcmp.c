/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:46:01 by schongte          #+#    #+#             */
/*   Updated: 2022/10/16 11:36:43 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*t1;
	unsigned char	*t2;
	size_t			counter;

	counter = 0;
	t1 = (unsigned char *) str1;
	t2 = (unsigned char *) str2;
	while (counter < n)
	{
		if (t1[counter] != t2[counter])
			return (t1[counter] - t2[counter]);
		counter++;
	}
	return (0);
}
