/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:43:15 by tnualman          #+#    #+#             */
/*   Updated: 2024/07/07 23:07:38 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_segment(t_cub3d *cub3d, t_raycast rc, float a);
static void	set_pixels(t_cub3d *cub3d, t_raycast *rc, float a, int i);

void	raycast(t_cub3d *cub3d)
{	
	t_raycast	rc;
	float		a;

	rc.pix_per_seg = (int)(VIEW_W / cub3d->player.fov_deg / RAYS_PER_DEG);
	a = -cub3d->player.fov_deg / 2;
	while (a < cub3d->player.fov_deg / 2)
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
		a += (float)1 / RAYS_PER_DEG;
	}
}

// ty stands for texture_y
static void	draw_segment(t_cub3d *cub3d, t_raycast rc, float a)
{
	int     i;

	rc.ray_dist = rc.ray[rc.selected_ray].dist * cos(deg_to_rad((float)a));
	a += (int)(cub3d->player.fov_deg / 2);
	rc.seg_height = SUBUNITS * VIEW_H / (rc.ray_dist + 1.0);
	rc.ty_step = (float)cub3d->texture_height / rc.seg_height;
	rc.ty_offset = 0.0;
	if (rc.seg_height > VIEW_H)
	{	
		rc.ty_offset = (rc.seg_height - VIEW_H) / 2.0;
		rc.seg_height = VIEW_H;
	}
	rc.seg_offset = (VIEW_H - rc.seg_height) / 2;
	i = -1;
	while (++i < rc.pix_per_seg)
	{
		set_pixels(cub3d, &rc, a, i);
		draw_pixel_column(cub3d->mlx_3dimg, rc.col_top, rc.seg_offset);
		if (rc.seg_height > 0)
			draw_wall_column(cub3d, rc);
		draw_pixel_column(cub3d->mlx_3dimg, rc.col_floor_top, rc.seg_offset);
	}
}

static void	set_pixels(t_cub3d *cub3d, t_raycast *rc, float a, int i)
{
	rc->col_top.x = RAYS_PER_DEG * a * rc->pix_per_seg + i;
	rc->col_top.y = 0;
	rc->col_top.color = cub3d->color_ceiling;
	rc->col_wall_top.x = RAYS_PER_DEG * a * rc->pix_per_seg + i;
	rc->col_wall_top.y = rc->seg_offset;
	rc->col_wall_top.color = 0x000000ff;
	rc->col_floor_top.x = RAYS_PER_DEG * a * rc->pix_per_seg + i;
	rc->col_floor_top.y = rc->seg_height + rc->seg_offset;
	rc->col_floor_top.color = cub3d->color_floor;
}
