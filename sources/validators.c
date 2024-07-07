/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:07:54 by schongte          #+#    #+#             */
/*   Updated: 2024/07/07 21:28:38 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_validate_texture(t_parser *parser)
{
	if (parser->map.no == NULL || parser->map.so == NULL
		|| parser->map.we == NULL || parser->map.ea == NULL
		|| parser->map.f == NULL || parser->map.c == NULL)
		ft_throw("Missing texture", parser, NULL);
}

void	ft_validate_containment(t_parser *parser)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < parser->map.height)
	{
		if (parser->map.map[i][0] != '1'
		|| parser->map.map[i][parser->map.width - 1] != '1')
			ft_throw("Map is not surrounded by walls", parser, NULL);
		j = 0;
		while (j < parser->map.width)
		{
			c = parser->map.map[i][j];
			if (ft_strchr("01NSWE", c) == NULL)
				ft_throw("Map contains invalid character", parser, NULL);
			j++;
		}
		i++;
	}
}
