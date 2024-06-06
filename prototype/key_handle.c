/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:51:34 by tnualman          #+#    #+#             */
/*   Updated: 2024/06/06 13:51:34 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototype.h"

void	key_hook(void *param)
{
	t_cub3d *cub3d;

	cub3d = param;
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub3d->mlx);
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_UP))
		cub3d->player.ypos -= 1;
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_DOWN))
		cub3d->player.ypos += 1;
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_LEFT))
		cub3d->player.xpos -= 1;
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_RIGHT))
		cub3d->player.xpos += 1;
	// if (key == KEY_RIGHT)
	// 	rotate_clockwise;
	// if (key == KEY_LEFT)
	// 	rotate_counterclockwise;
}

// void	close_window(t_cub3d *cub3d)
// {
// 	mlx_close_window(cub3d->mlx);
// }
