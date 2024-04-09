/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:19:18 by tnualman          #+#    #+#             */
/*   Updated: 2023/10/06 15:05:20 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_pixel_put(t_fdf *fdf, t_coord pixel, int color);
static int		fdf_pixel_color(t_coord pixel, t_coord start, t_coord end,
					t_coord delta);
static double	fdf_pixel_ratio(int start, int end, int current);
static int		fdf_color_interpolate(int start, int end, double ratio);

// Using classical Bresenham's algorithm;
void	fdf_draw_line(t_fdf *fdf, t_coord start, t_coord end)
{
	t_coord	pixel;
	t_coord	delta;
	int		diff;
	int		tmp;

	delta.x = end.x - start.x;
	delta.y = end.y - start.y;
	diff = ft_abs_int(delta.x) - ft_abs_int(delta.y);
	pixel = start;
	while (pixel.x != end.x || pixel.y != end.y)
	{
		fdf_pixel_put(fdf, pixel, fdf_pixel_color(pixel, start, end, delta));
		tmp = diff * 2;
		if (tmp > -ft_abs_int(delta.y))
		{
			pixel.x += diy_int_sign(delta.x);
			diff -= ft_abs_int(delta.y);
		}
		if (tmp < ft_abs_int(delta.x))
		{
			pixel.y += diy_int_sign(delta.y);
			diff += ft_abs_int(delta.x);
		}
	}
}

static void	fdf_pixel_put(t_fdf *fdf, t_coord pixel, int color)
{
	char	*pixel_addr;

	if (pixel.y >= WIN_HEIGHT || pixel.x >= WIN_WIDTH
		|| pixel.y < 0 || pixel.x < 0)
		return ;
	pixel_addr = fdf->img_data_addr + (pixel.y * fdf->img_size_line)
		+ (pixel.x * (fdf->img_bpp / 8));
	*(unsigned int *)pixel_addr = color;
}

static int	fdf_pixel_color(t_coord pixel, t_coord start, t_coord end,
				t_coord delta)
{
	int		r;
	int		g;
	int		b;
	double	ratio;

	if (delta.x > delta.y)
		ratio = fdf_pixel_ratio(start.x, end.x, pixel.x);
	else
		ratio = fdf_pixel_ratio(start.y, end.y, pixel.y);
	r = fdf_color_interpolate((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF, ratio);
	g = fdf_color_interpolate((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, ratio);
	b = fdf_color_interpolate(start.color & 0xFF, end.color & 0xFF, ratio);
	return ((r << 16) | (g << 8) | b);
}

static double	fdf_pixel_ratio(int start, int end, int current)
{
	if (start == end)
		return (1.0);
	return ((double)(current - start) / (double)(end - start));
}

static int	fdf_color_interpolate(int start, int end, double ratio)
{
	return ((int)((1 - ratio) * start + ratio * end));
}
