/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:57:15 by tnualman          #+#    #+#             */
/*   Updated: 2024/07/18 17:44:01 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	free_textures(t_cub3d *cub3d)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < 32)
// 	{
// 		free(cub3d->texture_north[i]);
// 		free(cub3d->texture_west[i]);
// 		free(cub3d->texture_south[i]);
// 		free(cub3d->texture_east[i]);
// 	}
// 	free(cub3d->texture_north);
// 	free(cub3d->texture_west);
// 	free(cub3d->texture_south);
// 	free(cub3d->texture_east);
// }

void	free_textures(t_cub3d *cub3d)
{
	if (cub3d->texture_north)
		mlx_delete_texture(cub3d->texture_north);
	if (cub3d->texture_west)
		mlx_delete_texture(cub3d->texture_west);
	if (cub3d->texture_south)
		mlx_delete_texture(cub3d->texture_south);
	if (cub3d->texture_east)
		mlx_delete_texture(cub3d->texture_east);
}

void	free_cub3d(t_cub3d *cub3d)
{
	int	i;

	free_textures(cub3d);
	i = -1;
	while (++i < cub3d->map_height)
		free(cub3d->map[i]);
	free(cub3d->map);
	free(cub3d);
}
