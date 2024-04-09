/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:44:15 by tnualman          #+#    #+#             */
/*   Updated: 2023/10/12 10:45:26 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_free_map(t_map *map);
void	fdf_free_maps(t_map **maps, int map_count);
void	free_fdf(t_fdf *fdf);

void	fdf_free_map(t_map *map)
{
	if (!map)
		return ;
	diy_free_2ptr_int(map->z_grid, map->y_length);
	diy_free_2ptr_int(map->color_grid, map->y_length);
	free(map);
}

void	fdf_free_maps(t_map **maps, int map_count)
{
	int	i;

	if (!maps)
		return ;
	i = 0;
	while (i < map_count)
		fdf_free_map(maps[i++]);
	free(maps);
}

void	free_fdf(t_fdf *fdf)
{
	fdf_free_maps(fdf->maps, fdf->map_count);
	free(fdf);
}
