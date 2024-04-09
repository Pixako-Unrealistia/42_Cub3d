/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:52:37 by tnualman          #+#    #+#             */
/*   Updated: 2023/10/15 14:00:32 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord	fdf_get_coord(t_fdf *fdf, int i, int j);
static void		fdf_draw_texts(t_fdf *fdf);
static void		fdf_draw_texts_part2(t_fdf *fdf, int y);

void	fdf_draw(t_fdf *fdf)
{
	t_map	*current_map;
	int		i;
	int		j;

	ft_bzero(fdf->img_data_addr, WIN_WIDTH * WIN_HEIGHT * (fdf->img_bpp / 8));
	if (fdf->zoom_scale > 0)
	{
		current_map = fdf->maps[fdf->current_map_index];
		j = -1;
		while (++j < current_map->y_length)
		{
			i = -1;
			while (++i < current_map->x_length)
			{
				if (i < current_map->x_length - 1)
					fdf_draw_line(fdf, fdf_get_coord(fdf, i, j),
						fdf_get_coord(fdf, i + 1, j));
				if (j < current_map->y_length - 1)
					fdf_draw_line(fdf, fdf_get_coord(fdf, i, j),
						fdf_get_coord(fdf, i, j + 1));
			}
		}
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->window_ptr, fdf->img_ptr, 0, 0);
	fdf_draw_texts(fdf);
}

static t_coord	fdf_get_coord(t_fdf *fdf, int i, int j)
{
	t_coord	coord;
	t_map	*current_map;

	current_map = fdf->maps[fdf->current_map_index];
	coord.x = i * fdf->zoom_scale;
	coord.y = j * fdf->zoom_scale;
	coord.z = current_map->z_grid[j][i] * fdf->zoom_scale * fdf->z_scale / 10;
	coord.color = current_map->color_grid[j][i];
	fdf_rotate(fdf, &coord);
	fdf_projection(fdf, &coord.x, &coord.y, coord.z);
	coord.x += fdf->offset_x;
	coord.y += fdf->offset_y;
	return (coord);
}

// TODO: Find a better way to add more info! 
// (Most likely to be the implementation of snprintf() ...)
static void	fdf_draw_texts(t_fdf *fdf)
{
	int		y;
	char	*str[2];

	y = 0;
	str[1] = ft_itoa(fdf->current_map_index);
	str[0] = ft_strjoin("Current Map Index: ", str[1]);
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 15, y += 30, WHITE,
		str[0]);
	free(str[1]);
	free(str[0]);
	fdf_draw_texts_part2(fdf, y);
}

static void	fdf_draw_texts_part2(t_fdf *fdf, int y)
{
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 15, y += 30, WHITE,
		"<< Controls >>");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 15, y += 30, WHITE,
		"Move: W A S D");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 15, y += 25, WHITE,
		"Zoom: + / -");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 15, y += 25, WHITE,
		"Altitude Scale: UP/DOWN");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 15, y += 25, WHITE,
		"Rotate:");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 30, y += 25, WHITE,
		"  x (cw / ccw): Z / X");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 30, y += 25, WHITE,
		"  y (cw / ccw): C / V");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 30, y += 25, WHITE,
		"  z (cw / ccw): B / N");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 15, y += 25, WHITE,
		"Change Perspective: P");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 15, y += 25, WHITE,
		"Change Map: LEFT/RIGHT");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 15, y += 25, WHITE,
		"Restore Defaults: R");
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 15, y += 25, WHITE,
		"ESC: Quit");
}
