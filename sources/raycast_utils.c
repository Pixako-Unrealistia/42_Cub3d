/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:03:28 by tnualman          #+#    #+#             */
/*   Updated: 2024/07/07 21:27:53 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Not sure if this will be useful...
void	cub3d_put_pixel(mlx_image_t *img, t_pixel pix)
{
	mlx_put_pixel(img, pix.x, pix.y, pix.color);
}

void	draw_pixel_column(mlx_image_t *img, t_pixel pix, int len)
{
	int	i;

	if (len <= 0)
		return ;
	i = -1;
	while (++i < len)
		mlx_put_pixel(img, pix.x, pix.y + i, pix.color);
}
