/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:08:22 by tnualman          #+#    #+#             */
/*   Updated: 2024/07/21 21:09:52 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "cub3d_parser.h"

# include <stdio.h>

# define PI 3.14159265358979323846
# define SQRT_HALF 0.70710678118

# define WIN_W			3200
# define WIN_H			2400
# define VIEW_W			1920
# define VIEW_H			1440

# define DEFAULT_FOV	60.0
# define SUBUNITS		64
# define RAYS_PER_DEG	4
# define MOVE_SPEED		4.0
# define ROTATE_SPEED	1.5

typedef struct s_player
{
	float	x;
	float	y;
	float	fov_deg;
	float	orient_deg;
	float	delta_x;
	float	delta_y;
	int		move_dir;
	int		strafe_dir;
	int		rotate_dir;	
}	t_player;

typedef struct s_pixel
{
	int	x;
	int	y;
	int	color;
}	t_pixel;

typedef struct s_ray
{
	float	x;
	float	y;
	float	angle_deg;
	float	angle_tan;
	float	x_offset;
	float	y_offset;
	int		x_map;
	int		y_map;
	int		step;
	float	dist;
}	t_ray;

// ty stands for texture_y .
typedef struct s_raycast
{
	t_ray	ray[2];
	int		selected_ray;
	int		pix_per_seg;
	int		ray_dist;
	int		seg_height;
	int		seg_offset;
	float	ty_step;
	float	ty_offset;
	t_pixel	col_top;
	t_pixel	col_wall_top;
	t_pixel	col_floor_top;
}	t_raycast;

typedef struct s_cub3d
{
	mlx_t			*mlx;
	mlx_image_t		*mlx_2dimg_playerdot;
	mlx_image_t		*mlx_2dimg;
	mlx_image_t		*mlx_3dimg;
	char			**map;
	int				map_width;
	int				map_height;
	t_player		player;
	int				new_frame;
	int				color_floor;
	int				color_ceiling;
	mlx_texture_t	*texture_north;
	mlx_texture_t	*texture_west;
	mlx_texture_t	*texture_south;
	mlx_texture_t	*texture_east;
	int				mouselook_mode;
}	t_cub3d;

// Hooks
void	key_hook(void *cub3d);
void	key_hook_l(mlx_key_data_t keydata, void *param);
void	cursor_hook(double xpos, double ypos, void *param);

void	free_cub3d(t_cub3d *cub3d);

// init_cub3d.c
void	init_map(t_cub3d *cub3d, t_parser *parser);
void	init_textures(t_cub3d *cub3d, t_parser *parser);
void	init_player(t_cub3d *cub3d, t_parser *parser);
void	init_mlx_stuff(t_cub3d *cub3d);

// player movement.c
void	rotate_player(t_cub3d *cub3d, float angle, int clockwise);
void	move_forward(t_cub3d *cub3d, float factor);
void	move_backward(t_cub3d *cub3d, float factor);
void	strafe_left(t_cub3d *cub3d, float factor);
void	strafe_right(t_cub3d *cub3d, float factor);

// draw_line.c
void	draw_line(mlx_image_t *img, t_pixel start, t_pixel end);
int		ft_abs_int(int value);
int		diy_int_sign(int value);

// raycast_math_utils.c
float	angle_inrange_deg(float angle);
float	angle_inrange_rad(float angle);
float	deg_to_rad(float angle);
float	ray_distance(t_player p, t_ray r);

// raycast_utils.c
void	draw_pixel_column(mlx_image_t *img, t_pixel pix, int len);

// raycast_1ray.c
void	raycast_1h(t_cub3d *cub3d, t_ray *r, float a);
void	raycast_1v(t_cub3d *cub3d, t_ray *r, float a);
void	draw_1ray(mlx_image_t *img, t_player p, t_ray r, int color);

// raycast_wall.c
void	draw_wall_column(t_cub3d *cub3d, t_raycast rc);

// raycast.c
void	raycast(t_cub3d *cub3d);

// parser_main.c
int		parser_main(int argc, char **argv, t_parser *parser);

#endif