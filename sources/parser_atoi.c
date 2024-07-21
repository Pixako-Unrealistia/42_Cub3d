/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <schongte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:33:31 by schongte          #+#    #+#             */
/*   Updated: 2024/07/21 22:33:31 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	return (1);
}

static int	limit_check(long value)
{
	if (value > 255 || value < 0)
		return (-1);
	else
		return ((int)value);
}

static int	looper(int iter, char *str, long value, int divider)
{
	int	diff;
	int	flag;

	flag = 0;
	if (str[iter] == '+')
	{
		iter++;
	}
	else if (str[iter] == '-')
	{
		flag++;
		iter++;
	}
	diff = iter;
	while (ft_isdigit(str[iter]))
		iter++;
	while (diff - iter != 0)
	{
		value += ((str[iter - 1] - '0') * divider);
		divider *= 10;
		iter--;
	}
	if (flag == 1)
		value = -value;
	return (limit_check(value));
}

int	validate_input(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < ft_strlen_nonl(str))
	{
		if (!ft_isdigit(str[i]) || (ft_isdigit(str[i]) && flag == 1))
		{
			if (str[i] == ' ' && flag == 0)
				flag = 1;
			else
				return (-1);
		}
		i++;
	}
	return (0);
}

int	atoi_strict(char *str)
{
	int		iter;
	long	value;
	int		divider;

	value = 0;
	iter = 0;
	divider = 1;
	if (validate_input(str) == -1)
		return (-1);
	while ((str[iter] >= 9 && str[iter] <= 13) || str[iter] == 32)
		iter++;
	if (!is_valid_number(str + iter))
		return (-1);
	return (looper(iter, (char *)str, value, divider));
}
