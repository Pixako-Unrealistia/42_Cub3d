/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:59:59 by schongte          #+#    #+#             */
/*   Updated: 2024/07/07 21:30:20 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSER_H
# define CUB3D_H

//Allowed
//• open, close, read, write,
//printf, malloc, free, perror,
//strerror, exit
//• All functions of the math
//library (-lm man man 3 math)
//• All functions of the Minilib

#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include "../libft/libft.h"


// Height will be 1...n, for example if the height is 5, the map will be 5 lines high
// Width will be 1...n+1, for example if the width is 5, the map will be 6 characters wide
typedef struct s_map
{
	int     height;
	int     width;
	char    *no;
	char    *so;
	char    *we;
	char    *ea;
	int     *f;
	int     *c;
	char    **map;
	int	 	start_x;
	int	 	start_y;
	char	start_dir;
}           t_map;

typedef struct s_parser
{
	t_map   map;
	int     map_alloc;
	char	*line;
	int		fd;
}           t_parser;

typedef struct s_for_loop
{
	int i;
	int j;
}           t_for_loop;

/* KEY values from the old minilibx are not used. */
// Linux
//  #  define KEY_W				119
//  #  define KEY_A				97
//  #  define KEY_S				115
//  #  define KEY_D				100

//  #  define KEY_UP  				65362
//  #  define KEY_LEFT  			65361
//  #  define KEY_RIGHT 			65363
//  #  define KEY_DOWN  			65364

//  #  define KEY_Q				113
//  #  define KEY_ESC  			65307

// Macos
//# define KEY_W				13
//# define KEY_A				0
//# define KEY_S				1
//# define KEY_D				2

//# define KEY_UP  				126
//# define KEY_LEFT  			123
//# define KEY_RIGHT 			124
//# define KEY_DOWN  			125

//# define KEY_Q				12
//# define KEY_ESC  			53

//# define FRONT				1
//# define LEFT					2
//# define RIGHT				3
//# define BACK					4

// utils.c
int		ft_strlen_nonl(char *str);
void	remove_one_nl(char **map);
void	ft_remove_spaces(char *str);
int		ft_abs(int n);
int		ft_is_line_empty(char *line);

// parser_map_utils.c
void	ft_safe_free(void *ptr);
void	ft_map_free(t_parser *parser);
void	ft_throw(char *str,t_parser *parser, char *line);
void	ft_map_alloc(t_parser *parser, size_t size);
void	ft_init_all(t_parser *parser);

// parser_map_corrections.c
void	flood_fill(t_parser *parser, int x, int y);
void	width_realloc(t_parser *parser);
void	fill_irregular_map(t_parser *parser);

// parser_validators.c
void	ft_validate_texture(t_parser *parser);
void	ft_validate_containment(t_parser *parser);

//parser_color.c
void	color_alloc(t_parser *parser, int **color);
void	color_loop(char **split_tmp, int **color, t_parser *parser, char *line);
void	ft_color_parser(t_parser *parser, char *line, int **color);


#endif 