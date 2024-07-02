/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:06:16 by tnualman          #+#    #+#             */
/*   Updated: 2024/06/30 20:29:51 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototype.h"

void	rotate_player(t_cub3d *cub3d, float angle, int clockwise)
{
	t_player    *player;

	player = &cub3d->player;
	if (clockwise)
		player->orient_deg += angle;
	else
		player->orient_deg -= angle;
	player->orient_deg = angle_inrange_deg(player->orient_deg);
	player->delta_x = cos(deg_to_rad(player->orient_deg)) * MOVE_SPEED;
	player->delta_y = sin(deg_to_rad(player->orient_deg)) * MOVE_SPEED;
	cub3d->no_key_pressed = 0;
}

// The large chunks of logical tests are for wall-collision detection.

void    move_forward(t_cub3d *cub3d)
{
	t_player	*player;
	int         cell[2];

	player = &cub3d->player;
	cell[0] = (int)player->x / SUBUNITS;
	cell[1] = (int)player->y / SUBUNITS;
	if ((player->delta_x > 0 && !(cub3d->map[cell[1]][cell[0] + 1] == '1'
		&& (int)(player->x + player->delta_x) / SUBUNITS > cell[0]))
		|| (player->delta_x < 0 && !(cub3d->map[cell[1]][cell[0] - 1] == '1'
		&& (int)(player->x + player->delta_x) / SUBUNITS < cell[0])))
		player->x += player->delta_x;
	if ((player->delta_y > 0 && !(cub3d->map[cell[1] + 1][cell[0]] == '1'
		&& (int)(player->y + player->delta_y) / SUBUNITS > cell[1]))
		|| (player->delta_y < 0 && !(cub3d->map[cell[1] - 1][cell[0]] == '1'
		&& (int)(player->y + player->delta_y) / SUBUNITS < cell[1])))
		player->y += player->delta_y;
	cub3d->no_key_pressed = 0;
}

void    move_backward(t_cub3d *cub3d)
{
	t_player	*player;
	int         cell[2];

	player = &cub3d->player;
	cell[0] = (int)player->x / SUBUNITS;
	cell[1] = (int)player->y / SUBUNITS;
	if ((player->delta_x > 0 && !(cub3d->map[cell[1]][cell[0] - 1] == '1'
		&& (int)(player->x - player->delta_x) / SUBUNITS < cell[0]))
		|| (player->delta_x < 0 && !(cub3d->map[cell[1]][cell[0] + 1] == '1'
		&& (int)(player->x - player->delta_x) / SUBUNITS > cell[0])))
		player->x -= player->delta_x;
	if ((player->delta_y > 0 && !(cub3d->map[cell[1] - 1][cell[0]] == '1'
		&& (int)(player->y - player->delta_y) / SUBUNITS < cell[1]))
		|| (player->delta_y < 0 && !(cub3d->map[cell[1] + 1][cell[0]] == '1'
		&& (int)(player->y - player->delta_y) / SUBUNITS > cell[1])))
		player->y -= player->delta_y;
	cub3d->no_key_pressed = 0;
}

void    strafe_left(t_cub3d *cub3d)
{
	t_player	*player;
	int         cell[2];

	player = &cub3d->player;
	cell[0] = (int)player->x / SUBUNITS;
	cell[1] = (int)player->y / SUBUNITS;
	if ((player->delta_y > 0 && !(cub3d->map[cell[1]][cell[0] + 1] == '1'
		&& (int)(player->x + player->delta_y) / SUBUNITS > cell[0]))
		|| (player->delta_y < 0 && !(cub3d->map[cell[1]][cell[0] - 1] == '1'
		&& (int)(player->x + player->delta_y) / SUBUNITS < cell[0])))
		player->x += player->delta_y;
	if ((player->delta_x > 0 && !(cub3d->map[cell[1] - 1][cell[0]] == '1'
		&& (int)(player->y - player->delta_x) / SUBUNITS < cell[1]))
		|| (player->delta_x < 0 && !(cub3d->map[cell[1] + 1][cell[0]] == '1'
		&& (int)(player->y - player->delta_x) / SUBUNITS > cell[1])))
		player->y -= player->delta_x;
	cub3d->no_key_pressed = 0;
}

void    strafe_right(t_cub3d *cub3d)
{
	t_player	*player;
	int         cell[2];

	player = &cub3d->player;
	cell[0] = (int)player->x / SUBUNITS;
	cell[1] = (int)player->y / SUBUNITS;
	if ((player->delta_y > 0 && !(cub3d->map[cell[1]][cell[0] - 1] == '1'
		&& (int)(player->x - player->delta_y) / SUBUNITS < cell[0]))
		|| (player->delta_y < 0 && !(cub3d->map[cell[1]][cell[0] + 1] == '1'
		&& (int)(player->x - player->delta_y) / SUBUNITS > cell[0])))
		player->x -= player->delta_y;
	if ((player->delta_x > 0 && !(cub3d->map[cell[1] + 1][cell[0]] == '1'
		&& (int)(player->y + player->delta_x) / SUBUNITS > cell[1]))
		|| (player->delta_x < 0 && !(cub3d->map[cell[1] - 1][cell[0]] == '1'
		&& (int)(player->y + player->delta_x) / SUBUNITS < cell[1])))
		player->y += player->delta_x;
	cub3d->no_key_pressed = 0;
}
