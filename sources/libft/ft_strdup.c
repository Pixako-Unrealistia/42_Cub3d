/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:37:34 by schongte          #+#    #+#             */
/*   Updated: 2022/09/11 20:43:27 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*new;
	size_t	counter;
	size_t	size;

	size = 0;
	while (src[size])
		++size;
	new = malloc(sizeof(char) * (size + 1));
	if (new)
	{
		counter = 0;
		while (src[counter])
		{
			new[counter] = src[counter];
			counter++;
		}
		new[counter] = '\0';
		return (new);
	}
	return (NULL);
}
