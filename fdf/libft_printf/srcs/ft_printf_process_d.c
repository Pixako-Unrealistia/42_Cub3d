/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process_d.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:25:27 by tnualman          #+#    #+#             */
/*   Updated: 2023/01/20 20:42:20 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_printf_process_d_flag_plus(char *str,
				t_format_info *p_format_info);

char	*ft_printf_process_d(va_list args, t_format_info *p_format_info)
{
	ssize_t	value;
	char	*str;

	if (p_format_info->flag_long < 1)
		value = va_arg(args, signed int);
	else if (p_format_info->flag_long == 1)
		value = va_arg(args, signed long);
	else
		value = va_arg(args, signed long long);
	str = ft_signed_tostr_base10(value);
	str = ft_printf_process_int_precision(str, p_format_info);
	str = ft_printf_process_d_flag_plus(str, p_format_info);
	str = ft_printf_process_width(str, p_format_info);
	return (str);
}

static char	*ft_printf_process_d_flag_plus(char *str,
				t_format_info *p_format_info)
{
	char	*newstr;
	int		len;

	if (!str || str[0] == '-' || str[0] == '\0'
		|| !(p_format_info->flag_plus || p_format_info->flag_space))
		return (str);
	len = ft_strlen(str);
	newstr = ft_calloc(sizeof(char), len + 2);
	if (!newstr)
	{
		free(str);
		return (NULL);
	}
	if (p_format_info->flag_plus)
		newstr[0] = '+';
	else
		newstr[0] = ' ';
	ft_memmove(newstr + 1, str, len);
	free(str);
	return (newstr);
}
