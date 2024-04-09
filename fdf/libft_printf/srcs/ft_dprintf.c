/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:53:05 by tnualman          #+#    #+#             */
/*   Updated: 2023/08/31 19:34:05 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_dprintf_loop(int fd, const char **p_format, va_list args);
static int	ft_printf_getinfo(const char *format, va_list args,
				t_format_info *format_info);
static int	ft_dprintf_process_format(int fd, va_list args,
				t_format_info *p_format_info);

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		len_total;
	int		len;

	if (!format || !*format)
		return (0);
	va_start(args, format);
	len_total = 0;
	while (*format)
	{
		len = ft_dprintf_loop(fd, &format, args);
		if (len >= 0)
			len_total += len;
		else
			break ;
	}
	va_end(args);
	return (len_total);
}

static int	ft_dprintf_loop(int fd, const char **p_format, va_list args)
{
	t_format_info	format_info;
	int				len;
	int				len_info;

	if (**p_format != '%')
	{
		ft_putchar_fd(**p_format, fd);
		*p_format += 1;
		return (1);
	}
	else
	{
		len_info = ft_printf_getinfo(*p_format, args, &format_info);
		if (len_info > 1)
		{
			len = ft_dprintf_process_format(fd, args, &format_info);
			*p_format += len_info;
			return (len);
		}
		else
			return (-1);
	}
}

static int	ft_printf_getinfo(const char *format, va_list args,
				t_format_info *p_format_info)
{
	int		i;

	ft_printf_resetinfo(p_format_info);
	i = 1;
	while (format[i])
	{
		if (!ft_printf_setinfo(format[i], args, p_format_info))
			return (i);
		i++;
		if (p_format_info->specifier)
			return (i);
	}
	return (i);
}

static int	ft_dprintf_process_format(int fd, va_list args,
				t_format_info *p_format_info)
{
	char	*str;
	int		len;

	if (p_format_info->specifier == 'c')
		return (ft_dprintf_process_c(fd, va_arg(args, int), p_format_info));
	if (p_format_info->specifier == '%')
		return (ft_dprintf_process_c(fd, '%', p_format_info));
	str = ft_printf_process_specifier(args, p_format_info);
	if (!str)
		return (0);
	ft_putstr_fd(str, fd);
	len = ft_strlen(str);
	free(str);
	return (len);
}
