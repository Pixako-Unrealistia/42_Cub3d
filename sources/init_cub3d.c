/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:04:33 by tnualman          #+#    #+#             */
/*   Updated: 2024/07/20 20:49:46 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_cub3d *cub3d, t_parser *parser)
{
	int	i;

	cub3d->map_width = parser->map.width;
	cub3d->map_height = parser->map.height;
	cub3d->map = malloc(sizeof(char *) * cub3d->map_height);
	i = -1;
	while (++i < cub3d->map_height)
		cub3d->map[i] = malloc(sizeof(char) * cub3d->map_width);
	i = -1;
	while (++i < cub3d->map_height * cub3d->map_width)
		cub3d->map[i / cub3d->map_width][i % cub3d->map_width]
			= parser->map.map[i / parser->map.width][i % parser->map.width];
	cub3d->color_floor = parser->map.f[0] << 24 | parser->map.f[1] << 16
		| parser->map.f[2] << 8 | 255;
	cub3d->color_ceiling = parser->map.c[0] << 24 | parser->map.c[1] << 16
		| parser->map.c[2] << 8 | 255;
}

void	init_textures(t_cub3d *cub3d, t_parser *parser)
{
	cub3d->texture_north = mlx_load_png(parser->map.no);
	if (!cub3d->texture_north)
		ft_putstr_fd("Error: cannot load texture for northern wall!\n", 2);
	cub3d->texture_west = mlx_load_png(parser->map.we);
	if (!cub3d->texture_west)
		ft_putstr_fd("Error: cannot load texture for western wall!\n", 2);
	cub3d->texture_south = mlx_load_png(parser->map.so);
	if (!cub3d->texture_south)
		ft_putstr_fd("Error: cannot load texture for southern wall!\n", 2);
	cub3d->texture_east = mlx_load_png(parser->map.ea);
	if (!cub3d->texture_east)
		ft_putstr_fd("Error: cannot load texture for eastern wall!\n", 2);
	if (!cub3d->texture_north || !cub3d->texture_west
		|| !cub3d->texture_south || !cub3d->texture_east)
	{
		ft_putstr_fd("Cleaning up and exiting...\n", 2);
		free_cub3d(cub3d);
		ft_map_free(parser);
		exit(EXIT_FAILURE);
	}
}

void	init_player(t_cub3d *cub3d, t_parser *parser)
{
	t_player	*player;

	player = &cub3d->player;
	player->x = (parser->map.start_x - 1) * SUBUNITS + SUBUNITS / 2.0;
	player->y = (parser->map.start_y - 1) * SUBUNITS + SUBUNITS / 2.0;
	player->fov_deg = DEFAULT_FOV;
	player->orient_deg = 0.0;
	if (parser->map.start_dir == 'N')
		player->orient_deg = 270.0;
	if (parser->map.start_dir == 'W')
		player->orient_deg = 180.0;
	if (parser->map.start_dir == 'S')
		player->orient_deg = 90.0;
	rotate_player(cub3d, 0, 0);
	player->move_dir = 0;
	player->strafe_dir = 0;
	player->rotate_dir = 0;
}

void	init_mlx_stuff(t_cub3d *cub3d)
{
	int	i;

	cub3d->mlx = mlx_init(WIN_W, WIN_H, "cub3D", true);
	cub3d->mlx_2dimg_playerdot = mlx_new_image(cub3d->mlx, 16, 16);
	i = -1;
	while (++i < 16 * 16)
		mlx_put_pixel(cub3d->mlx_2dimg_playerdot, i / 16, i % 16, 0xffff00ff);
	cub3d->mlx_2dimg = mlx_new_image(cub3d->mlx, SUBUNITS / 2
			* cub3d->map_width, SUBUNITS / 2 * cub3d->map_height);
	cub3d->mlx_3dimg = mlx_new_image(cub3d->mlx, VIEW_W, VIEW_H);
	mlx_image_to_window(cub3d->mlx, cub3d->mlx_3dimg, 0, 0);
	mlx_image_to_window(cub3d->mlx, cub3d->mlx_2dimg, 0, VIEW_H);
	mlx_image_to_window(cub3d->mlx, cub3d->mlx_2dimg_playerdot, 0, VIEW_H);
}
