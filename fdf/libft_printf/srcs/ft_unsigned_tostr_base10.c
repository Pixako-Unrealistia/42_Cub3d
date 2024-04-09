/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_tostr_base10.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:23:58 by tnualman          #+#    #+#             */
/*   Updated: 2023/01/19 15:02:50 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	baselen(size_t n);

char	*ft_unsigned_tostr_base10(size_t n)
{
	char	*base;
	char	*str;
	int		i;

	base = "0123456789";
	str = ft_calloc(sizeof(char), baselen(n) + 1);
	if (!str)
		return (NULL);
	str[0] = '0';
	i = 0;
	while (n > 0)
	{
		str[i++] = base[n % 10];
		n /= 10;
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
		n /= 10;
		i++;
	}
	return (i);
}
