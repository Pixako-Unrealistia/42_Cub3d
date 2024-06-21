/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:43:15 by tnualman          #+#    #+#             */
/*   Updated: 2024/06/21 17:13:43 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototype.h"

void    draw_wall_segment(t_cub3d *cub3d, float dist, int i, int color);

void    blacken_image(mlx_image_t *img)
{
    int i;

    i = -1;
    while (++i < (int)(img->width * img->height))
		mlx_put_pixel(img, i % img->width, i / img->width, 255);
}

void	raycast(t_cub3d *cub3d)
{
	t_ray	r[2];
	float	dist;
    int     color;
	int		i;

	blacken_image(cub3d->mlx_3dimg);
    i = -(int)cub3d->player.fov_deg / 2 - 1;
	while (++i < (int)cub3d->player.fov_deg / 2)
	{
		raycast_1h(cub3d, r + 0, i);
		raycast_1v(cub3d, r + 1, i);
		if (r[0].dist <= r[1].dist)
		{
            dist = r[0].dist;
			draw_1ray(cub3d->mlx_2dimg, cub3d->player, r[0], 255 << 16 | 255);
            color = 255 << 8 | 255;
		}
		else
		{
			dist = r[1].dist;
			draw_1ray(cub3d->mlx_2dimg, cub3d->player, r[1], 255 << 16 | 255);
            color = 255 << 24 | 255 << 16 | 255;
		}
        draw_wall_segment(cub3d, dist, i, color);
	}
}

void    draw_wall_segment(t_cub3d *cub3d, float dist, int i, int color)
{
    float   seg_height;
    float   seg_offset;
    t_pixel pixel[2];
    int     j;

    dist *= cos(deg_to_rad((float)i));
    i += (int)cub3d->player.fov_deg / 2;
    seg_height = SUBUNITS * VIEW_H / dist;
    if (seg_height > VIEW_H)
        seg_height = VIEW_H;
    seg_offset = (VIEW_H - seg_height) / 2;
    j = -1;
    while (++j < cub3d->pix_per_seg)
    {
        pixel[0].x = i * cub3d->pix_per_seg + j;
        pixel[0].y = seg_offset;
        pixel[0].color = color;
        pixel[1].x = i * cub3d->pix_per_seg + j;
        pixel[1].y = seg_height + seg_offset;
        pixel[1].color = color;
        draw_line(cub3d->mlx_3dimg, pixel[0], pixel[1]);
    }
}
