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

void	ft_map_alloc(t_game *game)
{
	game->map_alloc = 1;
	game->map.map = malloc(sizeof(char *) * 2);
	game->map.map[0] = malloc(sizeof(char) * 2);
	game->map.map[0][0] = '\0';
	game->map.map[1] = NULL;
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
		ft_map_alloc(game);
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
	if (x < 0 || y < 0 || x >= game->map.width || y >= game->map.height || game->map.map[y][x] != ' ')
		return;
	game->map.map[y][x] = 'V';
	flood_fill(game, x - 1, y);
	flood_fill(game, x + 1, y);
	flood_fill(game, x, y - 1);
	flood_fill(game, x, y + 1);
}

void ft_validate_containment(t_game *game)
{
	
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
