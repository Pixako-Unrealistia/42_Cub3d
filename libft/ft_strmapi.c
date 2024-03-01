/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:27:17 by schongte          #+#    #+#             */
/*   Updated: 2022/10/15 23:13:15 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		len;
	size_t		counter;
	char		*tmpstr;
	char		*result;

	counter = 0;
	tmpstr = (char *)s;
	if (!tmpstr || !f)
		return (NULL);
	len = ft_strlen(tmpstr);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (counter < len)
	{
		result[counter] = f(counter, tmpstr[counter]);
		counter++;
	}
	result[counter] = '\0';
	return (result);
}
