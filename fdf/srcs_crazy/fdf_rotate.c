/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:26:13 by tnualman          #+#    #+#             */
/*   Updated: 2023/10/15 14:08:20 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* SOURCE: https://en.wikipedia.org/wiki/Rotation_matrix#General_3D_rotations
 * Using the convention of "intrinsic rotation", where :
 * "Alpha" represents the rotation of the z-axis (yaw) (angle.z),
 * "Beta" represents the rotation of the for the y-axis (pitch) (angle.y), and
 * "Gamma" represents the rotation of the for the x-axis (roll) (angle.x).
 * trig[6] pre-computes the trigonometric values.
 * "cor" stands for "center of rotation.) (In this fdf project, for z, it's 0)
 */
static void	fdf_rotate_trig(t_fdf *fdf, float trig[6]);
static int	fdf_rotate_x(t_fcoord old, t_fcoord cor, float trig[6]);
static int	fdf_rotate_y(t_fcoord old, t_fcoord cor, float trig[6]);
static int	fdf_rotate_z(t_fcoord old, t_fcoord cor, float trig[6]);

void	fdf_rotate(t_fdf *fdf, t_coord *coord)
{
	t_fcoord	old;
	t_fcoord	cor;
	t_map		*map;
	float		trig[6];

	map = fdf->maps[fdf->current_map_index];
	cor.x = fdf->zoom_scale * (map->x_length - 1) / 2;
	cor.y = fdf->zoom_scale * (map->y_length - 1) / 2;
	old.x = coord->x - cor.x;
	old.y = coord->y - cor.y;
	old.z = coord->z;
	fdf_rotate_trig(fdf, trig);
	coord->x = fdf_rotate_x(old, cor, trig);
	coord->y = fdf_rotate_y(old, cor, trig);
	coord->z = fdf_rotate_z(old, cor, trig);
}

static void	fdf_rotate_trig(t_fdf *fdf, float trig[6])
{
	float	alpha;
	float	beta;
	float	gamma;

	alpha = fdf->view_angle_z;
	beta = fdf->view_angle_y;
	gamma = fdf->view_angle_x;
	trig[0] = sin(alpha);
	trig[1] = sin(beta);
	trig[2] = sin(gamma);
	trig[3] = cos(alpha);
	trig[4] = cos(beta);
	trig[5] = cos(gamma);
}

static int	fdf_rotate_x(t_fcoord old, t_fcoord cor, float trig[6])
{
	float	x_term;
	float	y_term;
	float	z_term;

	x_term = trig[3] * trig[4] * old.x;
	y_term = (trig[3] * trig[1] * trig[2] - trig[0] * trig[5]) * old.y;
	z_term = (trig[3] * trig[1] * trig[5] + trig[0] * trig[5]) * old.z;
	return ((int)(x_term + y_term + z_term + cor.x));
}

static int	fdf_rotate_y(t_fcoord old, t_fcoord cor, float trig[6])
{
	float	x_term;
	float	y_term;
	float	z_term;

	x_term = trig[0] * trig[4] * old.x;
	y_term = (trig[0] * trig[1] * trig[2] + trig[3] * trig[5]) * old.y;
	z_term = (trig[0] * trig[1] * trig[5] - trig[3] * trig[2]) * old.z;
	return ((int)(x_term + y_term + z_term + cor.y));
}

static int	fdf_rotate_z(t_fcoord old, t_fcoord cor, float trig[6])
{
	float	x_term;
	float	y_term;
	float	z_term;

	x_term = -trig[1] * old.x;
	y_term = trig[4] * trig[2] * old.y;
	z_term = trig[4] * trig[5] * old.z;
	return ((int)(x_term + y_term + z_term));
}
