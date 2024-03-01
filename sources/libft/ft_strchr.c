/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 22:16:47 by schongte          #+#    #+#             */
/*   Updated: 2022/10/16 11:47:24 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*copy;

	copy = (char *)str;
	if (!c)
		return (&copy[ft_strlen(str)]);
	while (*copy)
	{
		if (*copy == (char)c)
			return (copy);
		copy++;
	}
	return ((char *) NULL);
}
