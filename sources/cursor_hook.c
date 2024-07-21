/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:04:11 by tnualman          #+#    #+#             */
/*   Updated: 2024/07/21 21:15:47 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cursor_hook(double xpos, double ypos, void *param)
{
	t_cub3d		*cub3d;

	(void)ypos;
	cub3d = param;
	if (cub3d->mouselook_mode)
	{
		rotate_player(cub3d, (xpos - VIEW_W / 2) / 32, 1);
		mlx_set_mouse_pos(cub3d->mlx, VIEW_W / 2, VIEW_H / 2);
	}
}
