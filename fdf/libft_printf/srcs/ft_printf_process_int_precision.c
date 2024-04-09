/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process_int_precision.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:34:38 by tnualman          #+#    #+#             */
/*   Updated: 2023/08/31 19:40:20 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_printf_process_int_precision_fill(char *str, int precision);

char	*ft_printf_process_int_precision(char *str,
				t_format_info *p_format_info)
{
	if (!str || !p_format_info->flag_dot)
		return (str);
	if (str[0] == '0' && p_format_info->precision == 0)
	{
		free(str);
		str = ft_calloc(sizeof(char), 1);
		return (str);
	}
	if (p_format_info->precision > ft_strlen(str)
		|| (str[0] == '-'
			&& p_format_info->precision > ft_strlen(str) - 1))
		str = ft_printf_process_int_precision_fill(str,
				p_format_info->precision);
	return (str);
}

static char	*ft_printf_process_int_precision_fill(char *str, int precision)
{
	char	*newstr;
	int		len;
	int		i[2];

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	i[0] = 0;
	if (str[0] == '-')
		i[0] = 1;
	newstr = ft_calloc(sizeof(char), precision + 1 + i[0]);
	if (!newstr)
	{
		free(str);
		return (NULL);
	}
	if (i[0])
		newstr[0] = '-';
	i[1] = i[0];
	while (i[1] < precision - len + 2 * i[0])
		newstr[i[1]++] = '0';
	ft_memmove(newstr + precision - len + 2 * i[0], str + i [0], len - i[0]);
	free(str);
	return (newstr);
}
