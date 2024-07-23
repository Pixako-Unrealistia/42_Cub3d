/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_corrections.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:42:38 by schongte          #+#    #+#             */
/*   Updated: 2024/07/23 18:34:04 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	flood_fill(t_parser *parser, int x, int y)
{
	if (x < 0 || x >= parser->map.height || y < 0 || y >= parser->map.width)
		return ;
	if (parser->map.map[x][y] == '0')
		ft_throw("Map is not surrounded by walls", parser, NULL);
	if (parser->map.map[x][y] != ' ')
		return ;
	parser->map.map[x][y] = 'd';
	flood_fill(parser, x + 1, y);
	flood_fill(parser, x - 1, y);
	flood_fill(parser, x, y + 1);
	flood_fill(parser, x, y - 1);
}

void	util_irregular(t_parser *parser, int i, int j)
{
	if (parser->map.map[i][j] == '0')
		ft_throw("Map is not surrounded by walls", parser, NULL);
	if (parser->map.map[i][j] == ' ')
		flood_fill(parser, i, j);
}

void	fill_irregular_map(t_parser *parser)
{
	int	i;

	i = 0;
	parser->map.map[parser->map.start_y][parser->map.start_x] = '0';
	while (i < parser->map.width)
		util_irregular(parser, 0, i++);
	i = 0;
	while (i < parser->map.width)
		util_irregular(parser, parser->map.height - 1, i++);
	i = 0;
	while (i < parser->map.height)
		util_irregular(parser, i++, 0);
	i = 0;
	while (i < parser->map.height)
		util_irregular(parser, i++, parser->map.width - 1);
}

void	width_utils(t_parser *parser, t_for_loop f, int initial_width)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (parser->map.width + 1));
	while (f.j < initial_width)
	{
		tmp[f.j] = parser->map.map[f.i][f.j];
		f.j++;
	}
	while (f.j < parser->map.width)
	{
		tmp[f.j] = ' ';
		f.j++;
	}
	tmp[parser->map.width] = '\0';
	free(parser->map.map[f.i]);
	parser->map.map[f.i] = malloc(sizeof(char) * (parser->map.width + 1));
	ft_strlcpy(parser->map.map[f.i], tmp, parser->map.width + 1);
	free(tmp);
}

void	width_realloc(t_parser *parser)
{
	int			initial_width;
	t_for_loop	f;

	initial_width = 0;
	f.i = 0;
	while (f.i < parser->map.height)
	{
		initial_width = ft_strlen_nonl(parser->map.map[f.i]);
		if (initial_width != parser->map.width)
		{
			f.j = 0;
			width_utils(parser, f, initial_width);
		}
		else if (initial_width == parser->map.width)
			parser->map.map[f.i][parser->map.width] = '\0';
		f.i++;
	}
}
