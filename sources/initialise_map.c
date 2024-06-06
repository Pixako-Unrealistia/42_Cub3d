/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:59:17 by schongte          #+#    #+#             */
/*   Updated: 2024/05/14 17:25:18 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Seperate to initialise_map.c

void	ft_map_alloc(t_game *game, size_t size)
{
	game->map.map = malloc(sizeof(char *) * 2);
	if (game->map.map == NULL)
	{
		ft_throw("Memory allocation failed", game, NULL);
	}
	game->map.map[0] = malloc(sizeof(char) * (size + 1));
	if (game->map.map[0] == NULL)
	{
		ft_throw("Memory allocation failed", game, NULL);
	}
	game->map.map[0][size] = '\0';
	game->map.map[1] = NULL;
	game->map_alloc = 1;
}


void	ft_texture_parser(t_game *game, char *line, char **texture)
{
	int i = 0;
	int j = 0;
	char *tmp;

	if (*texture != NULL)
		ft_throw("Texture already realised", game, line);
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

void	ft_color_parser(t_game *game, char *line, int *color)
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
		ft_throw("Invalid color range", game, line);
	*color = tmp;
}

int	ft_header_parser(t_game *game, char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		ft_texture_parser(game, line, &game->map.no);
	else if (line[0] == 'S' && line[1] == 'O')
		ft_texture_parser(game, line, &game->map.so);
	else if (line[0] == 'W' && line[1] == 'E')
		ft_texture_parser(game, line, &game->map.we);
	else if (line[0] == 'E' && line[1] == 'A')
		ft_texture_parser(game, line, &game->map.ea);
	else if (line[0] == 'F')
		ft_color_parser(game, line, &game->map.f);
	else if (line[0] == 'C')
		ft_color_parser(game, line, &game->map.c);
	else if (line[0] == '\n')
		return (1);
	else if (line[0] == '\0')
		return (0);
	else
	{
		ft_printf("%s", line);
		ft_throw("Invalid map parameter", game, line);
		return (0);
	}
	return (1);
}

void	ft_map_reader(t_game *game, char *line)
{
	char	**tmp;

	if (game->map_alloc == 0)
		ft_map_alloc(game, ft_strlen_nonl(line));
	else
	{
		tmp = malloc(sizeof(char *) * (game->map.height + 2));
		if (tmp == NULL)
			ft_throw("Memory allocation failed", game, line);
		for (int i = 0; i < game->map.height; i++)
			tmp[i] = game->map.map[i];
		tmp[game->map.height] = malloc(sizeof(char) * (ft_strlen_nonl(line) + 1));
		if (tmp[game->map.height] == NULL)
			ft_throw("Memory allocation failed", game, line);
		tmp[game->map.height][ft_strlen_nonl(line)] = '\0';
		tmp[game->map.height + 1] = NULL;
		free(game->map.map);
		game->map.map = tmp;
	}

	if (game->map.map[game->map.height] != NULL)
	{
		free(game->map.map[game->map.height]);
		game->map.map[game->map.height] = NULL;
	}
	game->map.map[game->map.height] = strdup(line);
	game->map.map[game->map.height + 1] = NULL;
	game->map.height++;
	if (game->map.width < ft_strlen_nonl(line))
		game->map.width = ft_strlen_nonl(line);
}

// End of Seperation //
// Seperate to validate_map.c

void	ft_cube_argv(int argc, char **argv, t_game *game)
{
	int	map_parameter_len;

	game->map_alloc = 0;
	if (argc != 2)
		ft_throw("Format : ./cub3d (map_path)", game, NULL);
	map_parameter_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][map_parameter_len - 4], ".cub", 4))
		ft_throw("Expected .cub", game, NULL);
}

void	ft_validate_texture(t_game *game)
{
	if (game->map.no == NULL || game->map.so == NULL || game->map.we == NULL || game->map.ea == NULL || game->map.f == -1 || game->map.c == -1)
		ft_throw("Missing texture", game, NULL);
}

void ft_validate_containment(t_game *game)
{
	int i, j;
	for (i = 0; i < game->map.height; i++)
	{
		if (game->map.map[i][0] != '1' || game->map.map[i][game->map.width - 1] != '1')
			ft_throw("Map is not surrounded by walls", game, NULL);
		for (j = 0; j < game->map.width; j++)
		{
			char c = game->map.map[i][j];
			if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W')
				ft_throw("Map contains invalid character", game, NULL);
		}
	}
}

// End of Seperation //

void	ft_schongte(t_game *game)
{
	int i = 0;
	//print NO SO EA WE
	ft_printf("NO : %s", game->map.no);
	ft_printf("SO : %s", game->map.so);
	ft_printf("EA : %s", game->map.ea);
	ft_printf("WE : %s", game->map.we);
	////print F C
	ft_printf("F : %d\n", game->map.f);
	ft_printf("C : %d\n", game->map.c);

	while (game->map.map[i])
	{
		printf("%s", game->map.map[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_game	game;
	char	*line;
	int fd;

	ft_init_all(&game);
	ft_cube_argv(argc, argv, &game);
	game.map.map = NULL;
	game.map_alloc = 0;

	fd = open(argv[1], O_RDONLY);
	line = NULL;
	while (super_get_next_line(fd, &line) > 0)
	{
		if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E' || line[0] == 'F' || line[0] == 'C')
		{
			if (ft_header_parser(&game, line) == 0)
				break;
		}
		else
			ft_map_reader(&game, line);
		ft_safe_free(line);
	}
	ft_safe_free(line);
	ft_validate_texture(&game);
	//ft_validate_containment(&game);

	//Intregity check
	//ft_printf("\n\n");
	//for (int i = 0; game.map.map[i]; i++)
	//{
	//	ft_printf("%s", game.map.map[i]);
	//}

	ft_schongte(&game);

	ft_map_free(&game);
	return (0);
}

