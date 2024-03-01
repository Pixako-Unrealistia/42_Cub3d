/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:57:09 by schongte          #+#    #+#             */
/*   Updated: 2023/04/06 01:36:53 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printout(unsigned int nb)
{
	if (nb > 9)
		print_usn(nb / 10);
	if (nb <= 9)
	{
		ft_putchar_fd(nb + 48, 1);
		return ;
	}
	ft_putchar_fd((nb % 10) + 48, 1);
}

int	print_usn(unsigned int nb)
{
	unsigned int	counter;

	printout(nb);
	counter = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		counter++;
	}
	return (counter);
}
