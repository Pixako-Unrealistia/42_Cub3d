/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:32:51 by tnualman          #+#    #+#             */
/*   Updated: 2023/08/31 19:39:03 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>

# ifdef __linux__
#  define IS_LINUX 1
#  define S_NULL "(null)"
#  define S_NULL_L 6
#  define P_NULL "(nil)"
#  define P_NULL_L 5
# else
#  define IS_LINUX 0
#  define S_NULL "(null)"
#  define S_NULL_L 6
#  define P_NULL "0x0"
#  define P_NULL_L 3
# endif

# define L_SPECIFIER "cspdiuxX%"

typedef struct s_format_info
{
	char			specifier;
	unsigned int	precision;
	unsigned int	width;
	unsigned int	flag_long;
	unsigned int	flag_hash:1;
	unsigned int	flag_space:1;
	unsigned int	flag_plus:1;
	unsigned int	flag_minus:1;
	unsigned int	flag_zero:1;
	unsigned int	flag_dot:1;
	unsigned int	flag_unused:10;
}					t_format_info;

int		ft_printf(const char *format, ...);

void	ft_printf_resetinfo(t_format_info *p_format_info);
int		ft_printf_setinfo(char c, va_list args, t_format_info *p_format_info);

char	*ft_printf_process_specifier(va_list args,
			t_format_info *p_format_info);

int		ft_printf_process_c(char c, t_format_info *p_format_info);
char	*ft_printf_process_d(va_list args, t_format_info *p_format_info);
char	*ft_printf_process_p(size_t ptr, t_format_info *p_format_info);
char	*ft_printf_process_s(char *s, t_format_info *p_format_info);
char	*ft_printf_process_u(va_list args, t_format_info *p_format_info);
char	*ft_printf_process_x(va_list args, t_format_info *p_format_info);

char	*ft_printf_process_int_precision(char *str,
			t_format_info *p_format_info);

char	*ft_printf_process_width(char *str, t_format_info *p_format_info);
char	*ft_printf_process_width_left(char *str,
			t_format_info *p_format_info);
char	*ft_printf_process_width_right(char *str,
			t_format_info *p_format_info);

char	*ft_signed_tostr_base10(ssize_t n);
char	*ft_strrev(char *s);
char	*ft_unsigned_tostr_base10(size_t n);
char	*ft_unsigned_tostr_base16(size_t n);

int		ft_dprintf(int fd, const char *format, ...);
int		ft_dprintf_process_c(int fd, char c, t_format_info *p_format_info);

#endif