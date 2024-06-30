/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:58:16 by tnualman          #+#    #+#             */
/*   Updated: 2024/06/30 21:01:49 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This is an attempt to create a basic raycaster, following the example from
* https://www.youtube.com/watch?v=gYRrGTC7GtA ,
* but using MLX42 instead of OpenGL (directly(?)). 
*/

/* COMPILE WITH:
* gcc main.c key_handle.c free_utils.c player.c minimap.c libmlx42.a -ldl -lglfw -pthread -lm -o cub3d
*/

#include "prototype.h"

//void	init_map(t_cub3d *cub3d, t_game *game)
//{
//	int	i;
//	int map[]=
//	{
//		1,1,1,1,1,1,1,1,
//		1,0,1,0,0,0,0,1,
//		1,0,1,0,0,0,0,1,
//		1,0,1,0,0,0,0,1,
//		1,0,0,0,0,0,0,1,
//		1,0,0,0,0,1,0,1,
//		1,0,0,0,0,0,0,1,
//		1,1,1,1,1,1,1,1,	
//	};
//	cub3d->map_width = 8;
//	cub3d->map_height = 8;
//	cub3d->map = malloc(sizeof(int *) * cub3d->map_height);
//	i = -1;
//	while (++i < cub3d->map_height)
//		cub3d->map[i] = malloc(sizeof(int) * cub3d->map_width);
//	i = -1;
//	while (++i < cub3d->map_height * cub3d->map_width)
//		cub3d->map[i / cub3d->map_width][i % cub3d->map_width] = map[i];
//	cub3d->player.xpos = 80.0;
//	cub3d->player.ypos = 80.0;
//	cub3d->player.fov_deg = 60.0;
//	cub3d->player.orient_deg = 0.0;
//	cub3d->player.delta_x = MOVE_SPEED;
//	cub3d->player.delta_y = 0.0;
//}

void	init_map(t_cub3d *cub3d, t_game *game)
{
	//int	i;
	//int map[]= 
	//{
	//	1,1,1,1,1,1,1,1,
	//	1,0,0,0,0,1,0,1,
	//	1,0,0,0,0,1,0,1,
	//	1,0,0,0,0,1,0,1,
	//	1,0,0,0,0,0,0,1,
	//	1,0,0,0,0,1,0,1,
	//	1,0,0,0,0,0,0,1,
	//	1,1,1,1,1,1,1,1,	
	//};
	//cub3d->map_width = 8;
	//cub3d->map_height = 8;
	//cub3d->map = malloc(sizeof(int *) * cub3d->map_height);
	//i = -1;
	//while (++i < cub3d->map_height)
	//	cub3d->map[i] = malloc(sizeof(int) * cub3d->map_width);
	//i = -1;
	//while (++i < cub3d->map_height * cub3d->map_width)
	//	cub3d->map[i / cub3d->map_width][i % cub3d->map_width] = map[i];
	//cub3d->player.x = SUBUNITS + 32.0;
	//cub3d->player.y = SUBUNITS + 32.0;
	//cub3d->player.fov_deg = 60.0;
	//cub3d->player.orient_deg = 0.0;
	//cub3d->player.delta_x = MOVE_SPEED;
	//cub3d->player.delta_y = 0.0;
	//cub3d->pix_per_seg = (int)(VIEW_W / cub3d->player.fov_deg);

	// ^^ Your original function, I resolved the merge conflict but in case there's problem roll it back.
	int	i;

	cub3d->map_width = game->map.width;
	cub3d->map_height = game->map.height;
	cub3d->map = malloc(sizeof(char *) * cub3d->map_height);
	i = -1;
	while (++i < cub3d->map_height)
		cub3d->map[i] = malloc(sizeof(char) * cub3d->map_width);
	i = -1;
	while (++i < cub3d->map_height * cub3d->map_width)
		cub3d->map[i / cub3d->map_width][i % cub3d->map_width] = game->map.map[i / game->map.width][i % game->map.width];
	cub3d->player.x = SUBUNITS + 32.0;
	cub3d->player.y = SUBUNITS + 32.0;
	cub3d->player.fov_deg = 60.0;
	cub3d->player.orient_deg = 0.0;
	cub3d->player.delta_x = MOVE_SPEED;
	cub3d->player.delta_y = 0.0;
	cub3d->color_floor = 0x1f1f1fff;
	cub3d->color_ceiling = 0x01babcff;
	cub3d->color_north = 0xbfbf00ff;
	cub3d->color_west = 0x0000ffff;
	cub3d->color_south = 0x00ff00ff;
	cub3d->color_east = 0xff0000ff;
}

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

void	init_mlx_stuff(t_cub3d *cub3d)
{
	int	i;

	cub3d->mlx = mlx_init(WIN_W, WIN_H, "cub3d-prototype", true);
	cub3d->mlx_2dimg_playerdot = mlx_new_image(cub3d->mlx, 16, 16);
	i = -1;
	while (++i < 16 * 16)
		mlx_put_pixel(cub3d->mlx_2dimg_playerdot, i / 16, i % 16,
			255 << 24 | 255 << 16 | 255);
	cub3d->mlx_2dimg = mlx_new_image(cub3d->mlx, SUBUNITS * cub3d->map_width,
		SUBUNITS * cub3d->map_height);
	cub3d->mlx_3dimg = mlx_new_image(cub3d->mlx, VIEW_W, VIEW_H);
	mlx_image_to_window(cub3d->mlx, cub3d->mlx_2dimg, 0 , 0);
	mlx_image_to_window(cub3d->mlx, cub3d->mlx_2dimg_playerdot, 0, 0);
	mlx_image_to_window(cub3d->mlx, cub3d->mlx_3dimg,
		SUBUNITS * cub3d->map_width , 0);
	// mlx_set_instance_depth(cub3d->mlx_2dimg_playerdot->instances, 1);
	// mlx_set_instance_depth(cub3d->mlx_2dimg->instances, 2);
}



void	game_loop(void *param)
{
	t_cub3d	*cub3d;
	
	cub3d = param;
	if (cub3d->no_key_pressed == 0)
	{
		cub3d->mlx_2dimg_playerdot->instances[0].x = cub3d->player.x - 8;
		cub3d->mlx_2dimg_playerdot->instances[0].y = cub3d->player.y - 8;
		draw_2d_map(cub3d);
		raycast(cub3d);
	}
	cub3d->no_key_pressed = 1;
}

int	cub3d_main(t_game *game)
{
	t_cub3d	*cub3d;
	
	cub3d = malloc(sizeof(t_cub3d));
	init_map(cub3d, game);
	init_mlx_stuff(cub3d);
	mlx_loop_hook(cub3d->mlx, &key_hook, cub3d);
	mlx_loop_hook(cub3d->mlx, &game_loop, cub3d);
	mlx_loop(cub3d->mlx);
	mlx_terminate(cub3d->mlx);
	free_all(cub3d);
	return (0);
}