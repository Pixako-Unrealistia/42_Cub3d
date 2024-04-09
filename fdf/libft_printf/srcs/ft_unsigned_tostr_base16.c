/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_tostr_base16.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:34:48 by tnualman          #+#    #+#             */
/*   Updated: 2023/01/19 15:02:50 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	baselen(size_t n);

char	*ft_unsigned_tostr_base16(size_t n)
{
	char	*base;
	char	*str;
	int		i;

	base = "0123456789abcdef";
	str = ft_calloc(sizeof(char), baselen(n) + 1);
	if (!str)
		return (NULL);
	str[0] = '0';
	i = 0;
	while (n > 0)
	{
		str[i++] = base[n % 16];
		n /= 16;
	}
	ft_strrev(str);
	return (str);
}

static int	baselen(size_t n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}
