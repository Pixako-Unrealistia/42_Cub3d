/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:21:24 by schongte          #+#    #+#             */
/*   Updated: 2024/07/07 21:55:02 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_map_free(t_parser *parser)
{
	if (parser->map.map) {
		for (int i = 0; i < parser->map.height; i++) {
			if (parser->map.map[i] != NULL) {
				free(parser->map.map[i]);
			}
		}
		free(parser->map.map);
		parser->map.map = NULL;
	}
	if (parser->map.no != NULL)
		free(parser->map.no);
	if (parser->map.so != NULL)
		free(parser->map.so);
	if (parser->map.we != NULL)
		free(parser->map.we);
	if (parser->map.ea != NULL)
		free(parser->map.ea);
	if (parser->map.f != NULL)
		free(parser->map.f);
	if (parser->map.c != NULL)
		free(parser->map.c);
	parser->map_alloc = 0;
}

void	ft_throw(char *str,t_parser *parser, char *free_me)
{
	ft_printf("Error\n%s\n", str);
	if (free_me != NULL)
		free(free_me);
	ft_map_free(parser);
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
	parser->error = NULL;
}
