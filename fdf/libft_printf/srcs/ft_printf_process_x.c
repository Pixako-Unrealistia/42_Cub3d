/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process_x.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:42:30 by tnualman          #+#    #+#             */
/*   Updated: 2023/01/20 20:54:41 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_printf_process_x_flag_hash(char *str,
				t_format_info *p_format_info);

char	*ft_printf_process_x(va_list args, t_format_info *p_format_info)
{
	size_t	value;
	char	*str;
	int		i;

	if (p_format_info->flag_long < 1)
		value = va_arg(args, unsigned int);
	else if (p_format_info->flag_long == 1)
		value = va_arg(args, unsigned long);
	else
		value = va_arg(args, unsigned long long);
	str = ft_unsigned_tostr_base16(value);
	if (p_format_info->specifier == 'X')
	{
		i = -1;
		while (str[++i])
			str[i] = ft_toupper(str[i]);
	}
	str = ft_printf_process_int_precision(str, p_format_info);
	str = ft_printf_process_x_flag_hash(str, p_format_info);
	str = ft_printf_process_width(str, p_format_info);
	return (str);
}

static char	*ft_printf_process_x_flag_hash(char *str,
				t_format_info *p_format_info)
{
	char	*newstr;
	int		len;

	if (!str || !p_format_info->flag_hash || str[0] == '0' || str[0] == '\0')
		return (str);
	len = ft_strlen(str);
	newstr = ft_calloc(sizeof(char), len + 3);
	if (!newstr)
	{
		free(str);
		return (NULL);
	}
	newstr[0] = '0';
	if (p_format_info->specifier == 'x')
		newstr[1] = 'x';
	else
		newstr[1] = 'X';
	ft_memmove(newstr + 2, str, len);
	free(str);
	return (newstr);
}
