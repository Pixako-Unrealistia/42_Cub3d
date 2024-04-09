/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process_c.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:32:14 by tnualman          #+#    #+#             */
/*   Updated: 2023/01/22 15:24:31 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_printf_process_c(char c, t_format_info *p_format_info)
{
	unsigned int	i;
	char			fill;

	if (p_format_info->specifier == '%' && IS_LINUX)
		p_format_info->width = 1;
	if (p_format_info->width == 0)
		p_format_info->width++;
	fill = ' ';
	if (p_format_info->specifier == '%' && p_format_info->flag_zero)
		fill = '0';
	i = 0;
	if (p_format_info->flag_minus)
	{
		ft_putchar_fd(c, 1);
		while (i++ < p_format_info->width - 1)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (i++ < p_format_info->width - 1)
			ft_putchar_fd(fill, 1);
		ft_putchar_fd(c, 1);
	}
	return (p_format_info->width);
}
