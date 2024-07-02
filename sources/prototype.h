/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:08:22 by tnualman          #+#    #+#             */
/*   Updated: 2024/07/02 20:00:53 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This is an attempt to create a basic raycaster, following the example from
 * https://www.youtube.com/watch?v=gYRrGTC7GtA ,
 * but using MLX42 instead of OpenGL (directly(?)). 
 */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "MLX42.h"
# include "cub3d.h"

# include <stdio.h>

# define PI 3.14159265358979323846

# define WIN_W			1920
# define WIN_H			1080
# define VIEW_W			1280
# define VIEW_H			960
# define SUBUNITS		64

# define MOVE_SPEED		2.0
# define ROTATE_SPEED	1.0

typedef struct s_player
{
	float		x;
	float		y;
	float		fov_deg;
	float		orient_deg;
	float		delta_x;
	float		delta_y;
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

typedef struct s_raycast
{
	t_ray	ray[2];
	int		selected_ray;
	int		pix_per_seg;
	int		ray_dist;
	int		seg_height;
	int		seg_offset;
	t_pixel col_top;
	t_pixel	col_wall_top;
	t_pixel	col_floor_top;
}	t_raycast;

typedef struct s_cub3d
{
	mlx_t		*mlx;
	mlx_image_t	*mlx_2dimg_playerdot;
	mlx_image_t	*mlx_2dimg;
	mlx_image_t	*mlx_3dimg;
	char		**map;
	int			map_width;
	int			map_height;
	t_player	player;
	int			no_key_pressed;
	int			color_floor;
	int			color_ceiling;
	int			color_north;
	int			color_west;
	int			color_south;
	int			color_east;
}	t_cub3d;

void	key_hook(void *cub3d);

void	free_all(t_cub3d *cub3d);

// player movement
void	rotate_player(t_cub3d *cub3d, float angle, int clockwise);
void    move_forward(t_cub3d *cub3d);
void    move_backward(t_cub3d *cub3d);
void	strafe_left(t_cub3d *cub3d);
void	strafe_right(t_cub3d *cub3d);

// draw_line
void	draw_line(mlx_image_t *img, t_pixel start, t_pixel end);
int		ft_abs_int(int value);
int		diy_int_sign(int value);

// raycast_utils
float	angle_inrange_deg(float angle);
float	angle_inrange_rad(float angle);
float	deg_to_rad(float angle);
float   ray_distance(t_player p, t_ray r);
void	draw_pixel_column(mlx_image_t *img, t_pixel pix, int len);

// raycast_1ray
void	raycast_1h(t_cub3d *cub3d, t_ray *r, float a);
void	raycast_1v(t_cub3d *cub3d, t_ray *r, float a);
void	draw_1ray(mlx_image_t *img, t_player p, t_ray r, int color);

// raycast
void	raycast(t_cub3d *cub3d);
//main.c
int		cub3d_main(t_parser *parser);

#endif