/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:30:29 by schongte          #+#    #+#             */
/*   Updated: 2022/10/16 12:31:08 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	unfortunette(long value)
{
	if (value > 2147483647)
		return (0);
	else if (value < -2147483648)
		return (-1);
	else
		return (value);
}

int	looper(int pint, char *str, long value, int dividant)
{
	int	diff;
	int	flak;

	flak = 0;
	if (str[pint] == 43)
		pint++;
	else if (str[pint] == 45)
	{
		flak++;
		pint++;
	}
	diff = pint;
	while (str[pint] >= 48 && str[pint] <= 57)
		pint++;
	while (diff - pint != 0)
	{
		value += ((str[pint - 1] - 48) * dividant);
		dividant *= 10;
		pint--;
	}
	if (flak == 1)
		value = -value;
	return (unfortunette(value));
}

int	ft_atoi(const char *str)
{
	int		pint;
	long	value;
	int		dividant;

	value = 0;
	pint = 0;
	dividant = 1;
	while ((str[pint] >= 9 && str[pint] <= 13) || str[pint] == 32)
		pint++;
	return (looper(pint, (char *)str, value, dividant));
}
