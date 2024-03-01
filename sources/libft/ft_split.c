/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:29:58 by schongte          #+#    #+#             */
/*   Updated: 2022/10/16 22:29:27 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_modlen(const char *s, char c)
{
	size_t	counter;
	size_t	flag;

	counter = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && !flag)
		{
			flag = 1;
			counter++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (counter);
}

char	*allocat(const char *s, size_t start, size_t end)
{
	char	*newstr;
	size_t	counter;

	counter = 0;
	newstr = malloc(sizeof(char) * (end - start + 1));
	while (start < end)
		newstr[counter++] = s[start++];
	newstr[counter] = '\0';
	return (newstr);
}

char	**ft_split(char const *s, char c)
{
	size_t	c1;
	size_t	c2;
	int		target;
	char	**res;

	res = malloc(sizeof(char *) * (ft_modlen(s, c) + 1));
	if (!s || !res)
		return (0);
	c1 = 0;
	c2 = 0;
	target = -1;
	while (c1 <= ft_strlen(s))
	{
		if (s[c1] != c && target < 0)
			target = c1;
		else if ((s[c1] == c || c1 == ft_strlen(s)) && target >= 0)
		{
			res[c2++] = allocat(s, target, c1);
			target = -1;
		}
		c1++;
	}
	res[c2] = 0;
	return (res);
}
