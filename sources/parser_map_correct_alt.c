/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_correct_alt.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:42:38 by schongte          #+#    #+#             */
/*   Updated: 2024/07/23 16:32:32 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	alt_fill(t_parser *parser, int x, int y)
{
	printf("x = %d, y = %d\n", x, y);
	if (x < 0 || x >= parser->map.height || y < 0 || y >= parser->map.width)
		return ;
	if (ft_strchr("d1", parser->map.map[x][y]) != NULL)
		return ;
	printf("map[x][y] = %d %d\n", x, y);
	if (x == 0 && parser->map.map[x][y] != '1')
		ft_throw("Map is not surrounded by walls", parser, NULL);
	if (x == parser->map.height - 1 && parser->map.map[x][y] != '1')
		ft_throw("Map is not surrounded by walls", parser, NULL);
	if (y == 0 && parser->map.map[x][y] != '1')
		ft_throw("Map is not surrounded by walls", parser, NULL);
	if (y == parser->map.width - 2 && parser->map.map[x][y] != '1')
		ft_throw("Map is not surrounded by walls", parser, NULL);
	parser->map.map[x][y] = 'd';
	flood_fill(parser, x + 1, y);
	flood_fill(parser, x - 1, y);
	flood_fill(parser, x, y + 1);
	flood_fill(parser, x, y - 1);
}

void	fill_from_start(t_parser *parser)
{
	printf("start_x = %d, start_y = %d\n", parser->map.start_x,
		parser->map.start_y);
	printf("map[start_x][start_y] = %c\n",
		parser->map.map[parser->map.start_y][parser->map.start_x]);
	alt_fill(parser, parser->map.start_x, parser->map.start_y);
}
