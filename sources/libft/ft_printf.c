/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:26:24 by schongte          #+#    #+#             */
/*   Updated: 2023/04/04 20:24:26 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static int	em_switch(const char *input, va_list args)
{
	int	tempo;

	tempo = 0;
	if (*input == 'c')
		tempo += print_char(va_arg(args, int));
	else if (*input == 's')
		tempo += print_str(va_arg(args, char *));
	else if (*input == 'p')
		tempo += print_ptr(va_arg(args, unsigned long), 87);
	else if (*input == 'd')
		tempo += print_int(va_arg(args, int));
	else if (*input == 'i')
		tempo += print_int(va_arg(args, int));
	else if (*input == 'u')
		tempo += print_usn(va_arg(args, unsigned int));
	else if (*input == 'x')
		tempo += print_hex(va_arg(args, unsigned int), 87);
	else if (*input == 'X')
		tempo += print_hex(va_arg(args, unsigned int), 55);
	else if (*input == '%')
		tempo += print_char('%');
	return (tempo);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		tempo;

	tempo = 0;
	va_start(args, input);
	while (*input != '\0')
	{
		if (*input == '%')
		{
			input++;
			tempo = tempo + em_switch(input, args);
		}
		else
			tempo = tempo + print_char(*input);
		input++;
	}
	va_end(args);
	return (tempo);
}
