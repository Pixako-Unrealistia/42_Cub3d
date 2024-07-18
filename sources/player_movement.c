/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:06:16 by tnualman          #+#    #+#             */
/*   Updated: 2024/07/18 20:51:30 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_cub3d *cub3d, float angle, int clockwise)
{
	t_player	*player;

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

void	move_forward(t_cub3d *cub3d, float factor)
{
	t_player	*p;
	int			c[2];
	float		dx;
	float		dy;

	p = &cub3d->player;
	dx = p->delta_x;
	dy = p->delta_y;
	c[0] = (int)p->x / SUBUNITS;
	c[1] = (int)p->y / SUBUNITS;
	if ((dx > 0 && !(cub3d->map[c[1]][c[0] + 1] == '1'
			&& (int)(p->x + dx * factor + SUBUNITS / 8) / SUBUNITS > c[0]))
			|| (dx < 0 && !(cub3d->map[c[1]][c[0] - 1] == '1'
			&& (int)(p->x + dx * factor - SUBUNITS / 8) / SUBUNITS < c[0])))
		p->x += dx * factor;
	if ((dy > 0 && !(cub3d->map[c[1] + 1][c[0]] == '1'
			&& (int)(p->y + dy * factor + SUBUNITS / 8) / SUBUNITS > c[1]))
			|| (dy < 0 && !(cub3d->map[c[1] - 1][c[0]] == '1'
			&& (int)(p->y + dy * factor - SUBUNITS / 8) / SUBUNITS < c[1])))
		p->y += dy * factor;
	cub3d->new_frame = 1;
}

void	move_backward(t_cub3d *cub3d, float factor)
{
	t_player	*p;
	int			c[2];
	float		dx;
	float		dy;

	p = &cub3d->player;
	dx = p->delta_x;
	dy = p->delta_y;
	c[0] = (int)p->x / SUBUNITS;
	c[1] = (int)p->y / SUBUNITS;
	if ((dx > 0 && !(cub3d->map[c[1]][c[0] - 1] == '1'
			&& (int)(p->x - dx * factor - SUBUNITS / 8) / SUBUNITS < c[0]))
			|| (dx < 0 && !(cub3d->map[c[1]][c[0] + 1] == '1'
			&& (int)(p->x - dx * factor + SUBUNITS / 8) / SUBUNITS > c[0])))
		p->x -= dx * factor;
	if ((dy > 0 && !(cub3d->map[c[1] - 1][c[0]] == '1'
			&& (int)(p->y - dy * factor - SUBUNITS / 8) / SUBUNITS < c[1]))
			|| (dy < 0 && !(cub3d->map[c[1] + 1][c[0]] == '1'
			&& (int)(p->y - dy * factor + SUBUNITS / 8) / SUBUNITS > c[1])))
		p->y -= dy * factor;
	cub3d->new_frame = 1;
}

void	strafe_left(t_cub3d *cub3d, float factor)
{
	t_player	*p;
	int			c[2];
	float		dx;
	float		dy;

	p = &cub3d->player;
	dx = p->delta_x;
	dy = p->delta_y;
	c[0] = (int)p->x / SUBUNITS;
	c[1] = (int)p->y / SUBUNITS;
	if ((dy > 0 && !(cub3d->map[c[1]][c[0] + 1] == '1'
			&& (int)(p->x + dy * factor + SUBUNITS / 8) / SUBUNITS > c[0]))
			|| (dy < 0 && !(cub3d->map[c[1]][c[0] - 1] == '1'
			&& (int)(p->x + dy * factor - SUBUNITS / 8) / SUBUNITS < c[0])))
		p->x += dy * factor;
	if ((dx > 0 && !(cub3d->map[c[1] - 1][c[0]] == '1'
			&& (int)(p->y - dx * factor - SUBUNITS / 8) / SUBUNITS < c[1]))
			|| (dx < 0 && !(cub3d->map[c[1] + 1][c[0]] == '1'
			&& (int)(p->y - dx * factor + SUBUNITS / 8) / SUBUNITS > c[1])))
		p->y -= dx * factor;
	cub3d->new_frame = 1;
}

void	strafe_right(t_cub3d *cub3d, float factor)
{
	t_player	*p;
	int			c[2];
	float		dx;
	float		dy;

	p = &cub3d->player;
	dx = p->delta_x;
	dy = p->delta_y;
	c[0] = (int)p->x / SUBUNITS;
	c[1] = (int)p->y / SUBUNITS;
	if ((dy > 0 && !(cub3d->map[c[1]][c[0] - 1] == '1'
			&& (int)(p->x - dy * factor - SUBUNITS / 8) / SUBUNITS < c[0]))
			|| (dy < 0 && !(cub3d->map[c[1]][c[0] + 1] == '1'
			&& (int)(p->x - dy * factor + SUBUNITS / 8) / SUBUNITS > c[0])))
		p->x -= dy * factor;
	if ((dx > 0 && !(cub3d->map[c[1] + 1][c[0]] == '1'
			&& (int)(p->y + dx * factor + SUBUNITS / 8) / SUBUNITS > c[1]))
			|| (dx < 0 && !(cub3d->map[c[1] - 1][c[0]] == '1'
			&& (int)(p->y + dx * factor - SUBUNITS / 8) / SUBUNITS < c[1])))
		p->y += dx * factor;
	cub3d->new_frame = 1;
}
