/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:03:28 by tnualman          #+#    #+#             */
/*   Updated: 2024/06/20 22:19:53 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototype.h"

float	angle_inrange_deg(float angle)
{
	while (angle < 0.0)
		angle += 360.0;
	while (angle >= 360.0)
		angle -= 360.0;
	return (angle);
}

float	angle_inrange_rad(float angle)
{
	while (angle < 0.0)
		angle += 2 * PI;
	while (angle >= 2 * PI)
		angle -= 2 * PI;
	return (angle);
}

float	deg_to_rad(float angle)
{
	return (angle / 180.0 * PI);
}
float	ray_distance(t_player p, t_ray r)
{
	return (sqrt((r.x - p.x) * (r.x - p.x) + (r.y - p.y) * (r.y - p.y)));
}

void	draw_1ray(mlx_image_t *img, t_player p, t_ray r, int color)
{
	t_pixel	pixel[2];

	pixel[0].x = p.x;
	pixel[0].y = p.y;
	pixel[0].color = color;
	pixel[1].x = r.x;
	pixel[1].y = r.y;
	pixel[1].color = color;
	draw_line(img, pixel[0], pixel[1]);
}