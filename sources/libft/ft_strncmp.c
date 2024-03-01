/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:21:10 by schongte          #+#    #+#             */
/*   Updated: 2022/10/16 12:12:15 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *dest, const char *src, size_t n)
{
	size_t	tempo;

	tempo = 0;
	while ((dest[tempo] || src[tempo]) && n > 0)
	{
		if (dest[tempo] != src[tempo])
			return ((unsigned char)dest[tempo] - (unsigned char)src[tempo]);
		tempo++;
		n--;
	}
	return (0);
}
