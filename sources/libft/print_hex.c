/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:57:24 by schongte          #+#    #+#             */
/*   Updated: 2023/04/04 20:57:27 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_string(unsigned int value, int *strlen)
{
	int				counter;
	unsigned int	tempo;
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

int	print_hex(unsigned int value, int asc)
{
	unsigned int	tempval;
	char			*printout;
	int				counter;
	int				*iptr;

	iptr = &counter;
	tempval = value;
	printout = create_string(value, iptr);
	if (!printout)
		return (0);
	while (tempval != 0)
	{
		printout[counter] = util_hex_ascii(tempval, asc);
		tempval = tempval / 16;
		counter--;
	}
	ft_putstr_fd(printout, 1);
	counter = ft_strlen(printout);
	free(printout);
	if (value == 0)
		counter += print_char('0');
	return (counter);
}
