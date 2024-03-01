/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:26:24 by schongte          #+#    #+#             */
/*   Updated: 2023/04/06 01:35:33 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	util_hex_ascii(unsigned int tempval, int asc)
{
	if ((tempval % 16) < 10)
		return ((tempval % 16) + 48);
	else
		return ((tempval % 16) + asc);
}
