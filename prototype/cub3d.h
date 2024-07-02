/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <schongte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:59:59 by schongte          #+#    #+#             */
/*   Updated: 2024/06/09 17:28:59 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
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

typedef struct s_map
{
	int     height;
	int     width;
	char    *no;
	char    *so;
	char    *we;
	char    *ea;
	int     f;
	int     c;
	char    **map;
	int	 	start_x;
	int	 	start_y;
}           t_map;

typedef struct s_parser
{
	t_map   map;
	int     map_alloc;
}           t_parser;

// Linux
 #  define KEY_W				119
 #  define KEY_A				97
 #  define KEY_S				115
 #  define KEY_D				100

 #  define KEY_UP  			65362
 #  define KEY_LEFT  		65361
 #  define KEY_RIGHT 		65363
 #  define KEY_DOWN  		65364

 #  define KEY_Q				113
 #  define KEY_ESC  			65307

// Macos
//# define KEY_W				13
//# define KEY_A				0
//# define KEY_S				1
//# define KEY_D				2

//# define KEY_UP  			126
//# define KEY_LEFT  			123
//# define KEY_RIGHT 			124
//# define KEY_DOWN  			125

//# define KEY_Q				12
//# define KEY_ESC  			53

//# define FRONT				1
//# define LEFT				2
//# define RIGHT				3
//# define BACK				4

// utils.c
int		ft_strlen_nonl(char *str);
void	remove_one_nl(char **map);
void	ft_remove_spaces(char *str);
int		ft_abs(int n);
int		ft_is_line_empty(char *line);

// map_utils.c
void	ft_safe_free(void *ptr);
void	ft_map_free(t_parser *parser);
void	ft_throw(char *str,t_parser *parser, char *line);
void	ft_map_alloc(t_parser *parser, size_t size);
void	ft_init_all(t_parser *parser);

// DO NOT MOVE THE REST OF INITIALISE_MAP

#endif 