/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:11:01 by tnualman          #+#    #+#             */
/*   Updated: 2023/10/15 14:08:04 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_linux/mlx.h"

# include "../libft_core_and_diy/srcs/libft.h"
# include "../libft_printf/srcs/ft_printf.h"

# include <fcntl.h>
# include <math.h>

# define WIN_HEIGHT 		900
# define WIN_WIDTH 			1600
# define ISOMETRIC_ANGLE	0.523599
# define MOVE_INCREMENT 	10
# define ROTATION_INCREMENT 0.02
# define ZOOM_INCREMENT 	0.25
# define Z_INCREMENT 		0.1
# define Z_COLORING			0
# define DEFAULT_WIRE 		0x7F7F7F
# define WHITE				0xFFFFFF

# ifdef __linux__

#  include "../minilibx_linux/mlx.h"

#  define KEY_ESC	65307
#  define KEY_W 	119
#  define KEY_A 	97
#  define KEY_S 	115
#  define KEY_D 	100
#  define KEY_Z 	122
#  define KEY_X 	120
#  define KEY_C 	99
#  define KEY_V		118
#  define KEY_B 	98
#  define KEY_N		110
#  define KEY_P		112
#  define KEY_R		114
#  define KEY_MINUS 45
#  define KEY_PLUS	61
#  define KEY_DOWN	65364
#  define KEY_UP	65362
#  define KEY_LEFT	65361
#  define KEY_RIGHT	65363

# else

#  include "../minilibx_macos/mlx.h"

#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_Z 6
#  define KEY_X 7
#  define KEY_C 8
#  define KEY_V 9
#  define KEY_B 11
#  define KEY_N 45
#  define KEY_P 35
#  define KEY_R 15
#  define KEY_MINUS 27
#  define KEY_PLUS 24
#  define KEY_DOWN 125
#  define KEY_UP 126
#  define KEY_LEFT 123
#  define KEY_RIGHT 124

# endif

typedef struct s_coord
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_coord;

typedef struct s_fcoord
{
	float	x;
	float	y;
	float	z;
}	t_fcoord;

typedef struct s_screen
{
	int	x;
	int	y;
	int	color;
}	t_screen;

typedef struct s_map
{
	int	x_length;
	int	y_length;
	int	**z_grid;
	int	z_min;
	int	z_max;
	int	**color_grid;
}	t_map;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*window_ptr;
	void	*img_ptr;
	char	*img_data_addr;
	int		img_bpp;
	int		img_size_line;
	int		img_endian;
	t_map	**maps;
	int		map_count;
	int		current_map_index;
	int		projection;
	int		offset_x;
	int		offset_y;
	float	zoom_scale;
	float	z_scale;
	float	view_angle_x;
	float	view_angle_y;
	float	view_angle_z;
}	t_fdf;

int		fdf_file_check(int argc, char **argv);

t_map	**fdf_create_maps(t_map **maps, int map_count, char **argv);

int		fdf_map_fill_init(t_map *map);
int		fdf_map_fill_loop(t_map *map, int fd);

void	fdf_free_map(t_map *map);
void	fdf_free_maps(t_map **maps, int map_count);
void	free_fdf(t_fdf *fdf);

void	fdf_exit_on_error(char *message, int error_code);
void	fdf_map_fill_error(t_map *map, int fill_errno, char *file,
			int map_index);

/*
void	fdf_print_maps(t_map **maps, int map_count);
void	fdf_print_map(t_map *map);
*/

void	fdf_window(t_fdf *fdf);
void	fdf_defaults(t_fdf *fdf);
int		fdf_close_window(t_fdf *fdf);

void	fdf_draw(t_fdf *fdf);

void	fdf_draw_line(t_fdf *fdf, t_coord start, t_coord end);

void	fdf_rotate(t_fdf *fdf, t_coord *coord);

void	fdf_projection(t_fdf *fdf, int *x, int *y, int z);

int		fdf_keyboard_handle(int key, t_fdf *fdf);

#endif