/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_reader.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:44:53 by schongte          #+#    #+#             */
/*   Updated: 2024/07/15 20:12:20 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_texture_parser(t_parser *parser, char *line, char **texture)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*texture != NULL)
		ft_throw("Texture already realised", parser, line);
	line[ft_strlen(line) - 2] = '\0';
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	while (line[i + j] != '\0')
		j++;
	*texture = malloc(sizeof(char) * (j + 1));
	j = 0;
	while (line[i + j] != '\0')
	{
		(*texture)[j] = line[i + j];
		j++;
	}
	(*texture)[j] = '\0';
}

int	ft_header_parser(t_parser *parser, char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		ft_texture_parser(parser, line, &parser->map.no);
	else if (line[0] == 'S' && line[1] == 'O')
		ft_texture_parser(parser, line, &parser->map.so);
	else if (line[0] == 'W' && line[1] == 'E')
		ft_texture_parser(parser, line, &parser->map.we);
	else if (line[0] == 'E' && line[1] == 'A')
		ft_texture_parser(parser, line, &parser->map.ea);
	else if (line[0] == 'F')
		ft_color_parser(parser, line, &parser->map.f);
	else if (line[0] == 'C')
		ft_color_parser(parser, line, &parser->map.c);
	else if (line[0] == '\n')
		return (1);
	else if (line[0] == '\r')
		return (1);
	else if (line[0] == '\0')
		return (0);
	else
		return (0);
	return (1);
}

void	find_starting_position(t_parser *parser, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_strchr("NSEW", line[i]) != NULL)
		{
			if (parser->map.start_x != -1 || parser->map.start_y != -1)
			{
				printf("Encountered %s\n", line);
				printf("Found first at x: %d y: %d\n",
					parser->map.start_x, parser->map.start_y);
				ft_throw("Multiple starting positions", parser, line);
			}
			parser->map.start_x = i;
			parser->map.start_y = parser->map.height;
			parser->map.start_dir = line[i];
		}
		if (ft_strchr("01dNSEW \n\r", line[i]) == NULL)
		{
			printf("line[%d] : >\033[31m%c\033[0m<\n", i, line[i]);
			ft_throw("Invalid character in map", parser, line);
		}
		i++;
	}
}

void	map_reader_tmp(t_parser *parser, int line_len)
{
	char	**tmp;
	int		i;

	tmp = malloc(sizeof(char *) * (parser->map.height + 2));
	if (tmp == NULL)
		ft_throw("Memory allocation failed", parser, parser->line);
	i = 0;
	while (i < parser->map.height)
	{
		tmp[i] = parser->map.map[i];
		i++;
	}
	tmp[parser->map.height] = malloc(sizeof(char) * line_len + 1);
	if (tmp[parser->map.height] == NULL)
		ft_throw("Memory allocation failed", parser, parser->line);
	tmp[parser->map.height][line_len] = '\0';
	tmp[parser->map.height + 1] = NULL;
	free(parser->map.map);
	parser->map.map = tmp;
}

void	ft_map_reader(t_parser *parser)
{
	int		line_len;

	line_len = ft_strlen_nonl(parser->line);
	if (parser->map_alloc == 0)
		ft_map_alloc(parser, line_len);
	else
	{
		map_reader_tmp(parser, line_len);
		parser->map_alloc = 1;
	}
	if (parser->map.map[parser->map.height] != NULL)
	{
		free(parser->map.map[parser->map.height]);
		parser->map.map[parser->map.height] = NULL;
	}
	parser->map.map[parser->map.height] = ft_strdup(parser->line);
	parser->map.map[parser->map.height + 1] = NULL;
	parser->map.height++;
	if (parser->map.width < line_len)
		parser->map.width = line_len;
	find_starting_position(parser, parser->line);
}
