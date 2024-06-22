/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util_confirmed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <schongte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:21:24 by schongte          #+#    #+#             */
/*   Updated: 2024/04/20 21:21:24 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "cub3d.h"

void ft_map_free(t_game *game) {
	if (game->map.map) {
		for (int i = 0; i < game->map.height; i++) {
			if (game->map.map[i] != NULL) {
				free(game->map.map[i]);
			}
		}
		free(game->map.map);
		game->map.map = NULL;
	}
	if (game->map.no != NULL)
		free(game->map.no);
	if (game->map.so != NULL)
		free(game->map.so);
	if (game->map.we != NULL)
		free(game->map.we);
	if (game->map.ea != NULL)
		free(game->map.ea);
	game->map_alloc = 0;
}

void	ft_throw(char *str,t_game *game, char *line)
{
	ft_printf("Error\n%s\n", str);
	if (line != NULL)
		free(line);
	ft_map_free(game);
	exit(0);
}

void	ft_safe_free(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	ft_init_all(t_game *game)
{
	game->map.height = 0;
	game->map.width = 0;
	game->map.no = NULL;
	game->map.so = NULL;
	game->map.we = NULL;
	game->map.ea = NULL;
	game->map.f = -1;
	game->map.c = -1;
	game->map.map = NULL;
	game->map_alloc = 0;
}

