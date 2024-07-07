/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:08:55 by tnualman          #+#    #+#             */
/*   Updated: 2024/07/07 21:24:40 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* For INT_MIN (-2147483648), this function returns INT_MIN itself.
 */
int	ft_abs_int(int value)
{
	if (value < 0 && value > -2147483648)
		value *= -1;
	return (value);
}

int	diy_int_sign(int value)
{
	if (value > 0)
		return (1);
	if (value < 0)
		return (-1);
	return (0);
}
