/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_colourful.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <schongte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:58:14 by schongte          #+#    #+#             */
/*   Updated: 2024/07/12 13:58:14 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	print_red(char *str)
{
	ft_printf("\033[0;31m%s\033[0m\n", str);
}

void	print_green(char *str)
{
	ft_printf("\033[0;32m%s\033[0m\n", str);
}

void	print_yellow(char *str)
{
	ft_printf("\033[0;33m%s\033[0m\n", str);
}

void	print_blue(char *str)
{
	ft_printf("\033[0;34m%s\033[0m\n", str);
}

void	print_magenta(char *str)
{
	ft_printf("\033[0;35m%s\033[0m\n", str);
}

void	print_cyan(char *str)
{
	ft_printf("\033[0;36m%s\033[0m\n", str);
}
