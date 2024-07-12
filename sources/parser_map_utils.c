/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:21:24 by schongte          #+#    #+#             */
/*   Updated: 2024/07/07 21:55:02 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_map_free(t_parser *parser)
{
	int	i;

	i = 0;
	if (parser->map.map)
	{
		while (parser->map.map[i] != NULL)
		{
			free(parser->map.map[i]);
			i++;
		}
		free(parser->map.map);
		parser->map.map = NULL;
	}
	ft_safe_free(parser->map.no);
	ft_safe_free(parser->map.so);
	ft_safe_free(parser->map.we);
	ft_safe_free(parser->map.ea);
	ft_safe_free(parser->map.f);
	ft_safe_free(parser->map.c);
	parser->map.height = 0;
	parser->map.width = 0;
	parser->map_alloc = 0;
}

void	ft_throw(char *str, t_parser *parser, char *free_me)
{
	ft_printf("Error\n%s\n", str);
	if (free_me != NULL)
		free (free_me);
	ft_map_free(parser);
	if (parser->fd != -1)
	{
		while (super_get_next_line(parser->fd, &parser->line) > 0)
			free (parser->line);
		free (parser->line);
		close (parser->fd);
	}
	exit(0);
}

void	ft_safe_free(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	ft_init_all(t_parser *parser)
{
	parser->map.height = 0;
	parser->map.width = 0;
	parser->map.no = NULL;
	parser->map.so = NULL;
	parser->map.we = NULL;
	parser->map.ea = NULL;
	parser->map.f = NULL;
	parser->map.c = NULL;
	parser->map.map = NULL;
	parser->map_alloc = 0;
	parser->line = NULL;
	parser->fd = -1;
	parser->map.start_x = -1;
	parser->map.start_y = -1;
	parser->map.start_dir = '0';
}
