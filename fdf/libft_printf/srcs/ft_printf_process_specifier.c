/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process_specifier.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:41:51 by tnualman          #+#    #+#             */
/*   Updated: 2023/01/22 15:26:18 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_printf_process_specifier(va_list args, t_format_info *p_format_info)
{
	char	*str;

	if (p_format_info->specifier == 's')
		str = ft_printf_process_s(va_arg(args, char *), p_format_info);
	else if (p_format_info->specifier == 'p')
		str = ft_printf_process_p((unsigned long long)va_arg(args, void *),
				p_format_info);
	else if (p_format_info->specifier == 'd' || p_format_info->specifier == 'i')
		str = ft_printf_process_d(args, p_format_info);
	else if (p_format_info->specifier == 'u')
		str = ft_printf_process_u(args, p_format_info);
	else if (p_format_info->specifier == 'x' || p_format_info->specifier == 'X')
		str = ft_printf_process_x(args, p_format_info);
	else
		str = ft_calloc(sizeof(char), 1);
	return (str);
}
