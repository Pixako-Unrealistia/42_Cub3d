/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:57:44 by tnualman          #+#    #+#             */
/*   Updated: 2022/09/19 03:42:42 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s_mapped;
	unsigned int	len_s;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len_s = ft_strlen(s);
	s_mapped = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!s_mapped)
		return (NULL);
	i = 0;
	while (i < len_s)
	{
		s_mapped[i] = f(i, s[i]);
		i++;
	}
	s_mapped[i] = '\0';
	return (s_mapped);
}
