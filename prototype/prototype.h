/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:08:22 by tnualman          #+#    #+#             */
/*   Updated: 2024/06/07 19:18:25 by tnualman         ###   ########.fr       */
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

// MLX Linux keyboard values

# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100

# define KEY_UP  	65362
# define KEY_LEFT  	65361
# define KEY_RIGHT 	65363
# define KEY_DOWN  	65364

# define KEY_Q		113
# define KEY_ESC  	65307

// Other defines

# define M_PI 3.14159265358979323846

# define WIN_W			1280
# define WIN_H			720
# define SUBUNITS		64
# define MOVE_SPEED		2.0
# define ROTATE_SPEED	5.0

typedef struct s_player
{
	float		xpos;
	float		ypos;
	float		fov_deg;
	float		orient_deg;
	float		delta_x;
	float		delta_y;
}	t_player;

typedef struct s_cub3d
{
	mlx_t		*mlx;
	mlx_image_t	*mlx_2dimg_playerdot;
	mlx_image_t	*mlx_2dimg;
	// mlx_image_t	*mlx_3dimg;
	int			**map;
	int			map_width;
	int			map_height;			
	t_player	player;
}	t_cub3d;

void	key_hook(void *cub3d);

void	free_all(t_cub3d *cub3d);

void	rotate_player(t_cub3d *cub3d, float angle, int clockwise);
void    move_forward(t_cub3d *cub3d);
void    move_backward(t_cub3d *cub3d);
void	strafe_left(t_cub3d *cub3d);
void	strafe_right(t_cub3d *cub3d);

#endif