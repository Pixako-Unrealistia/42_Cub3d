/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:21:50 by tnualman          #+#    #+#             */
/*   Updated: 2024/07/07 23:00:30 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_wall_column_loop(t_cub3d *cub3d, t_raycast rc,
	float tx, int **texture);

void	draw_wall_column(t_cub3d *cub3d, t_raycast rc)
{	
	float	tx;
	int		**texture ;
	
	if (rc.selected_ray == 0)
	{
		tx = (int)rc.ray[0].x % SUBUNITS * cub3d->texture_width / SUBUNITS;
		if (cub3d->player.orient_deg < 180.0)
			tx = cub3d->texture_width - 1 - tx;
		if (cub3d->player.orient_deg < 180.0)
			texture = cub3d->texture_south;
		else
			texture = cub3d->texture_north;
	}
	else
	{
		tx = (int)rc.ray[1].y % SUBUNITS * cub3d->texture_width / SUBUNITS;
		if (90 < cub3d->player.orient_deg && cub3d->player.orient_deg < 270.0)
			tx = cub3d->texture_width - 1 - tx;
		if (90 < cub3d->player.orient_deg && cub3d->player.orient_deg < 270.0)
			texture = cub3d->texture_west;
		else
			texture = cub3d->texture_east;
	}
	draw_wall_column_loop(cub3d, rc, tx, texture);
}

static void	draw_wall_column_loop(t_cub3d *cub3d, t_raycast rc,
	float tx, int **texture)
{
	float	ty;
	int 	i;
	int		color;
	
	ty = rc.ty_offset * rc.ty_step;
	i = -1;
	while (++i < rc.seg_height)
	{	
		if (texture[(int)ty][(int)tx] == 1)
			color = 0xffff00ff;
		else
			color = 0x0000ffff;
		mlx_put_pixel(cub3d->mlx_3dimg, rc.col_wall_top.x, rc.col_wall_top.y + i, color);
		ty += rc.ty_step;
	}
}