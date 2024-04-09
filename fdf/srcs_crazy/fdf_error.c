/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:45:49 by tnualman          #+#    #+#             */
/*   Updated: 2023/10/12 11:14:34 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_map_fill_error(t_map *map, int fill_errno, char *file,
			int map_index)
{
	if (fill_errno == 1)
		ft_dprintf(2, "File %s is an empty map!\n", file);
	else if (fill_errno == 2)
		ft_dprintf(2, "Allocation for map[%d] failed!\n", map_index);
	else if (fill_errno == 3)
		ft_dprintf(2, "Failed to open %s!\n", file);
	else if (fill_errno == 4)
		ft_dprintf(2, "Failed to parse map[%d] due to a failed inner loop \
			allocation!\n", map_index);
	fdf_free_map(map);
}

void	fdf_exit_on_error(char *message, int error_code)
{
	ft_dprintf(2, message);
	exit(error_code);
}
