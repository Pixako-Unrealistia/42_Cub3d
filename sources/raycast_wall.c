/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:21:50 by tnualman          #+#    #+#             */
/*   Updated: 2024/07/18 18:26:30 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_wall_column_loop(t_cub3d *cub3d, t_raycast rc,
				float tx, mlx_texture_t *texture);

void	draw_wall_column(t_cub3d *cub3d, t_raycast rc)
{
	float			tx;
	mlx_texture_t	*texture;

	if (rc.selected_ray == 0)
	{
		if (rc.ray[0].angle_deg < 180.0)
			texture = cub3d->texture_south;
		else
			texture = cub3d->texture_north;
		tx = (int)rc.ray[0].x % SUBUNITS * texture->width / SUBUNITS;
		if (rc.ray[0].angle_deg < 180.0)
			tx = texture->width - 1 - tx;
	}
	else
	{
		if (90.0 < rc.ray[1].angle_deg && rc.ray[1].angle_deg < 270.0)
			texture = cub3d->texture_west;
		else
			texture = cub3d->texture_east;
		tx = (int)rc.ray[1].y % SUBUNITS * texture->width / SUBUNITS;
		if (90.0 < rc.ray[1].angle_deg && rc.ray[1].angle_deg < 270.0)
			tx = texture->width - 1 - tx;
	}
	draw_wall_column_loop(cub3d, rc, tx, texture);
}

static void	draw_wall_column_loop(t_cub3d *cub3d, t_raycast rc,
	float tx, mlx_texture_t *texture)
{
	float	ty;
	int		i;
	int		color;
	int		pixel_index;

	rc.ty_step *= (float)texture->height;
	ty = rc.ty_offset * rc.ty_step;
	i = -1;
	while (++i < rc.seg_height)
	{
		pixel_index = texture->bytes_per_pixel
			* ((int)ty * texture->width + (int)tx);
		color = texture->pixels[pixel_index] << 24
			| texture->pixels[pixel_index + 1] << 16
			| texture->pixels[pixel_index + 2] << 8
			| texture->pixels[pixel_index + 3];
		mlx_put_pixel(cub3d->mlx_3dimg, rc.col_wall_top.x,
			rc.col_wall_top.y + i, color);
		ty += rc.ty_step;
	}
}
