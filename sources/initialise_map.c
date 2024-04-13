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
	int i = 0;

	if (game->map.map)
	{
		while (game->map.map[i])
		{
			free(game->map.map[i]);
			i++;
		}
		free(game->map.map);
	}
	game->map_alloc = 0;
}

void	ft_throw(char *str,t_game *game)
{
	ft_printf("\nError\n%s\n", str);
	ft_map_free(game);
	exit(0);
}

// End of Seperation //
// Seperate to initialise_map.c

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
		ft_throw("Format : ./cub3d (map_path)", game);
	map_parameter_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][map_parameter_len - 4], ".cub", 4))
		ft_throw("Expected .cub", game);
}

void flood_fill(t_game *game, int x, int y)
{
    // If the current position is out of bounds or is not an empty space, return
    if (x < 0 || y < 0 || x >= game->map.width || y >= game->map.height || game->map.map[y][x] != '0')
        return;

    // Mark the current position as visited
    game->map.map[y][x] = 'V';

    // Recursively fill the neighboring positions
    flood_fill(game, x - 1, y);
    flood_fill(game, x + 1, y);
    flood_fill(game, x, y - 1);
    flood_fill(game, x, y + 1);
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

                // After the flood fill, check if any edge position is marked as visited
                for (int i = 0; i < game->map.width; i++)
                {
                    if (game->map.map[0][i] == 'V' || game->map.map[game->map.height - 1][i] == 'V')
                        ft_throw("Map is not fully contained", game);
                }
                for (int i = 0; i < game->map.height; i++)
                {
                    if (game->map.map[i][0] == 'V' || game->map.map[i][game->map.width - 1] == 'V')
                        ft_throw("Map is not fully contained", game);
                }

                return;
            }
        }
    }

    // If no empty space is found, the map is fully contained
}

// End of Seperation //


int main(int argc, char **argv)
{
	t_game	game;
	char	*line;
	int fd;

	ft_cube_argv(argc, argv, &game);
	game.map.map = NULL;
	game.map_alloc = 0;

	fd = open(argv[1], O_RDONLY);
	line = NULL;
	ft_init_all(&game);
	while (1)
	{
		super_get_next_line(fd, &line);
		if (line == NULL)
			break;
		ft_printf("%s", line);
		ft_map_reader(&game, line);
	}	
	ft_validate_containment(&game);

	//Intregity check
	//ft_printf("\n\n");
	//for (int i = 0; game.map.map[i]; i++)
	//{
	//	ft_printf("%s", game.map.map[i]);
	//}

	free(line);
	ft_map_free(&game);
	return (0);
}
