/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 23:32:32 by schongte          #+#    #+#             */
/*   Updated: 2022/10/13 23:03:52 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	tempo;
	char	*result;

	if (s1 && set)
	{
		while (*s1 && ft_strchr(set, *s1))
			s1++;
		tempo = ft_strlen((char *)s1);
		while (tempo && ft_strchr(set, s1[tempo]))
			tempo--;
		result = ft_substr((char *)s1, 0, tempo + 1);
		return (result);
	}
	return (NULL);
}
