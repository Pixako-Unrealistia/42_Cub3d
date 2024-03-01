/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:56:13 by schongte          #+#    #+#             */
/*   Updated: 2022/09/19 23:29:57 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		tempo;
	int		counter;
	int		counter2;
	char	*string;

	if (!s1 || !s2)
		return (NULL);
	counter = ft_strlen((char *)s1);
	counter2 = ft_strlen((char *)s2);
	string = (char *)malloc((counter + counter2 + 1) * sizeof(char));
	if (!string)
		return (0);
	tempo = -1;
	while (s1[++tempo])
		string[tempo] = s1[tempo];
	tempo = -1;
	while (s2[++tempo])
	{
		string[counter] = s2[tempo];
		counter++;
	}
	string[counter] = '\0';
	return (string);
}
