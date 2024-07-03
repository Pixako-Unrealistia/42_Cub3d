/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:59:17 by schongte          #+#    #+#             */
/*   Updated: 2024/07/03 18:20:43 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "prototype.h"  //DO NOT MOVE THIS IT WILL CAUSE ISSUE

// Seperate to initialise_map.c
//./cub3d ../maps/mandatory.cub
void	ft_map_alloc(t_parser *parser, size_t size)
{
	parser->map.map = malloc(sizeof(char *) * 2);
	if (parser->map.map == NULL)
	{
		ft_throw("Memory allocation failed", parser, NULL);
	}
	parser->map.map[0] = malloc(sizeof(char) * (size + 1));
	if (parser->map.map[0] == NULL)
	{
		ft_throw("Memory allocation failed", parser, NULL);
	}
	parser->map.map[0][size] = '\0';
	parser->map.map[1] = NULL;
	parser->map_alloc = 1;
}


void	ft_texture_parser(t_parser *parser, char *line, char **texture)
{
	int i = 0;
	int j = 0;
	char *tmp;

	if (*texture != NULL)
		ft_throw("Texture already realised", parser, line);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	while (line[i + j] != '\0')
		j++;
	tmp = malloc(sizeof(char) * (j + 1));
	j = 0;
	while (line[i + j] != '\0')
	{
		tmp[j] = line[i + j];
		j++;
	}
	tmp[j] = '\0';
	*texture = tmp;
}

void	ft_color_parser(t_parser *parser, char *line, int *color)
{
	int i = 0;
	int j = 0;
	int tmp;

	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	while (line[i + j] != '\0')
		j++;
	tmp = ft_atoi(&line[i]);
	if (tmp < 0 || tmp > 255)
		ft_throw("Invalid color range", parser, line);
	*color = tmp;
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
	{
		ft_printf(">%s<", line);
		//ft_throw("Invalid map parameter", parser, line);
		return (0);
	}
	return (1);
}

void	ft_find_starting_position(t_parser *parser, char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		{
			parser->map.start_x = i;
			parser->map.start_y = parser->map.height;
			parser->map.start_dir = line[i];
			return ;
		}
		i++;
	}
}

void	ft_map_reader(t_parser *parser, char *line)
{
	char	**tmp;
	int		i;

	//if (ft_strlen_nonl(line) == 0 && parser->map_alloc == 0)
	//	return ;
	if (parser->map_alloc == 0)
		ft_map_alloc(parser, ft_strlen_nonl(line));
	else
	{
		tmp = malloc(sizeof(char *) * (parser->map.height + 2));
		if (tmp == NULL)
			ft_throw("Memory allocation failed", parser, line);
		i = 0;
		while (i < parser->map.height)
		{
			tmp[i] = parser->map.map[i];
			i++;
		}
		tmp[parser->map.height] = malloc(sizeof(char) * (ft_strlen_nonl(line) + 1));
		if (tmp[parser->map.height] == NULL)
			ft_throw("Memory allocation failed", parser, line);
		tmp[parser->map.height][ft_strlen_nonl(line)] = '\0';
		tmp[parser->map.height + 1] = NULL;
		free(parser->map.map);
		parser->map.map = tmp;
	}

	if (parser->map.map[parser->map.height] != NULL)
	{
		free(parser->map.map[parser->map.height]);
		parser->map.map[parser->map.height] = NULL;
	}
	parser->map.map[parser->map.height] = ft_strdup(line);
	parser->map.map[parser->map.height + 1] = NULL;
	parser->map.height++;
	if (parser->map.width < ft_strlen_nonl(line))
		parser->map.width = ft_strlen_nonl(line);

	//THIS WHOLE FUNCTION WILL BE REWRITTEN HERE'S A BANDAGE
	//loop through ever char of line, if the char is NSEW, set the start_x and start_y
	ft_find_starting_position(parser, line);
}

// End of Seperation //
// Seperate to validate_map.c

void	ft_cube_argv(int argc, char **argv, t_parser *parser)
{
	int	map_parameter_len;

	parser->map_alloc = 0;
	if (argc != 2)
		ft_throw("Format : ./cub3d (map_path)", parser, NULL);
	map_parameter_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][map_parameter_len - 4], ".cub", 4))
		ft_throw("Expected .cub", parser, NULL);
}

void	ft_validate_texture(t_parser *parser)
{
	if (parser->map.no == NULL || parser->map.so == NULL || parser->map.we == NULL || parser->map.ea == NULL || parser->map.f == -1 || parser->map.c == -1)
		ft_throw("Missing texture", parser, NULL);
}

void ft_validate_containment(t_parser *parser)
{
	int i, j;
	for (i = 0; i < parser->map.height; i++)
	{
		if (parser->map.map[i][0] != '1' || parser->map.map[i][parser->map.width - 1] != '1')
			ft_throw("Map is not surrounded by walls", parser, NULL);
		for (j = 0; j < parser->map.width; j++)
		{
			char c = parser->map.map[i][j];
			if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W')
				ft_throw("Map contains invalid character", parser, NULL);
		}
	}
}

// End of Seperation //

void	ft_schongte(t_parser *parser)
{
	//print NO SO EA WE
	ft_printf("NO : %s", parser->map.no);
	ft_printf("SO : %s", parser->map.so);
	ft_printf("EA : %s", parser->map.ea);
	ft_printf("WE : %s", parser->map.we);
	////print F C
	ft_printf("F : %d\n", parser->map.f);
	ft_printf("C : %d\n", parser->map.c);
	ft_printf("start_x : %d\n", parser->map.start_x);
	ft_printf("start_y : %d\n", parser->map.start_y);
	ft_printf("start_dir : %c\n", parser->map.start_dir);
	//printf("line count : %d\n", i);
}

void flood_fill(char **map, int x, int y, int width, int height)
{
	if (x < 0 || x >= width || y < 0 || y >= height || map[y][x] != ' ')
		return;
	map[y][x] = 'd';
	flood_fill(map, x + 1, y, width, height);
	flood_fill(map, x - 1, y, width, height);
	flood_fill(map, x, y + 1, width, height);
	flood_fill(map, x, y - 1, width, height);
}

void fill_irregular_map(t_parser *parser)
{
	//flood fill from top edges
	for (int i = 0; i < parser->map.width; i++)
	{
		if (parser->map.map[0][i] == ' ')
			flood_fill(parser->map.map, i, 0, parser->map.width, parser->map.height);
	}
	//flood fill from bottom edges
	for (int i = 0; i < parser->map.width; i++)
	{
		if (parser->map.map[parser->map.height - 1][i] == ' ')
			flood_fill(parser->map.map, i, parser->map.height - 1, parser->map.width, parser->map.height);
	}
	//flood fill from left edges
	for (int i = 0; i < parser->map.height; i++)
	{
		if (parser->map.map[i][0] == ' ')
			flood_fill(parser->map.map, 0, i, parser->map.width, parser->map.height);
	}
	//flood fill from right edges
	for (int i = 0; i < parser->map.height; i++)
	{
		if (parser->map.map[i][parser->map.width - 1] == ' ')
			flood_fill(parser->map.map, parser->map.width - 1, i, parser->map.width, parser->map.height);
	}
}

void ft_width_realloc(t_parser *parser)
{
	for (int i = 0; i < parser->map.height; i++)
	{
		if ((int)ft_strlen(parser->map.map[i]) < parser->map.width)
		{
			char *tmp = malloc(sizeof(char) * (parser->map.width + 1));
			for (int j = 0; j < parser->map.width; j++)
			{
				if (j < (int)ft_strlen(parser->map.map[i]))
					tmp[j] = parser->map.map[i][j];
				else
					tmp[j] = ' ';
			}
			tmp[parser->map.width] = '\0';
			free(parser->map.map[i]);
			parser->map.map[i] = tmp;
		}
	}
}

//void ft_validate_no_empty_line(t_parser *parser)
//{
//	int i;

//	i = 0;
//	while (i < parser->map.height)
//	{
//		if (parser->map.map[i][0] != '\r' && parser->map.map[i][0] != '\n')
//			return ;
//		i++;
//	}
//	ft_throw("Map contains empty lines", parser, NULL);
//}

int main(int argc, char **argv)
{
	t_parser	parser;
	char	*line;
	int		fd;

	ft_init_all(&parser);
	ft_cube_argv(argc, argv, &parser);
	parser.map.map = NULL;
	parser.map_alloc = 0;

	printf("argv[1] : %s\n", argv[1]);
	fd = open(argv[1], O_RDONLY);
	line = NULL;
	//while (super_get_next_line(fd, &line))
	//{
	//	if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E' || line[0] == 'F' || line[0] == 'C')
	//	{
	//		if (ft_header_parser(&parser, line) == 0)
	//			break;
	//	}
	//	else
	//	{
	//		if (ft_strlen_nonl(line) > 1)
	//		{
	//			printf("line : %s\n", line);
	//			ft_map_reader(&parser, line, &found);
	//		}
	//		else if (found == 1)
	//			break;
	//	}
	//	ft_safe_free(line);
	//}

	//parse header first
	while (super_get_next_line(fd, &line))
	{
		if (ft_header_parser(&parser, line) == 0)
		{
			ft_map_reader(&parser, line);
			ft_safe_free(line);
			while (super_get_next_line(fd, &line))
			{
				ft_map_reader(&parser, line);
				ft_safe_free(line);
			}
		}
		ft_safe_free(line);
	}
	ft_safe_free(line);

	close(fd);
	ft_validate_texture(&parser);
	
	//to do next, FIX MAP ALLOC

	//ft_validate_containment(&parser);

	//Intregity check
	//ft_printf("\n\n");

	//ft_width_realloc(&parser);

	//print map height
	ft_printf("map height : %d\n", parser.map.height);
	//print map width
	ft_printf("map width : %d\n", parser.map.width);

	ft_schongte(&parser);

	for (int i = 0; i < parser.map.height; i++)
	{
		printf("%s", parser.map.map[i]);
	}
	printf("\n\n");

	fill_irregular_map(&parser);

	//printf("\n\n");
	for (int i = 0; i < parser.map.height; i++)
	{
		printf("%s", parser.map.map[i]);
	}

	//ft_schongte(&parser);
	cub3d_main(&parser);

	ft_map_free(&parser);
	return (0);
}

