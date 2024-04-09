/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 00:54:30 by tnualman          #+#    #+#             */
/*   Updated: 2023/10/14 10:14:06 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_defaults(t_fdf *fdf);
int		fdf_close_window(t_fdf *fdf);

void	fdf_window(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->window_ptr = mlx_new_window(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"fdf");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	fdf->img_data_addr = mlx_get_data_addr(fdf->img_ptr,
			&fdf->img_bpp, &fdf->img_size_line, &fdf->img_endian);
	fdf->current_map_index = 0;
	fdf_defaults(fdf);
	fdf_draw(fdf);
	mlx_hook(fdf->window_ptr, 2, 1L << 0, fdf_keyboard_handle, fdf);
	mlx_hook(fdf->window_ptr, 17, 1L << 17, fdf_close_window, fdf);
	mlx_loop(fdf->mlx_ptr);
}

void	fdf_defaults(t_fdf *fdf)
{
	t_map	*current_map;

	current_map = fdf->maps[fdf->current_map_index];
	fdf->zoom_scale = WIN_WIDTH / current_map->x_length / 2;
	if (WIN_HEIGHT / current_map->y_length / 2 > fdf->zoom_scale)
		fdf->zoom_scale = WIN_HEIGHT / current_map->y_length / 2;
	fdf->offset_x = WIN_WIDTH / 2;
	fdf->offset_y = (WIN_HEIGHT - current_map->y_length * fdf->zoom_scale) / 2;
	fdf->projection = 1;
	fdf->z_scale = 1;
	fdf->view_angle_x = 0;
	fdf->view_angle_y = 0;
	fdf->view_angle_z = 0;
}

int	fdf_close_window(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->window_ptr);
	mlx_destroy_window(fdf->mlx_ptr, fdf->window_ptr);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	free_fdf(fdf);
	exit(0);
	return (0);
}
