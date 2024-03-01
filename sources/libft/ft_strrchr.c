/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 23:28:35 by schongte          #+#    #+#             */
/*   Updated: 2022/10/16 12:00:55 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	counter;

	counter = ft_strlen(str);
	if (!c && !str)
		return ((char *)&str[0]);
	else if (!str)
		return (NULL);
	while (counter >= 0)
	{
		if (str[counter] == (char)c)
			return ((char *)&str[counter]);
		counter--;
	}
	if (c == 0)
		return ((char *)&str[counter]);
	return (NULL);
}
