/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process_width_left.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:37:46 by tnualman          #+#    #+#             */
/*   Updated: 2023/01/19 19:07:14 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_printf_process_width_left(char *str,
				t_format_info *p_format_info)
{
	char			*newstr;
	unsigned int	i;

	if (!str)
		return (NULL);
	newstr = ft_calloc(sizeof(char), p_format_info->width + 1);
	if (!newstr)
	{
		free(str);
		return (NULL);
	}
	i = ft_strlen(str);
	ft_memmove(newstr, str, i);
	while (i < p_format_info->width)
		newstr[i++] = ' ';
	free(str);
	return (newstr);
}
