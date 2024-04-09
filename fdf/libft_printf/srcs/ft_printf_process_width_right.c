/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process_width_right.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:39:06 by tnualman          #+#    #+#             */
/*   Updated: 2023/01/20 23:32:21 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_printf_process_width_fill_zeroes(char *str,
				t_format_info *p_format_info);
static char	*ft_printf_process_width_fill_spaces(char *str,
				t_format_info *p_format_info);

char	*ft_printf_process_width_right(char *str,
				t_format_info *p_format_info)
{
	if (!str)
		return (NULL);
	if (p_format_info->flag_zero && !p_format_info->flag_dot
		&& (p_format_info->specifier == 'd'
			|| p_format_info->specifier == 'i'
			|| p_format_info->specifier == 'u'
			|| p_format_info->specifier == 'x'
			|| p_format_info->specifier == 'X'
			|| p_format_info->specifier == 'p'))
		str = ft_printf_process_width_fill_zeroes(str, p_format_info);
	else
		str = ft_printf_process_width_fill_spaces(str, p_format_info);
	return (str);
}

static char	*ft_printf_process_width_fill_zeroes(char *str,
				t_format_info *p_format_info)
{
	char	*newstr;
	int		i[2];

	if (!str)
		return (NULL);
	i[0] = 0;
	if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
		i[0] = 1;
	else if (str[0] == '0')
	{
		if (str[1] == 'x' || str[1] == 'X')
			i[0] = 2;
	}
	i[1] = i[0] + p_format_info->width - ft_strlen(str);
	newstr = ft_calloc(sizeof(char), p_format_info->width + 1);
	if (!newstr)
	{
		free(str);
		return (NULL);
	}
	ft_memmove(newstr, str, i[0]);
	ft_memset(newstr + i[0], '0', i[1] - i[0]);
	ft_memmove(newstr + i[1], str + i[0], ft_strlen(str) - i[0]);
	free(str);
	return (newstr);
}

static char	*ft_printf_process_width_fill_spaces(char *str,
				t_format_info *p_format_info)
{
	char	*newstr;
	int		len;

	if (!str)
		return (NULL);
	newstr = ft_calloc(sizeof(char), p_format_info->width + 1);
	if (!newstr)
	{
		free(str);
		return (NULL);
	}
	len = ft_strlen(str);
	ft_memset(newstr, ' ', p_format_info->width - len);
	ft_memmove(newstr + p_format_info->width - len, str, len);
	free(str);
	return (newstr);
}
