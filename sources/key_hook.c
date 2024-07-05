/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:51:34 by tnualman          #+#    #+#             */
/*   Updated: 2024/07/05 17:42:47 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototype.h"

void	key_hook(void *param)
{
	t_cub3d *cub3d;
	
	cub3d = param;
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub3d->mlx);
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(cub3d->mlx, MLX_KEY_W))
		move_forward(cub3d);
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(cub3d->mlx, MLX_KEY_S))
		move_backward(cub3d);
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_A))
		strafe_left(cub3d);
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_D))
		strafe_right(cub3d);
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(cub3d->mlx, MLX_KEY_Q))
		rotate_player(cub3d, ROTATE_SPEED, 0);
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(cub3d->mlx, MLX_KEY_E))
		rotate_player(cub3d, ROTATE_SPEED, 1);
}
