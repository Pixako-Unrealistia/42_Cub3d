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
}

void	ft_throw(char *str,t_game *game)
{
	ft_printf("Error\n%s\n", str);
	ft_map_free(game);
	exit(0);
}

int main()
{
	t_game game;
	char *path = "./maps/basic.cub";

	game.map.map = NULL;
	game.map_alloc = 0;

	int fd = open(path, O_RDONLY);
	char *line;
	while (super_get_next_line(fd, &line) != NULL)
	{
		ft_map_reader(&game, line);
		ft_printf("%s\n", line);
	}
	free(line);
	ft_map_free(&game);
	return (0);
}