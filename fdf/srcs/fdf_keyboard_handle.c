/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyboard_handle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:58:07 by tnualman          #+#    #+#             */
/*   Updated: 2023/10/07 09:19:31 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	move_or_rotate(int key, t_fdf *fdf);
static void	zoom_or_z_scale(int key, t_fdf *fdf);
static void	change_map(int key, t_fdf *fdf);

int	fdf_keyboard_handle(int key, t_fdf *fdf)
{
	if (key == KEY_ESC)
		fdf_close_window(fdf);
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D
		|| key == KEY_Z || key == KEY_X || key == KEY_C || key == KEY_V
		|| key == KEY_B || key == KEY_N)
		move_or_rotate(key, fdf);
	if (key == KEY_PLUS || key == KEY_MINUS || key == KEY_UP || key == KEY_DOWN)
		zoom_or_z_scale(key, fdf);
	if (key == KEY_LEFT || key == KEY_RIGHT)
		change_map(key, fdf);
	if (key == KEY_P)
		fdf->projection = !(fdf->projection);
	if (key == KEY_R)
		fdf_defaults(fdf);
	fdf_draw(fdf);
	return (0);
}

static void	move_or_rotate(int key, t_fdf *fdf)
{
	if (key == KEY_W)
		fdf->offset_y -= MOVE_INCREMENT;
	else if (key == KEY_A)
		fdf->offset_x -= MOVE_INCREMENT;
	else if (key == KEY_S)
		fdf->offset_y += MOVE_INCREMENT;
	else if (key == KEY_D)
		fdf->offset_x += MOVE_INCREMENT;
	else if (key == KEY_Z)
		fdf->view_angle_x += ROTATION_INCREMENT;
	else if (key == KEY_X)
		fdf->view_angle_x -= ROTATION_INCREMENT;
	else if (key == KEY_C)
		fdf->view_angle_y += ROTATION_INCREMENT;
	else if (key == KEY_V)
		fdf->view_angle_y -= ROTATION_INCREMENT;
	else if (key == KEY_B)
		fdf->view_angle_z += ROTATION_INCREMENT;
	if (key == KEY_N)
		fdf->view_angle_z -= ROTATION_INCREMENT;
}

static void	zoom_or_z_scale(int key, t_fdf *fdf)
{
	if (key == KEY_PLUS)
	{
		if (fdf->zoom_scale < 256.0)
			fdf->zoom_scale += ZOOM_INCREMENT;
	}
	else if (key == KEY_MINUS)
	{
		if (fdf->zoom_scale > 0)
			fdf->zoom_scale -= ZOOM_INCREMENT;
	}
	else if (key == KEY_UP)
	{
		if (fdf->z_scale < 16.0)
			fdf->z_scale += Z_INCREMENT;
	}
	else if (key == KEY_DOWN)
	{
		if (fdf->z_scale > 0)
			fdf->z_scale -= Z_INCREMENT;
	}
}

static void	change_map(int key, t_fdf *fdf)
{
	if (key == KEY_LEFT)
	{
		if (fdf->current_map_index <= 0)
			fdf->current_map_index = fdf->map_count - 1;
		else
			fdf->current_map_index -= 1;
	}
	else if (key == KEY_RIGHT)
	{
		if (fdf->current_map_index >= fdf->map_count - 1)
			fdf->current_map_index = 0;
		else
			fdf->current_map_index += 1;
	}
}
