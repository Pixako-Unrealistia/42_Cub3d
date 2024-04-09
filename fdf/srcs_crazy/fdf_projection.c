/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:44:05 by tnualman          #+#    #+#             */
/*   Updated: 2023/10/06 12:39:53 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* The code for projection is separated to this file to accomodate future
   additions; currently only has isometric and parallel views implemented.
 */

void	fdf_projection(t_fdf *fdf, int *x, int *y, int z)
{
	int	old_x;

	if (!fdf->projection)
		return ;
	old_x = *x;
	*x = (old_x - *y) * cos(ISOMETRIC_ANGLE);
	*y = -z + (old_x + *y) * sin(ISOMETRIC_ANGLE);
}
