/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:51:34 by tnualman          #+#    #+#             */
/*   Updated: 2024/07/21 21:15:55 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	do_movement(t_cub3d *cub3d);

void	key_hook(void *param)
{
	t_cub3d		*cub3d;
	mlx_t		*mlx;
	t_player	*player;

	cub3d = param;
	mlx = cub3d->mlx;
	player = &cub3d->player;
	if (mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx, MLX_KEY_W))
		player->move_dir += 1;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx, MLX_KEY_S))
		player->move_dir -= 1;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		player->strafe_dir -= 1;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		player->strafe_dir += 1;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_Q))
		player->rotate_dir -= 1;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx, MLX_KEY_E))
		player->rotate_dir += 1;
	do_movement(cub3d);
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void	key_hook_l(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*cub3d;

	cub3d = param;
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_PRESS)
	{
		if (cub3d->mouselook_mode)
			mlx_set_cursor_mode(cub3d->mlx, MLX_MOUSE_NORMAL);
		else
			mlx_set_cursor_mode(cub3d->mlx, MLX_MOUSE_DISABLED);
		mlx_set_mouse_pos(cub3d->mlx, VIEW_W / 2, VIEW_H / 2);
		cub3d->mouselook_mode = !(cub3d->mouselook_mode);
	}
}

static void	do_movement(t_cub3d *cub3d)
{
	t_player	*player;
	float		factor;

	player = &cub3d->player;
	factor = 1.0;
	if (player->move_dir && player->strafe_dir)
		factor = SQRT_HALF;
	if (player->move_dir > 0)
		move_forward(cub3d, factor);
	if (player->move_dir < 0)
		move_backward(cub3d, factor);
	if (player->strafe_dir > 0)
		strafe_right(cub3d, factor);
	if (player->strafe_dir < 0)
		strafe_left(cub3d, factor);
	if (player->rotate_dir)
		rotate_player(cub3d, ROTATE_SPEED, player->rotate_dir);
	player->move_dir = 0;
	player->strafe_dir = 0;
	player->rotate_dir = 0;
}
