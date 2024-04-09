/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process_u.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:31:33 by tnualman          #+#    #+#             */
/*   Updated: 2023/01/20 17:50:13 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_printf_process_u(va_list args, t_format_info *p_format_info)
{
	size_t	value;
	char	*str;

	if (p_format_info->flag_long < 1)
		value = va_arg(args, unsigned int);
	else if (p_format_info->flag_long == 1)
		value = va_arg(args, unsigned long);
	else
		value = va_arg(args, unsigned long long);
	str = ft_unsigned_tostr_base10(value);
	str = ft_printf_process_int_precision(str, p_format_info);
	str = ft_printf_process_width(str, p_format_info);
	return (str);
}
