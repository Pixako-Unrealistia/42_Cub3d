/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:58:16 by tnualman          #+#    #+#             */
/*   Updated: 2024/07/20 20:52:01 by tnualman         ###   ########.fr       */
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
			color = 0xffffffff;
		else
			color = 0x000000ff;
		i[1] = -1;
		while (++i[1] < SUBUNITS / 2)
		{
			i[2] = -1;
			while (++i[2] < SUBUNITS / 2)
				mlx_put_pixel(cub3d->mlx_2dimg,
					SUBUNITS / 2 * (i[0] % cub3d->map_width) + i[2],
					SUBUNITS / 2 * (i[0] / cub3d->map_width) + i[1], color);
		}
	}
}

void	game_loop(void *param)
{
	t_cub3d	*cub3d;

	cub3d = param;
	if (cub3d->new_frame == 1)
	{
		cub3d->mlx_2dimg_playerdot->instances[0].x = cub3d->player.x / 2 - 8;
		cub3d->mlx_2dimg_playerdot->instances[0].y = cub3d->player.y / 2 - 8
			+ VIEW_H;
		draw_2d_map(cub3d);
		raycast(cub3d);
	}
	cub3d->new_frame = 0;
}

int	main(int argc, char **argv)
{
	t_cub3d		cub3d;
	t_parser	parser;

	parser_main(argc, argv, &parser);
	init_map(&cub3d, &parser);
	init_textures(&cub3d, &parser);
	init_player(&cub3d, &parser);
	init_mlx_stuff(&cub3d);
	ft_map_free(&parser);
	mlx_loop_hook(cub3d.mlx, &key_hook, &cub3d);
	mlx_loop_hook(cub3d.mlx, &game_loop, &cub3d);
	mlx_loop(cub3d.mlx);
	mlx_terminate(cub3d.mlx);
	free_cub3d(&cub3d);
	return (0);
}
