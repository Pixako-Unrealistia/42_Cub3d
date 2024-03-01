/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:22:04 by schongte          #+#    #+#             */
/*   Updated: 2023/04/04 20:22:06 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_string(unsigned long value, int *strlen)
{
	int				counter;
	unsigned long	tempo;
	char			*str;

	counter = 0;
	tempo = value;
	while (tempo != 0)
	{
		tempo = tempo / 16;
		counter++;
	}
	str = calloc(counter + 1, sizeof(char));
	*strlen = counter - 1;
	return (str);
}

int	print_ptr(unsigned long value, int asc)
{
	unsigned long	tempval;
	char			*printout;
	int				counter;
	int				*iptr;

	iptr = &counter;
	tempval = value;
	printout = create_string(value, iptr);
	if (!printout)
		return (0);
	while (tempval != 0 && counter >= 0)
	{
		printout[counter] = util_hex_ascii(tempval, asc);
		tempval = tempval / 16;
		counter--;
	}
	counter = ft_strlen(printout);
	counter = counter + print_str("0x");
	ft_putstr_fd(printout, 1);
	free(printout);
	if (value == 0)
		counter += print_char('0');
	return (counter);
}
