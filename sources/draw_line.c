/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:19:18 by tnualman          #+#    #+#             */
/*   Updated: 2024/07/07 21:25:41 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Lifted and adapted from fdf. */

#include "cub3d.h"

static int		pixel_color(t_pixel step, t_pixel start, t_pixel end,
					t_pixel delta);
static double	pixel_ratio(int start, int end, int current);
static int		interpolate(int start, int end, double ratio);

// Using classical Bresenham's algorithm;
void	draw_line(mlx_image_t *img, t_pixel start, t_pixel end)
{
	t_pixel	step;
	t_pixel	delta;
	int		diff;
	int		tmp;

	delta.x = end.x - start.x;
	delta.y = end.y - start.y;
	diff = ft_abs_int(delta.x) - ft_abs_int(delta.y);
	step = start;
	while (step.x != end.x || step.y != end.y)
	{
		mlx_put_pixel(img, step.x, step.y,
			pixel_color(step, start, end, delta));
		tmp = diff * 2;
		if (tmp > -ft_abs_int(delta.y))
		{
			step.x += diy_int_sign(delta.x);
			diff -= ft_abs_int(delta.y);
		}
		if (tmp < ft_abs_int(delta.x))
		{
			step.y += diy_int_sign(delta.y);
			diff += ft_abs_int(delta.x);
		}
	}
}

static int	pixel_color(t_pixel step, t_pixel start, t_pixel end,
				t_pixel delta)
{
	int		r;
	int		g;
	int		b;
	int		a;
	double	ratio;

	if (delta.x > delta.y)
		ratio = pixel_ratio(start.x, end.x, step.x);
	else
		ratio = pixel_ratio(start.y, end.y, step.y);
	r = interpolate((start.color >> 24) & 0xFF,
			(end.color >> 24) & 0xFF, ratio);
	g = interpolate((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF, ratio);
	b = interpolate((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, ratio);
	a = interpolate(start.color & 0xFF, end.color & 0xFF, ratio);
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

static double	pixel_ratio(int start, int end, int current)
{
	if (start == end)
		return (1.0);
	return ((double)(current - start) / (double)(end - start));
}

static int	interpolate(int start, int end, double ratio)
{
	return ((int)((1 - ratio) * start + ratio * end));
}
