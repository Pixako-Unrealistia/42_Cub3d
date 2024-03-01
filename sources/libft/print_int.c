/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfriedri <tfriedri@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:33:32 by tfriedri          #+#    #+#             */
/*   Updated: 2022/04/08 17:07:31 by tfriedri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int n)
{
	int				nb;
	unsigned int	counter;

	nb = n;
	counter = 1;
	if (n < 0 && n != -2147483648)
	{
		nb = -n;
		counter++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		counter++;
	}
	ft_putnbr_fd(n, 1);
	if (n == -2147483648)
		return (11);
	return (counter);
}
