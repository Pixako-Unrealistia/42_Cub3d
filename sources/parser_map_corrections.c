/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_corrections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <schongte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:42:38 by schongte          #+#    #+#             */
/*   Updated: 2024/07/10 17:42:38 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void flood_fill(t_parser *parser, int x, int y)
{
	if (x < 0 || x >= parser->map.height || y < 0 || y >= parser->map.width)
		return;
	if (parser->map.map[x][y] == '0')
		ft_throw("Map is not surrounded by walls", parser, NULL);
	if (parser->map.map[x][y] != ' ')
		return;
	parser->map.map[x][y] = 'd';
	flood_fill(parser, x + 1, y);
	flood_fill(parser, x - 1, y);
	flood_fill(parser, x, y + 1);
	flood_fill(parser, x, y - 1);
}

void util_irregular(t_parser *parser, int i, int j)
{
	if (parser->map.map[i][j] == '0')
		ft_throw("Map is not surrounded by walls", parser, NULL);
	if (parser->map.map[i][j] == ' ')
		flood_fill(parser, i, j);
}

void fill_irregular_map(t_parser *parser)
{
	int i = 0;

	// flood fill from top edges
	i = 0;
	while (i < parser->map.width)
	{
		util_irregular(parser, 0, i);
		i++;
	}

	// flood fill from bottom edges
	i = 0;
	while (i < parser->map.width)
	{
		util_irregular(parser, parser->map.height - 1, i);
		i++;
	}

	// flood fill from left edges
	i = 0;
	while (i < parser->map.height)
	{
		util_irregular(parser, i, 0);
		i++;
	}

	// flood fill from right edges
	i = 0;
	while (i < parser->map.height)
	{
		util_irregular(parser, i, parser->map.width - 2);
		i++;
	}
}

void width_realloc(t_parser *parser)
{
	int initial_width = 0;
	for (int i = 0; i < parser->map.height; i++)
	{
		//print width and actual width
		printf("line : %s\n", parser->map.map[i]);
		printf("actual width : %d ", ft_strlen_nonl(parser->map.map[i]));
		printf("max width : %d\n", parser->map.width);
		
		initial_width = ft_strlen_nonl(parser->map.map[i]);

		//if the actual width is less than the max width, realloc the line
		if (initial_width != parser->map.width)
		{
			char *tmp = malloc(sizeof(char) * (parser->map.width + 1));
			int j = 0;
			while (j < initial_width)
			{
				tmp[j] = parser->map.map[i][j];
				j++;
			}
			while (j < parser->map.width)
			{
				tmp[j] = 'd';
				j++;
			}
			tmp[parser->map.width] = '\0';
			free(parser->map.map[i]);
			parser->map.map[i] = malloc(sizeof(char) * (parser->map.width));
			ft_strlcpy(parser->map.map[i], tmp, parser->map.width);
			free(tmp);
		}
		else if (initial_width == parser->map.width)
		{
			parser->map.map[i][parser->map.width] = '\0';
		}
	}
}
