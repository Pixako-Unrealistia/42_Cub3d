/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <schongte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:59:17 by schongte          #+#    #+#             */
/*   Updated: 2024/03/01 14:59:17 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Seperate to map_util.c

void	ft_init_all(t_game *game)
{
	game->map.height = 0;
	game->map.width = 0;
	game->map.no = NULL;
	game->map.so = NULL;
	game->map.we = NULL;
	game->map.ea = NULL;
	game->map.s = NULL;
	game->map.f = -1;
	game->map.c = -1;
	game->map.map = NULL;
	game->map_alloc = 0;
}

void	ft_map_alloc(t_game *game, size_t size)
{
    game->map_alloc = 1;
    game->map.map = malloc(sizeof(char *) * (size + 1));
    for (size_t i = 0; i < size; i++)
    {
        game->map.map[i] = malloc(sizeof(char) * 2);
        game->map.map[i][0] = '\0';
    }
    game->map.map[size] = NULL;
}

void	ft_map_free(t_game *game)
{
    int i;

	i = 0;
    if (game->map.map)
    {
        while (game->map.map[i])
        {
            free(game->map.map[i]);
            i++;
        }
        free(game->map.map);
		game->map.map = NULL;
    }
    if (game->map.no)
        free(game->map.no);
    if (game->map.so)
        free(game->map.so);
    if (game->map.we)
        free(game->map.we);
    if (game->map.ea)
        free(game->map.ea);
    if (game->map.s)
        free(game->map.s);
    game->map_alloc = 0;
}

void	ft_throw(char *str,t_game *game, char *line)
{
	ft_printf("Error\n%s\n", str);
	if (line)
		free(line);
	ft_map_free(game);
	exit(0);
}

// End of Seperation //
// Seperate to initialise_map.c

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
	ft_printf("%s\n", *texture);
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
	else if (line[0] == 'S' && line[1] == ' ')
		ft_texture_parser(game, line, &game->map.s);
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
    int		i;
    char	**tmp;

    i = 0;
    if (game->map_alloc == 0)
	{
        ft_map_alloc(game, ft_strlen_nonl(line));
	}
	while (game->map.map[i])
		i++;
	tmp = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (game->map.map[i])
	{
		tmp[i] = game->map.map[i];
		i++;
	}
	tmp[i] = line;
	tmp[i + 1] = NULL;
	free(game->map.map);
	game->map.map = tmp;

	game->map.height = i + 1;
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

void	flood_fill(t_game *game, int x, int y)
{
    if (x < 0 || y < 0 || x >= game->map.width || y >= game->map.height || game->map.map[y][x] != '0')
        return;
    game->map.map[y][x] = 'V';
    flood_fill(game, x - 1, y);
    flood_fill(game, x + 1, y);
    flood_fill(game, x, y - 1);
    flood_fill(game, x, y + 1);
}

void	ft_validate_texture(t_game *game)
{
	if (game->map.no == NULL || game->map.so == NULL || game->map.we == NULL || game->map.ea == NULL || game->map.s == NULL || game->map.f == -1 || game->map.c == -1)
		ft_throw("Missing texture", game, NULL);
}

void ft_validate_containment(t_game *game)
{
    // Find a known empty space to start the flood fill
    for (int y = 0; y < game->map.height; y++)
    {
        for (int x = 0; x < game->map.width; x++)
        {
            if (game->map.map[y][x] == '0')
            {
                flood_fill(game, x, y);
                for (int i = 0; i < game->map.width; i++)
                {
                    if (game->map.map[0][i] == 'V' || game->map.map[game->map.height - 1][i] == 'V')
                        ft_throw("Map is not fully contained", game, NULL);
                }
                for (int i = 0; i < game->map.height; i++)
                {
                    if (game->map.map[i][0] == 'V' || game->map.map[i][game->map.width - 1] == 'V')
                        ft_throw("Map is not fully contained", game, NULL);
                }
                return;
            }
        }
    }
}

// End of Seperation //

void	ft_schongte(t_game *game)
{
	int i = 0;

	while (game->map.map[i])
	{
		ft_printf("%s\n", game->map.map[i]);
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
		if (line[0] == '\n')
		{
			ft_printf("Empty line");
			free(line);
			continue;
		}
		if (ft_header_parser(&game, line) == 0)
		{
			free(line);
			ft_validate_texture(&game);
			while (super_get_next_line(fd, &line) > 0)
			{
				if (line[0] == '\0')
					break;
				ft_map_reader(&game, line);
				free(line);
			}
		}
		free(line);
	}
	ft_validate_texture(&game);
	ft_validate_containment(&game);

	//Intregity check
	//ft_printf("\n\n");
	//for (int i = 0; game.map.map[i]; i++)
	//{
	//	ft_printf("%s", game.map.map[i]);
	//}

	//ft_schongte(&game);

	free(line);
	ft_map_free(&game);
	return (0);
}

