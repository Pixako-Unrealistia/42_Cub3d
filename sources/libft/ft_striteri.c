/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:27:17 by schongte          #+#    #+#             */
/*   Updated: 2022/10/16 15:42:28 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char const *s, void (*f)(unsigned int, char *))
{
	unsigned int		tempo;
	char				*tmpstr;

	tmpstr = (char *)s;
	if (!tmpstr || !f)
		return ;
	tempo = 0;
	while (tmpstr[tempo])
	{
		f(tempo, &tmpstr[tempo]);
		tempo++;
	}
}
