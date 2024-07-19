/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:59:17 by schongte          #+#    #+#             */
/*   Updated: 2024/07/18 15:22:47 by tnualman         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_parser	parser;

	ft_init_all(&parser);
	ft_cube_argv(argc, argv, &parser);
	parser.map.map = NULL;
	parser.map_alloc = 0;

	printf("argv[1] : %s\n", argv[1]);
	parser.fd = open(argv[1], O_RDONLY);
	if (parser.fd == -1)
		ft_throw("No such file", &parser, NULL);
	while (super_get_next_line(parser.fd, &parser.line))
	{
		printf(">line : %s", parser.line);
		if (ft_header_parser(&parser, parser.line) == 0)
		{
			//if line contain something other than 0, 1, N,S,E,W, or space, throw error
			ft_map_reader(&parser);
			ft_safe_free(parser.line);
			while (super_get_next_line(parser.fd, &parser.line))
			{
				ft_map_reader(&parser);
				ft_safe_free(parser.line);
			}
		}
		ft_safe_free(parser.line);
	}
	ft_safe_free(parser.line);

	close(parser.fd);
	parser.fd = -1;
	ft_validate_texture(&parser);

	//ft_validate_containment(&parser);

	//Intregity check
	//ft_printf("\n\n");

	for (int i = 0; i < parser.map.height; i++)
	{
		printf(">%s", parser.map.map[i]);
	}
	printf("\n\n");

	width_realloc(&parser);

	//print map height
	ft_printf("map height : %d\n", parser.map.height);
	//print map width
	ft_printf("map width : %d\n", parser.map.width);

	display_stat(&parser);

	for (int i = 0; i < parser.map.height; i++)
	{
		printf(">%s\n", parser.map.map[i]);
	}
	printf("\n\n");

	fill_irregular_map(&parser);

	//printf("\n\n");
	for (int i = 0; i < parser.map.height; i++)
	{
		printf("%s\n", parser.map.map[i]);
	}

	//display_stat(&parser);
	cub3d_main(&parser);

	printf("NO : %s\n%s", parser.map.no, parser.map.no);
	ft_map_free(&parser);
	return (0);
}

