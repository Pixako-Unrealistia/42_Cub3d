/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:43:15 by tnualman          #+#    #+#             */
/*   Updated: 2024/06/30 17:27:54 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototype.h"

static void	draw_segment(t_cub3d *cub3d, t_raycast rc, int a);
static void	set_pixels(t_cub3d *cub3d, t_raycast *rc, int a, int i);
static void	draw_texture_column(t_cub3d *cub3d, t_raycast *rc);

void	raycast(t_cub3d *cub3d)
{
	t_raycast   rc;
	int         a;

	rc.pix_per_seg = (int)(VIEW_W / cub3d->player.fov_deg);
	a = -(int)cub3d->player.fov_deg / 2 - 1;
	while (++a < (int)cub3d->player.fov_deg / 2)
	{
		raycast_1h(cub3d, rc.ray + 0, a);
		raycast_1v(cub3d, rc.ray + 1, a);
		if (rc.ray[0].dist <= rc.ray[1].dist)
		{
			rc.selected_ray = 0;
			draw_1ray(cub3d->mlx_2dimg, cub3d->player, rc.ray[0], 0x00ff00ff);
		}
		else
		{
			rc.selected_ray = 1;
			draw_1ray(cub3d->mlx_2dimg, cub3d->player, rc.ray[1], 0x00ff00ff);
		}
		draw_segment(cub3d, rc, a);
	}
}

static void	draw_segment(t_cub3d *cub3d, t_raycast rc, int a)
{
	int     i;

	rc.ray_dist = rc.ray[rc.selected_ray].dist * cos(deg_to_rad((float)a));
	a += (int)(cub3d->player.fov_deg / 2);
	rc.seg_height = SUBUNITS * VIEW_H / (rc.ray_dist + 1.0);
	if (rc.seg_height > VIEW_H)
		rc.seg_height = VIEW_H;
	rc.seg_offset = (VIEW_H - rc.seg_height) / 2;
	i = -1;
	while (++i < rc.pix_per_seg)
	{
		set_pixels(cub3d, &rc, a, i);
		draw_pixel_column(cub3d->mlx_3dimg, rc.col_top, rc.seg_offset);
		draw_texture_column(cub3d, &rc);
		draw_pixel_column(cub3d->mlx_3dimg, rc.col_floor_top, rc.seg_offset);
	}
}

static void	set_pixels(t_cub3d *cub3d, t_raycast *rc, int a, int i)
{
	rc->col_top.x = a * rc->pix_per_seg + i;
	rc->col_top.y = 0;
	rc->col_top.color = cub3d->color_ceiling;
	rc->col_wall_top.x = a * rc->pix_per_seg + i;
	rc->col_wall_top.y = rc->seg_offset;
	rc->col_wall_top.color = 0x000000ff;
	rc->col_floor_top.x = a * rc->pix_per_seg + i;
	rc->col_floor_top.y = rc->seg_height + rc->seg_offset;
	rc->col_floor_top.color = cub3d->color_floor;
}

static void	draw_texture_column(t_cub3d *cub3d, t_raycast *rc)
{
	if (rc->selected_ray == 0 && rc->ray[0].angle_deg < 180.0)
		rc->col_wall_top.color = cub3d->color_south;
	if (rc->selected_ray == 0 && rc->ray[0].angle_deg >= 180.0)
		rc->col_wall_top.color = cub3d->color_north;
	if (rc->selected_ray == 1 
		&& (rc->ray[0].angle_deg < 90.0 || rc->ray[0].angle_deg > 270.0))
		rc->col_wall_top.color = cub3d->color_east;
	if (rc->selected_ray == 1 
		&& rc->ray[0].angle_deg >= 90.0 && rc->ray[0].angle_deg <= 270.0)
		rc->col_wall_top.color = cub3d->color_west;
	draw_pixel_column(cub3d->mlx_3dimg, rc->col_wall_top, rc->seg_height);
}
