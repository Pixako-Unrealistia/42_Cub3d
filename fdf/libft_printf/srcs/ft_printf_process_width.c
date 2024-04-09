/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process_width.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:37:09 by tnualman          #+#    #+#             */
/*   Updated: 2023/01/19 19:05:39 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_printf_process_width(char *str, t_format_info *p_format_info)
{
	if (!str || p_format_info->width <= ft_strlen(str))
		return (str);
	if (p_format_info->flag_minus)
		str = ft_printf_process_width_left(str, p_format_info);
	else
		str = ft_printf_process_width_right(str, p_format_info);
	return (str);
}
