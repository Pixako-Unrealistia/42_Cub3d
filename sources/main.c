/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:58:16 by tnualman          #+#    #+#             */
/*   Updated: 2024/07/18 20:13:55 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_2d_map(t_cub3d *cub3d)
{
	int	i[3];
	int	color;

	i[0] = -1;
	while (++i[0] < cub3d->map_width * cub3d->map_height)
	{
		if (cub3d->map[i[0] / cub3d->map_width][i[0] % cub3d->map_width] == '1')
			color = 255 << 24 | 255 << 16 | 255 << 8 | 255;
		else
			color = 255;
		i[1] = -1;
		while (++i[1] < SUBUNITS)
		{
			i[2] = -1;
			while (++i[2] < SUBUNITS)
				mlx_put_pixel(cub3d->mlx_2dimg,
					SUBUNITS * (i[0] % cub3d->map_width) + i[2],
					SUBUNITS * (i[0] / cub3d->map_width) + i[1], color);
		}
	}
}

void	game_loop(void *param)
{
	t_cub3d	*cub3d;

	cub3d = param;
	if (cub3d->new_frame == 1)
	{
		cub3d->mlx_2dimg_playerdot->instances[0].x = cub3d->player.x - 8;
		cub3d->mlx_2dimg_playerdot->instances[0].y = cub3d->player.y - 8;
		draw_2d_map(cub3d);
		raycast(cub3d);
	}
	cub3d->new_frame = 0;
}

int	cub3d_main(t_parser *parser)
{
	t_cub3d	*cub3d;

	cub3d = malloc(sizeof(t_cub3d));
	init_map(cub3d, parser);
	printf("%s\n", parser->map.no);
	init_textures(cub3d, parser);
	init_player(cub3d, parser);
	init_mlx_stuff(cub3d);
	mlx_loop_hook(cub3d->mlx, &key_hook, cub3d);
	mlx_loop_hook(cub3d->mlx, &game_loop, cub3d);
	mlx_loop(cub3d->mlx);
	mlx_terminate(cub3d->mlx);
	free_cub3d(cub3d);
	return (0);
}
