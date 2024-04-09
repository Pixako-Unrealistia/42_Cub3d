/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:13:07 by tnualman          #+#    #+#             */
/*   Updated: 2022/09/19 03:42:46 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	i[3];

	if (!s1 || !set)
		return (NULL);
	if (!*s1)
		return (ft_calloc(1, 1));
	i[1] = 0;
	while (s1[i[1]] && ft_strchr(set, s1[i[1]]))
		i[1]++;
	i[2] = i[1] + ft_strlen(s1 + i[1]) - 1;
	while (i[1] <= i[2] && ft_strchr(set, s1[i[2]]))
		i[2]--;
	trimmed = (char *)malloc(sizeof(char) * (2 + i[2] - i[1]));
	if (!trimmed)
		return (NULL);
	i[0] = 0;
	while (i[0] < 1 + i[2] - i[1])
	{
		trimmed[i[0]] = s1[i[0] + i[1]];
		i[0]++;
	}
	trimmed[i[0]] = '\0';
	return (trimmed);
}
