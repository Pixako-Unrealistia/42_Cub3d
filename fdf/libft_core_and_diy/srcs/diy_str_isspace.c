/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diy_str_isspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:55:54 by tnualman          #+#    #+#             */
/*   Updated: 2023/08/01 18:01:55 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	diy_str_isspace(const char *str)
{
	if (!str)
		return (0);
	if (!*str)
		return (1);
	while (*str)
		if (!ft_isspace(*str++))
			return (0);
	return (1);
}
