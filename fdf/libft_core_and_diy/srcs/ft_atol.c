/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:44:25 by tnualman          #+#    #+#             */
/*   Updated: 2023/07/31 18:15:25 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This ft_atol() is implemented such that the out-of-bound inputs will result 
 * in values at bounds (LONG_MIN and LONG_MAX) instead of 0 and -1.
 */

static long	cutoff_handler(long acc, int n)
{
	if (acc < -922337203685477580)
		return (-9223372036854775807 - 1);
	if (acc > 922337203685477580)
		return (9223372036854775807);
	if (acc == -922337203685477580)
	{
		if (n > 8)
			return (-9223372036854775807 - 1);
		return (acc * 10 - n);
	}
	if (acc == 922337203685477580)
	{
		if (n > 7)
			return (9223372036854775807);
		return (acc * 10 + n);
	}
	return (0);
}

long	ft_atol(const char *str)
{
	int		sign;
	long	acc;

	acc = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		if (-2922337203685477580 >= acc || acc >= 922337203685477580)
			return (cutoff_handler(acc, *str - '0'));
		acc *= 10;
		acc += sign * (*str - '0');
		str++;
	}
	return (acc);
}
