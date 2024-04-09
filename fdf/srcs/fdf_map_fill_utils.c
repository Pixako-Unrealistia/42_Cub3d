/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_fill_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:38:25 by tnualman          #+#    #+#             */
/*   Updated: 2023/10/12 10:42:10 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			fdf_map_fill_init(t_map *map);
static int	fdf_map_fill_init_z_color(t_map *map, int ***which);
int			fdf_map_fill_loop(t_map *map, int fd);
static void	fdf_map_fill_inner_loop(t_map *map, int y, char **line_splitted,
				int row_length);

int	fdf_map_fill_init(t_map *map)
{
	if (!fdf_map_fill_init_z_color(map, &(map->z_grid)))
		return (0);
	if (!fdf_map_fill_init_z_color(map, &(map->color_grid)))
	{
		diy_free_2ptr_int(map->z_grid, map->y_length);
		return (0);
	}
	return (1);
}

static int	fdf_map_fill_init_z_color(t_map *map, int ***which)
{
	int	i;

	*which = (int **)malloc(sizeof(int *) * map->y_length);
	if (!*which)
		return (0);
	i = 0;
	while (i < map->y_length)
	{
		(*which)[i] = (int *)ft_calloc(sizeof(int), map->x_length);
		if (!((*which)[i++]))
			break ;
	}
	if (!((*which)[--i]))
	{
		diy_free_2ptr_int(*which, i);
		return (0);
	}
	return (1);
}

int	fdf_map_fill_loop(t_map *map, int fd)
{
	int		y;
	size_t	row_length;
	char	*line;
	char	**line_splitted;

	y = 0;
	line = get_next_line(fd);
	while (line && y < map->y_length)
	{
		line_splitted = ft_split_cs_wc(line, " \n", &row_length);
		if (!line_splitted)
		{
			free(line);
			return (0);
		}
		fdf_map_fill_inner_loop(map, y++, line_splitted, row_length);
		diy_free_2ptr_char(line_splitted);
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

static void	fdf_map_fill_inner_loop(t_map *map, int y, char **line_splitted,
				int row_length)
{
	int		x;
	char	*color_str;

	x = -1;
	while (++x < row_length)
	{
		(map->z_grid)[y][x] = ft_atoi(line_splitted[x]);
		if ((map->z_grid)[y][x] < map->z_min)
			map->z_min = (map->z_grid)[y][x];
		if ((map->z_grid)[y][x] > map->z_max)
			map->z_max = (map->z_grid)[y][x];
		color_str = ft_strchr(line_splitted[x], ',');
		if (color_str && color_str[1])
			(map->color_grid)[y][x] = ft_atoui_hex(++color_str) % 0x1000000;
		else
			(map->color_grid)[y][x] = DEFAULT_WIRE;
	}
}
