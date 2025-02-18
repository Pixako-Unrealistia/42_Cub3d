/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:59:17 by schongte          #+#    #+#             */
/*   Updated: 2024/07/20 14:38:18 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Seperate to initialise_map.c
//./cub3d ../maps/mandatory.cub

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

// End of Seperation //

void	display_stat(t_parser *parser)
{
	int	iter;

	iter = 0;
	ft_printf("NO : %s\n", parser->map.no);
	ft_printf("SO : %s\n", parser->map.so);
	ft_printf("EA : %s\n", parser->map.ea);
	ft_printf("WE : %s\n", parser->map.we);
	ft_printf("F : %d %d %d\n", parser->map.f[0],
		parser->map.f[1], parser->map.f[2]);
	ft_printf("C : %d %d %d\n", parser->map.c[0],
		parser->map.c[1], parser->map.c[2]);
	ft_printf("start_x : %d\n", parser->map.start_x);
	ft_printf("start_y : %d\n", parser->map.start_y);
	ft_printf("start_dir : %c\n", parser->map.start_dir);
	while (iter < parser->map.height)
	{
		ft_printf("> %s\n", parser->map.map[iter]);
		iter++;
	}
}

void	open_and_parse(t_parser *parser, char *path)
{
	parser->fd = open(path, O_RDONLY);
	if (parser->fd == -1)
		ft_throw("No such file", parser, NULL);
	while (super_get_next_line(parser->fd, &parser->line))
	{
		if (ft_header_parser(parser, parser->line) == 0)
		{
			ft_map_reader(parser);
			ft_safe_free(parser->line);
			while (super_get_next_line(parser->fd, &parser->line))
			{
				if (parser->line[0] == '\n' || parser->line[0] == '\r')
					ft_throw("Empty Line", parser, parser->line);
				ft_map_reader(parser);
				ft_safe_free(parser->line);
			}
		}
		ft_safe_free(parser->line);
	}
	ft_safe_free(parser->line);
	close(parser->fd);
	parser->fd = -1;
}

// Suppose you want to use alt cases, use this.
//void	final_step2(t_parser *parser)
//{
//	int	iter;
//	int	iter2;

//	iter = 0;
//	iter2 = 0;
//	while (iter < parser->map.height)
//	{
//		iter2 = 0;
//		while (parser->map.map[iter][iter2] != '\0')
//		{
//			if (parser->map.map[iter][iter2] == ' ')
//				parser->map.map[iter][iter2] = '0';
//			if (parser->map.map[iter][iter2] == 'd')
//				parser->map.map[iter][iter2] = '0';
//			iter2++;
//		}
//		iter++;
//	}
//	parser->map.map[parser->map.start_y][parser->map.start_x]
//		= parser->map.start_dir;
//}

void	final_step(t_parser *parser)
{
	int	iter;
	int	iter2;

	iter = 0;
	iter2 = 0;
	while (iter < parser->map.height)
	{
		iter2 = 0;
		while (parser->map.map[iter][iter2] != '\0')
		{
			if (parser->map.map[iter][iter2] == ' ')
				parser->map.map[iter][iter2] = '0';
			if (parser->map.map[iter][iter2] == 'd')
				parser->map.map[iter][iter2] = '1';
			iter2++;
		}
		iter++;
	}
	parser->map.map[parser->map.start_y][parser->map.start_x]
		= parser->map.start_dir;
}

int	parser_main(int argc, char **argv, t_parser *parser)
{
	ft_init_all(parser);
	ft_cube_argv(argc, argv, parser);
	parser->map.map = NULL;
	parser->map_alloc = 0;
	printf("argv[1] : %s\n", argv[1]);
	open_and_parse(parser, argv[1]);
	ft_validate_texture(parser);
	width_realloc(parser);
	printf("\n");
	display_stat(parser);
	fill_irregular_map(parser);
	final_step(parser);
	display_stat(parser);
	return (0);
}
