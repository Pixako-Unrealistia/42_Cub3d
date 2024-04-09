/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:06:24 by tnualman          #+#    #+#             */
/*   Updated: 2023/01/21 16:36:37 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void		ft_printf_resetinfo(t_format_info *p_format_info);
int			ft_printf_setinfo(char c, va_list args,
				t_format_info *p_format_info);
static int	ft_printf_setinfo_star(char c, va_list args,
				t_format_info *p_format_info);

void	ft_printf_resetinfo(t_format_info *p_format_info)
{
	p_format_info->specifier = 0;
	p_format_info->precision = 0;
	p_format_info->width = 0;
	p_format_info->flag_long = 0;
	p_format_info->flag_hash = 0;
	p_format_info->flag_space = 0;
	p_format_info->flag_plus = 0;
	p_format_info->flag_minus = 0;
	p_format_info->flag_zero = 0;
	p_format_info->flag_dot = 0;
	p_format_info->flag_unused = 0;
}

int	ft_printf_setinfo(char c, va_list args, t_format_info *p_format_info)
{
	if (ft_printf_setinfo_star(c, args, p_format_info))
		return (1);
	else if (p_format_info->flag_dot && ft_isdigit(c))
		p_format_info->precision = (p_format_info->precision * 10) + (c - '0');
	else if (ft_strchr(L_SPECIFIER, c))
		p_format_info->specifier = c;
	else if (c == 'l')
		p_format_info->flag_long++;
	else if (c == '-')
		p_format_info->flag_minus = 1;
	else if (c == '+')
		p_format_info->flag_plus = 1;
	else if (c == ' ')
		p_format_info->flag_space = 1;
	else if (c == '0' && p_format_info->width == 0)
		p_format_info->flag_zero = 1;
	else if (c == '#')
		p_format_info->flag_hash = 1;
	else if (c == '.')
		p_format_info->flag_dot = 1;
	else if (ft_isdigit(c))
		p_format_info->width = (p_format_info->width * 10) + (c - '0');
	else
		return (0);
	return (1);
}

int	ft_printf_setinfo_star(char c, va_list args, t_format_info *p_format_info)
{
	int	value;

	if (c != '*')
		return (0);
	value = va_arg(args, int);
	if (p_format_info->flag_dot)
	{
		if (value < 0)
			p_format_info->flag_dot = 0;
		else
			p_format_info->precision = value;
	}
	else
	{
		if (value < 0)
		{
			p_format_info->flag_minus = 1;
			value *= -1;
		}
		p_format_info->width = value;
	}
	return (1);
}
