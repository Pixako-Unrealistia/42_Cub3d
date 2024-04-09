/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:57:44 by tnualman          #+#    #+#             */
/*   Updated: 2022/09/19 03:42:35 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	len_s;
	unsigned int	i;

	if (!s || !f)
		return ;
	len_s = ft_strlen(s);
	i = 0;
	while (i < len_s)
	{
		f(i, s + i);
		i++;
	}
}
