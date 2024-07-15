/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:06:16 by tnualman          #+#    #+#             */
/*   Updated: 2024/07/15 22:30:51 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	rotate_player(t_cub3d *cub3d, float angle, int clockwise)
{
	t_player    *player;

	player = &cub3d->player;
	if (clockwise == 1)
		player->orient_deg += angle;
	if (clockwise == -1)
		player->orient_deg -= angle;
	player->orient_deg = angle_inrange_deg(player->orient_deg);
	player->delta_x = cos(deg_to_rad(player->orient_deg)) * MOVE_SPEED;
	player->delta_y = sin(deg_to_rad(player->orient_deg)) * MOVE_SPEED;
	cub3d->new_frame = 1;
}

// The large chunks of logical tests are for wall-collision detection.
// Intended values for "float factor" are 1.0 and SQRT_HALF (diagonal moves).

void    move_forward(t_cub3d *cub3d, float factor)
{
	t_player	*player;
	int         cell[2];

	player = &cub3d->player;
	cell[0] = (int)player->x / SUBUNITS;
	cell[1] = (int)player->y / SUBUNITS;
	if ((player->delta_x > 0 && !(cub3d->map[cell[1]][cell[0] + 1] == '1'
		&& (int)(player->x + player->delta_x * factor) / SUBUNITS > cell[0]))
		|| (player->delta_x < 0 && !(cub3d->map[cell[1]][cell[0] - 1] == '1'
		&& (int)(player->x + player->delta_x * factor) / SUBUNITS < cell[0])))
		player->x += player->delta_x * factor;
	if ((player->delta_y > 0 && !(cub3d->map[cell[1] + 1][cell[0]] == '1'
		&& (int)(player->y + player->delta_y * factor) / SUBUNITS > cell[1]))
		|| (player->delta_y < 0 && !(cub3d->map[cell[1] - 1][cell[0]] == '1'
		&& (int)(player->y + player->delta_y * factor) / SUBUNITS < cell[1])))
		player->y += player->delta_y * factor;
	cub3d->new_frame = 1;
}

void    move_backward(t_cub3d *cub3d, float factor)
{
	t_player	*player;
	int         cell[2];

	player = &cub3d->player;
	cell[0] = (int)player->x / SUBUNITS;
	cell[1] = (int)player->y / SUBUNITS;
	if ((player->delta_x > 0 && !(cub3d->map[cell[1]][cell[0] - 1] == '1'
		&& (int)(player->x - player->delta_x * factor) / SUBUNITS < cell[0]))
		|| (player->delta_x < 0 && !(cub3d->map[cell[1]][cell[0] + 1] == '1'
		&& (int)(player->x - player->delta_x * factor) / SUBUNITS > cell[0])))
		player->x -= player->delta_x * factor;
	if ((player->delta_y > 0 && !(cub3d->map[cell[1] - 1][cell[0]] == '1'
		&& (int)(player->y - player->delta_y * factor) / SUBUNITS < cell[1]))
		|| (player->delta_y < 0 && !(cub3d->map[cell[1] + 1][cell[0]] == '1'
		&& (int)(player->y - player->delta_y * factor) / SUBUNITS > cell[1])))
		player->y -= player->delta_y * factor;
	cub3d->new_frame = 1;
}

void    strafe_left(t_cub3d *cub3d, float factor)
{
	t_player	*player;
	int         cell[2];

	player = &cub3d->player;
	cell[0] = (int)player->x / SUBUNITS;
	cell[1] = (int)player->y / SUBUNITS;
	if ((player->delta_y > 0 && !(cub3d->map[cell[1]][cell[0] + 1] == '1'
		&& (int)(player->x + player->delta_y * factor) / SUBUNITS > cell[0]))
		|| (player->delta_y < 0 && !(cub3d->map[cell[1]][cell[0] - 1] == '1'
		&& (int)(player->x + player->delta_y * factor) / SUBUNITS < cell[0])))
		player->x += player->delta_y * factor;
	if ((player->delta_x > 0 && !(cub3d->map[cell[1] - 1][cell[0]] == '1'
		&& (int)(player->y - player->delta_x * factor) / SUBUNITS < cell[1]))
		|| (player->delta_x < 0 && !(cub3d->map[cell[1] + 1][cell[0]] == '1'
		&& (int)(player->y - player->delta_x * factor) / SUBUNITS > cell[1])))
		player->y -= player->delta_x * factor;
	cub3d->new_frame = 1;
}

void    strafe_right(t_cub3d *cub3d, float factor)
{
	t_player	*player;
	int         cell[2];

	player = &cub3d->player;
	cell[0] = (int)player->x / SUBUNITS;
	cell[1] = (int)player->y / SUBUNITS;
	if ((player->delta_y > 0 && !(cub3d->map[cell[1]][cell[0] - 1] == '1'
		&& (int)(player->x - player->delta_y * factor) / SUBUNITS < cell[0]))
		|| (player->delta_y < 0 && !(cub3d->map[cell[1]][cell[0] + 1] == '1'
		&& (int)(player->x - player->delta_y * factor) / SUBUNITS > cell[0])))
		player->x -= player->delta_y * factor;
	if ((player->delta_x > 0 && !(cub3d->map[cell[1] + 1][cell[0]] == '1'
		&& (int)(player->y + player->delta_x * factor) / SUBUNITS > cell[1]))
		|| (player->delta_x < 0 && !(cub3d->map[cell[1] - 1][cell[0]] == '1'
		&& (int)(player->y + player->delta_x * factor) / SUBUNITS < cell[1])))
		player->y += player->delta_x * factor;
	cub3d->new_frame = 1;
}
