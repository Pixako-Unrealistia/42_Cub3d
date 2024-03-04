/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <schongte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:59:59 by schongte          #+#    #+#             */
/*   Updated: 2024/03/01 14:59:59 by schongte         ###   ########.fr       */
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
	int     res_x;
	int     res_y;
	char    *no;
	char    *so;
	char    *we;
	char    *ea;
	char    *s;
	int     f;
	int     c;
	char    **map;
}           t_map;

typedef struct s_game
{
	t_map   map;
	int     map_alloc;
}           t_game;



#endif 