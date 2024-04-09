/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:44:25 by tnualman          #+#    #+#             */
/*   Updated: 2023/09/08 17:11:57 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function returns -1 if argument is not a hexadecimal digit.
static unsigned int	char_to_int_base16(char c)
{
	if ('0' <= c && c <= '9')
		return (c - '0');
	else if ('a' <= c && c <= 'f')
		return (c - 'a' + 10);
	else if ('A' <= c && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

/* This function returns UINT_MAX (4294967295) in cases of overflow, instead
 * of -1, as in atoi().
 */
unsigned int	ft_atoui_hex(const char *str)
{
	unsigned int	acc;
	int				digit;

	acc = 0;
	while (ft_isspace(*str))
		str++;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		str += 2;
	digit = char_to_int_base16(*str);
	while (digit > -1)
	{
		if (acc >> 28)
			return (4294967295);
		acc = (acc << 4) + digit;
		digit = char_to_int_base16(*(++str));
	}
	return (acc);
}
