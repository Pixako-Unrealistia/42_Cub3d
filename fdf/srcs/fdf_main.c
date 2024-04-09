/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:11:25 by tnualman          #+#    #+#             */
/*   Updated: 2023/10/15 14:07:38 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_file_check(int argc, char **argv);

/*
void	fdf_print_maps(t_map **maps, int map_count);
void	fdf_print_map(t_map *map);
*/

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (!fdf_file_check(argc, argv))
		fdf_exit_on_error("Usage: only one map file (.fdf) as the argument.\n",
			1);
	fdf = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
	if (!fdf)
		fdf_exit_on_error("Error: initial allocation for the main fdf struct \
			failed! Exiting fdf.\n", 1);
	fdf->maps = (t_map **)ft_calloc(argc, sizeof(t_map *));
	if (fdf->maps)
		fdf->maps = fdf_create_maps(fdf->maps, argc - 1, argv);
	if (!fdf->maps)
	{
		free(fdf);
		fdf_exit_on_error("Error: map parsing failed! Exiting fdf.\n", 1);
	}
	fdf->map_count = argc - 1;
	fdf_window(fdf);
	return (0);
}

int	fdf_file_check(int argc, char **argv)
{
	int		fd;
	char	*dotstr;

	if (argc != 2)
		return (0);
	dotstr = ft_strrchr(argv[1], '.');
	if (!dotstr || ft_strncmp(dotstr, ".fdf", 4))
	{
		ft_dprintf(2, "%s is not a valid map file (.fdf) !\n", argv[1]);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_dprintf(2, "Cannot open %s !\n", argv[1]);
		return (0);
	}
	close(fd);
	return (1);
}

/*
void	fdf_print_maps(t_map **maps, int map_count)
{
	int	i;

	if (!maps)
		return ;
	i = 0;
	while (i < map_count)
	{
		ft_printf("Map %d :\n", i);
		fdf_print_map(maps[i++]);
	}
}

void	fdf_print_map(t_map *map)
{
	int	x;
	int	y;

	if (!map)
		return ;
	ft_printf("z_grid :\n");
	y = -1;
	while (++y < map->y_length)
	{
		x = -1;
		while (++x < map->x_length)
			ft_printf("%d ", (map->z_grid)[y][x]);
		ft_printf("\n");
	}
	ft_printf("color_grid :\n");
	y = -1;
	while (++y < map->y_length)
	{
		x = -1;
		while (++x < map->x_length)
			ft_printf("%x ", (map->color_grid)[y][x]);
		ft_printf("\n");
	}
}
*/
