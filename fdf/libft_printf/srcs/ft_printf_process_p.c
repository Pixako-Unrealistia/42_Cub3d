/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process_p.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:52:51 by tnualman          #+#    #+#             */
/*   Updated: 2023/01/22 15:10:10 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_printf_process_p_add0x(char *str);

char	*ft_printf_process_p(size_t ptr, t_format_info *p_format_info)
{
	char	*str;

	if (ptr || !IS_LINUX)
	{
		str = ft_unsigned_tostr_base16(ptr);
		str = ft_printf_process_int_precision(str, p_format_info);
		str = ft_printf_process_p_add0x(str);
	}
	else
	{
		str = ft_calloc(sizeof(char), P_NULL_L + 1);
		if (!str)
			return (NULL);
		ft_memmove(str, P_NULL, P_NULL_L);
	}
	str = ft_printf_process_width(str, p_format_info);
	return (str);
}

static char	*ft_printf_process_p_add0x(char *str)
{
	char	*newstr;
	int		len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	newstr = ft_calloc(sizeof(char), len + 3);
	if (!newstr)
	{
		free(str);
		return (NULL);
	}
	newstr[0] = '0';
	newstr[1] = 'x';
	ft_memmove(newstr + 2, str, len);
	free(str);
	return (newstr);
}
