/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:19:59 by schongte          #+#    #+#             */
/*   Updated: 2023/04/04 21:33:22 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *input, ...);
int		print_ptr(unsigned long value, int asc);
int		print_usn(unsigned int nb);
int		print_str(char *s);
int		print_int(int n);
int		print_char(char c);
int		print_hex(unsigned int value, int asc);
int		util_hex_ascii(unsigned int tempval, int asc);

#endif
