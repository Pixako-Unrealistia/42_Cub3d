/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_math_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:03:28 by tnualman          #+#    #+#             */
/*   Updated: 2024/07/05 17:42:47 by tnualman         ###   ########.fr       */
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

