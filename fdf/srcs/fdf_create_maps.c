/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_maps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:29:12 by tnualman          #+#    #+#             */
/*   Updated: 2023/10/12 10:37:05 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	*fdf_create_map(char *file, int map_index);
static t_map	*fdf_map_set_dimension(t_map *map, char *file, int map_index);
static t_map	*fdf_map_fill(t_map *map, char *file, int map_index);

t_map	**fdf_create_maps(t_map **maps, int map_count, char **argv)
{
	int	i;

	i = 0;
	while (i < map_count)
	{
		maps[i] = fdf_create_map(argv[i + 1], i);
		if (!maps[i++])
			break ;
	}
	if (!maps[--i])
	{
		while (--i >= 0)
			fdf_free_map(maps[i]);
		free(maps);
		return (NULL);
	}
	maps[map_count] = NULL;
	return (maps);
}

static t_map	*fdf_create_map(char *file, int map_index)
{
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		ft_dprintf(2, "Allocation for map[%d] failed!\n", map_index);
		return (NULL);
	}
	map = fdf_map_set_dimension(map, file, map_index);
	if (map)
		map = fdf_map_fill(map, file, map_index);
	if (!map)
		ft_dprintf(2, "Setup for map[%d] failed!\n", map_index);
	return (map);
}

static t_map	*fdf_map_set_dimension(t_map *map, char *file, int map_index)
{
	int		fd;
	int		wc;
	char	*temp_str;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_dprintf(2, "Failed to open %s for map[%d] !\n", file, map_index);
		free(map);
		return (NULL);
	}
	temp_str = get_next_line(fd);
	while (temp_str)
	{
		(map->y_length)++;
		wc = ft_word_count(temp_str, ' ');
		if (wc > map->x_length)
			map->x_length = wc;
		free(temp_str);
		temp_str = get_next_line(fd);
	}
	close(fd);
	return (map);
}

static t_map	*fdf_map_fill(t_map *map, char *file, int map_index)
{
	int	fd;

	if (map->y_length < 1)
	{
		fdf_map_fill_error(map, 1, file, map_index);
		return (NULL);
	}
	if (!fdf_map_fill_init(map))
	{
		fdf_map_fill_error(map, 2, file, map_index);
		return (NULL);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		fdf_map_fill_error(map, 3, file, map_index);
		return (NULL);
	}
	if (!fdf_map_fill_loop(map, fd))
	{
		fdf_map_fill_error(map, 4, file, map_index);
		map = NULL;
	}
	close(fd);
	return (map);
}
