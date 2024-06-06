/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:57:15 by tnualman          #+#    #+#             */
/*   Updated: 2024/06/01 15:22:39 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototype.h"

void	free_all(t_cub3d *cub3d)
{
    int i;

    i = -1;
    while (++i < cub3d->map_height)
        free(cub3d->map[i]);
    free(cub3d->map);
    free(cub3d);
}