/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 23:28:35 by schongte          #+#    #+#             */
/*   Updated: 2022/10/15 23:25:58 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *c, size_t n)
{
	size_t	counter;

	if (!*c || str == c)
		return ((char *)str);
	if (*c && n == 0)
		return (NULL);
	counter = ft_strlen((char *)c);
	while (*str && counter <= n)
	{
		if (!(ft_strncmp((char *)str, (char *)c, counter)))
			return ((char *)str);
		str++;
		n--;
	}
	return (NULL);
}
