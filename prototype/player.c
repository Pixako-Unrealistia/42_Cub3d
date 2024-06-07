/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:06:16 by tnualman          #+#    #+#             */
/*   Updated: 2024/06/07 19:01:48 by tnualman         ###   ########.fr       */
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
	if (player->orient_deg > 360.0)
		player->orient_deg -= 360.0;
	if (player->orient_deg < 0.0)
		player->orient_deg += 360.0;
	player->delta_x = cos(player->orient_deg / 180.0 * M_PI) * MOVE_SPEED;
	player->delta_y = sin(player->orient_deg / 180.0 * M_PI) * MOVE_SPEED;
}

void    move_forward(t_cub3d *cub3d)
{
	t_player	*player;
	int         cell[2];

	player = &cub3d->player;
	cell[0] = (int)player->xpos / SUBUNITS;
	cell[1] = (int)player->ypos / SUBUNITS;
	if ((player->delta_x > 0 && !(cub3d->map[cell[1]][cell[0] + 1] == 1
		&& (int)(player->xpos + player->delta_x) / SUBUNITS > cell[0]))
		|| (player->delta_x < 0 && !(cub3d->map[cell[1]][cell[0] - 1] == 1
		&& (int)(player->xpos + player->delta_x) / SUBUNITS < cell[0])))
		player->xpos += player->delta_x;
	if ((player->delta_y > 0 && !(cub3d->map[cell[1] + 1][cell[0]] == 1
		&& (int)(player->ypos + player->delta_y) / SUBUNITS > cell[1]))
		|| (player->delta_y < 0 && !(cub3d->map[cell[1] - 1][cell[0]] == 1
		&& (int)(player->ypos + player->delta_y) / SUBUNITS < cell[1])))
		player->ypos += player->delta_y;
}

void    move_backward(t_cub3d *cub3d)
{
	t_player	*player;
	int         cell[2];

	player = &cub3d->player;
	cell[0] = (int)player->xpos / SUBUNITS;
	cell[1] = (int)player->ypos / SUBUNITS;
	if ((player->delta_x > 0 && !(cub3d->map[cell[1]][cell[0] - 1] == 1
		&& (int)(player->xpos - player->delta_x) / SUBUNITS < cell[0]))
		|| (player->delta_x < 0 && !(cub3d->map[cell[1]][cell[0] + 1] == 1
		&& (int)(player->xpos - player->delta_x) / SUBUNITS > cell[0])))
		player->xpos -= player->delta_x;
	if ((player->delta_y > 0 && !(cub3d->map[cell[1] - 1][cell[0]] == 1
		&& (int)(player->ypos - player->delta_y) / SUBUNITS < cell[1]))
		|| (player->delta_y < 0 && !(cub3d->map[cell[1] + 1][cell[0]] == 1
		&& (int)(player->ypos - player->delta_y) / SUBUNITS > cell[1])))
		player->ypos -= player->delta_y;
}

void    strafe_left(t_cub3d *cub3d)
{
	t_player	*player;
	int         cell[2];

	player = &cub3d->player;
	cell[0] = (int)player->xpos / SUBUNITS;
	cell[1] = (int)player->ypos / SUBUNITS;
	if ((player->delta_y > 0 && !(cub3d->map[cell[1]][cell[0] + 1] == 1
		&& (int)(player->xpos + player->delta_y) / SUBUNITS > cell[0]))
		|| (player->delta_y < 0 && !(cub3d->map[cell[1]][cell[0] - 1] == 1
		&& (int)(player->xpos + player->delta_y) / SUBUNITS < cell[0])))
		player->xpos += player->delta_y;
	if ((player->delta_x > 0 && !(cub3d->map[cell[1] - 1][cell[0]] == 1
		&& (int)(player->ypos - player->delta_x) / SUBUNITS < cell[1]))
		|| (player->delta_x < 0 && !(cub3d->map[cell[1] + 1][cell[0]] == 1
		&& (int)(player->ypos - player->delta_x) / SUBUNITS > cell[1])))
		player->ypos -= player->delta_x;
}

void    strafe_right(t_cub3d *cub3d)
{
	t_player	*player;
	int         cell[2];

	player = &cub3d->player;
	cell[0] = (int)player->xpos / SUBUNITS;
	cell[1] = (int)player->ypos / SUBUNITS;
	if ((player->delta_y > 0 && !(cub3d->map[cell[1]][cell[0] - 1] == 1
		&& (int)(player->xpos - player->delta_y) / SUBUNITS < cell[0]))
		|| (player->delta_y < 0 && !(cub3d->map[cell[1]][cell[0] + 1] == 1
		&& (int)(player->xpos - player->delta_y) / SUBUNITS > cell[0])))
		player->xpos -= player->delta_y;
	if ((player->delta_x > 0 && !(cub3d->map[cell[1] + 1][cell[0]] == 1
		&& (int)(player->ypos + player->delta_x) / SUBUNITS > cell[1]))
		|| (player->delta_x < 0 && !(cub3d->map[cell[1] - 1][cell[0]] == 1
		&& (int)(player->ypos + player->delta_x) / SUBUNITS < cell[1])))
		player->ypos += player->delta_x;
}

