/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_tostr_base10.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:34:31 by tnualman          #+#    #+#             */
/*   Updated: 2023/01/19 19:15:26 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int		baselen(ssize_t n);
static ssize_t	ft_abs(ssize_t n);

char	*ft_signed_tostr_base10(ssize_t n)
{
	char	*base;
	char	*str;
	int		i;
	int		sign;

	base = "0123456789";
	str = ft_calloc(sizeof(char), baselen(n) + 1);
	if (!str)
		return (NULL);
	sign = 1;
	if (n < 0)
		sign = -1;
	str[0] = '0';
	i = 0;
	while (n)
	{
		str[i++] = base[ft_abs(n % 10)];
		n /= 10;
	}
	if (sign < 0)
		str[i] = '-';
	ft_strrev(str);
	return (str);
}

static int	baselen(ssize_t n)
{
	int	i;

	i = 0;
	if (n < 1)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static ssize_t	ft_abs(ssize_t n)
{
	if (n < 0)
		return (-n);
	return (n);
}
