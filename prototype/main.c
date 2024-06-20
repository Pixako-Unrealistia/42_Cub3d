/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:58:16 by tnualman          #+#    #+#             */
/*   Updated: 2024/06/20 22:38:20 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This is an attempt to create a basic raycaster, following the example from
 * https://www.youtube.com/watch?v=gYRrGTC7GtA ,
 * but using MLX42 instead of OpenGL (directly(?)). 
 */

/* COMPILE WITH:
 * gcc main.c key_handle.c free_utils.c player.c minimap.c libmlx42.a -ldl -lglfw -pthread -lm -o cub3d
 */

#include "prototype.h"

void	init_map(t_cub3d *cub3d)
{
	int	i;
	int map[]=           //the map array. Edit to change level but keep the outer walls
	{
		1,1,1,1,1,1,1,1,
		1,0,0,0,0,1,0,1,
		1,0,0,0,0,1,0,1,
		1,0,0,0,0,1,0,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,1,0,1,
		1,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,	
	};
	cub3d->map_width = 8;
	cub3d->map_height = 8;
	cub3d->map = malloc(sizeof(int *) * cub3d->map_height);
	i = -1;
	while (++i < cub3d->map_height)
		cub3d->map[i] = malloc(sizeof(int) * cub3d->map_width);
	i = -1;
	while (++i < cub3d->map_height * cub3d->map_width)
		cub3d->map[i / cub3d->map_width][i % cub3d->map_width] = map[i];
	cub3d->player.x = SUBUNITS + 32.0;
	cub3d->player.y = SUBUNITS + 32.0;
	cub3d->player.fov_deg = 60.0;
	cub3d->player.orient_deg = 0.0;
	cub3d->player.delta_x = MOVE_SPEED;
	cub3d->player.delta_y = 0.0;
}

void	draw_2d_map(t_cub3d *cub3d)
{
	int	i[3];
	int	color;

	i[0] = -1;
	while (++i[0] < cub3d->map_width * cub3d->map_height)
	{
		if (cub3d->map[i[0] / cub3d->map_width][i[0] % cub3d->map_width] == 1)
			color = 255 << 24 | 255 << 16 | 255 << 8 | 255;
		else
			color = 255;
		i[1] = -1;
		while (++i[1] < SUBUNITS)
		{
			i[2] = -1;
			while (++i[2] < SUBUNITS)
				mlx_put_pixel(cub3d->mlx_2dimg,
					SUBUNITS * (i[0] % cub3d->map_width) + i[2],
					SUBUNITS * (i[0] / cub3d->map_width) + i[1], color);
		}
	}
}

void	init_mlx_stuff(t_cub3d *cub3d)
{
	int	i;

	cub3d->mlx = mlx_init(WIN_W, WIN_H, "cub3d-prototype", true);
	cub3d->mlx_2dimg_playerdot = mlx_new_image(cub3d->mlx, 16, 16);
	i = -1;
	while (++i < 16 * 16)
		mlx_put_pixel(cub3d->mlx_2dimg_playerdot, i / 16, i % 16,
			255 << 24 | 255 << 16 | 255);
	cub3d->mlx_2dimg = mlx_new_image(cub3d->mlx, SUBUNITS * cub3d->map_width,
		SUBUNITS * cub3d->map_height);
	// cub3d->mlx_3dimg = ...
	// mlx_image_to_window(cub3d->mlx, cub3d->mlx_3dimg, 0 , 0);
	mlx_image_to_window(cub3d->mlx, cub3d->mlx_2dimg, 0 , 0);
	mlx_image_to_window(cub3d->mlx, cub3d->mlx_2dimg_playerdot, 0, 0);
	// mlx_set_instance_depth(cub3d->mlx_2dimg_playerdot->instances, 1);
	// mlx_set_instance_depth(cub3d->mlx_2dimg->instances, 2);
}

void	raycast_1h(t_cub3d *cub3d, t_ray *r, int i)
{
	t_player	p;

	p = cub3d->player;
	r->angle_deg = angle_inrange_deg(p.orient_deg + i);
	r->angle_tan = tan(deg_to_rad(r->angle_deg));
	r->step = 0;
	if (r->angle_deg == 0.0 || r->angle_deg == 180.0)
	{
		r->x = cub3d->map_width * 2 *SUBUNITS;
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

void	raycast_1v(t_cub3d *cub3d, t_ray *r, int i)
{
	t_player	p;

	p = cub3d->player;
	r->angle_deg = angle_inrange_deg(p.orient_deg + i);
	r->angle_tan = tan(deg_to_rad(r->angle_deg));
	r->step = 0;
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

void	raycast(t_cub3d *cub3d)
{
	t_ray	r[2];
	// float	dist;
	int		i;

	i = -(int)cub3d->player.fov_deg / 2 - 1;
	while (++i < (int)cub3d->player.fov_deg / 2)
	{
		raycast_1h(cub3d, r + 0, i);
		raycast_1v(cub3d, r + 1, i);
		if (r[0].dist <= r[1].dist)
		{
			// dist = r[0].dist;
			draw_1ray(cub3d->mlx_2dimg, cub3d->player, r[0], 255 << 16 | 255);
		}
		else
		{
			// dist = r[1].dist;
			draw_1ray(cub3d->mlx_2dimg, cub3d->player, r[1], 255 << 16 | 255);
		}
		// TODO: use the values of dist to draw 3d walls.
	}
}

void	game_loop(void *param)
{
	t_cub3d	*cub3d;
	
	cub3d = param;
	if (cub3d->no_key_pressed == 0)
	{
		// printf("Key pressed.\n");
		cub3d->mlx_2dimg_playerdot->instances[0].x = cub3d->player.x - 8;
		cub3d->mlx_2dimg_playerdot->instances[0].y = cub3d->player.y - 8;
		draw_2d_map(cub3d);
		raycast(cub3d);
	}
	cub3d->no_key_pressed = 1;
	// mlx_image_to_window(cub3d->mlx, cub3d->mlx_3dimg, 0 , 0);
}

int	main(void)
{
	t_cub3d	*cub3d;
	
	cub3d = malloc(sizeof(t_cub3d));
	init_map(cub3d);
	init_mlx_stuff(cub3d);
	mlx_loop_hook(cub3d->mlx, &key_hook, cub3d);
	mlx_loop_hook(cub3d->mlx, &game_loop, cub3d);
	mlx_loop(cub3d->mlx);
	mlx_terminate(cub3d->mlx);
	free_all(cub3d);
	return (0);
}