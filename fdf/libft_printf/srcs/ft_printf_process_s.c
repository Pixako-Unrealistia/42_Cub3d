/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process_s.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:10:07 by tnualman          #+#    #+#             */
/*   Updated: 2023/01/21 16:32:33 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_printf_process_s_precision(char *str,
				t_format_info *p_format_info, int is_null_string);

char	*ft_printf_process_s(char *s, t_format_info *p_format_info)
{
	char	*str;
	int		is_null_string;

	is_null_string = 0;
	if (s)
		str = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	else
	{
		str = ft_calloc(sizeof(char), S_NULL_L + 1);
		is_null_string = 1;
	}
	if (!str)
		return (NULL);
	if (s)
		ft_memmove(str, s, ft_strlen(s));
	else
		ft_memmove(str, S_NULL, S_NULL_L);
	str = ft_printf_process_s_precision(str, p_format_info, is_null_string);
	str = ft_printf_process_width(str, p_format_info);
	return (str);
}

static char	*ft_printf_process_s_precision(char *str,
				t_format_info *p_format_info, int is_null_string)
{
	char	*newstr;

	if (!str || !p_format_info->flag_dot)
		return (str);
	if (p_format_info->precision == 0 || (is_null_string && IS_LINUX
			&& p_format_info->precision < S_NULL_L))
		newstr = ft_calloc(sizeof(char), 1);
	else
		newstr = ft_substr(str, 0, p_format_info->precision);
	free(str);
	return (newstr);
}
