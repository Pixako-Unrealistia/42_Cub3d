/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_1ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:38:44 by tnualman          #+#    #+#             */
/*   Updated: 2024/06/21 15:53:24 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototype.h"

static void raycast_1h_case(t_cub3d *cub3d, t_player p, t_ray *r)
{
    if (r->angle_deg == 0.0 || r->angle_deg == 180.0)
	{
		r->x = cub3d->map_width * 2 * SUBUNITS;
		r->y = p.y;
		r->step = cub3d->map_height;
	}
	else if (r->angle_deg < 180.0)
	{
		r->y = (int)(p.y / SUBUNITS) * SUBUNITS + SUBUNITS;
		r->x = (r->y - p.y) / r->angle_tan + p.x;
		r->y_offset = SUBUNITS;
		r->x_offset = r->y_offset / r->angle_tan;
	}
	else
	{
		r->y = (int)(p.y / SUBUNITS) * SUBUNITS - 0.0001;
		r->x = (r->y - p.y) / r->angle_tan + p.x;
		r->y_offset = -SUBUNITS;
		r->x_offset = r->y_offset / r->angle_tan;
	}
}

void	raycast_1h(t_cub3d *cub3d, t_ray *r, int i)
{
	t_player	p;

	p = cub3d->player;
	r->angle_deg = angle_inrange_deg(p.orient_deg + i);
	r->angle_tan = tan(deg_to_rad(r->angle_deg));
	r->step = 0;
	raycast_1h_case(cub3d, p, r);
	while (r->step < cub3d->map_height)
	{
		r->x_map = (int)(r->x / SUBUNITS);
		r->y_map = (int)(r->y / SUBUNITS);
		if (r->x_map < 0 || r->x_map >= cub3d->map_width 
			|| r->y_map < 0 || r->y_map >= cub3d->map_height
			|| cub3d->map[r->y_map][r->x_map] == 1)
			r->step = cub3d->map_height;
		else
		{
			r->x += r->x_offset;
			r->y += r->y_offset;
			r->step++;
		}
	}
	r->dist = ray_distance(p, *r);
}

static void raycast_1v_case(t_cub3d *cub3d, t_player p, t_ray *r)
{
    if (r->angle_deg == 90.0 || r->angle_deg == 270.0)
	{
		r->x = p.x;
		r->y = cub3d->map_height * 2 * SUBUNITS;
		r->step = cub3d->map_width;
	}
	else if (90.0 < r->angle_deg && r->angle_deg < 270.0)
	{
		r->x = (int)(p.x / SUBUNITS) * SUBUNITS - 0.0001;
		r->y = (r->x - p.x) * r->angle_tan + p.y;
		r->x_offset = -SUBUNITS;
		r->y_offset = r->x_offset * r->angle_tan;
	}
	else
	{
		r->x = (int)(p.x / SUBUNITS) * SUBUNITS + SUBUNITS;
		r->y = (r->x - p.x) * r->angle_tan + p.y;
		r->x_offset = SUBUNITS;
		r->y_offset = r->x_offset * r->angle_tan;
	}
}

void	raycast_1v(t_cub3d *cub3d, t_ray *r, int i)
{
	t_player	p;

	p = cub3d->player;
	r->angle_deg = angle_inrange_deg(p.orient_deg + i);
	r->angle_tan = tan(deg_to_rad(r->angle_deg));
	r->step = 0;
	raycast_1v_case(cub3d, p, r);
	while (r->step < cub3d->map_height)
	{
		r->x_map = (int)(r->x / SUBUNITS);
		r->y_map = (int)(r->y / SUBUNITS);
		if (r->x_map < 0 || r->x_map >= cub3d->map_width 
			|| r->y_map < 0 || r->y_map >= cub3d->map_height
			|| cub3d->map[r->y_map][r->x_map] == 1)
			r->step = cub3d->map_height;
		else
		{
			r->x += r->x_offset;
			r->y += r->y_offset;
			r->step++;
		}
	}
	r->dist = ray_distance(p, *r);
}
