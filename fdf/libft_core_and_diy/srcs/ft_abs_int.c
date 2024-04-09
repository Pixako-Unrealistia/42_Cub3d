/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:37:53 by tnualman          #+#    #+#             */
/*   Updated: 2023/10/14 12:00:15 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* For INT_MIN (-2147483648), this function returns INT_MIN itself.
 */

int	ft_abs_int(int value)
{
	if (value < 0 && value > -2147483648)
		value *= -1;
	return (value);
}
