/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:31:53 by schongte          #+#    #+#             */
/*   Updated: 2023/01/07 15:31:55 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	util_strlen(char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

char	*util_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *) str);
		str++;
	}
	if (c == '\0')
		return ((char *) str);
	return ((char *) NULL);
}

void	*util_memset(void *str, int c, size_t n)
{
	unsigned char	*tempo;

	tempo = str;
	while (n > 0)
	{
		*tempo = c;
		tempo++;
		n--;
	}
	return (str);
}

char	*util_strjoin(char const *s1, char const *s2)
{
	int		tempo;
	int		counter;
	char	*string;

	if (!s1 || !s2)
		return (NULL);
	counter = util_strlen((char *)s1) + util_strlen((char *)s2);
	string = (char *)malloc((counter + 1) * sizeof(char));
	if (!string)
		return (NULL);
	tempo = -1;
	while (s1[++tempo])
		string[tempo] = s1[tempo];
	tempo = -1;
	counter = util_strlen((char *)s1);
	while (s2[++tempo])
	{
		string[counter] = s2[tempo];
		counter++;
	}
	string[counter] = '\0';
	return (string);
}

void	*util_calloc(size_t nitems, size_t size)
{
	char	*tempo;
	size_t	total;
	size_t	counter;

	tempo = malloc(nitems * size);
	if (!tempo)
		return (NULL);
	total = nitems * size;
	counter = 0;
	while (counter < total)
	{
		tempo[counter] = 0;
		counter++;
	}
	return (tempo);
}
