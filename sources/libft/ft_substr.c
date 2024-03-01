/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:08:23 by schongte          #+#    #+#             */
/*   Updated: 2022/09/19 16:38:03 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	char	*tmps;

	if (!s)
		return (0);
	tmps = (char *)s;
	if (ft_strlen(tmps) < start)
		len = 0;
	if (ft_strlen(tmps + start) < len)
		len = ft_strlen(tmps + start);
	tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, tmps + start, len + 1);
	return (tmp);
}
