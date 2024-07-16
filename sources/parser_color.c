/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <schongte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:15:06 by schongte          #+#    #+#             */
/*   Updated: 2024/07/14 14:15:06 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	before_throw(char *w, t_parser *parser, char *line, char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i] != NULL)
	{
		free(to_free[i]);
		i++;
	}
	if (to_free != NULL)
		free(to_free);
	printf("\033[31m%s\033[0m\n", line);
	ft_throw(w, parser, parser->line);
}

void	color_alloc(t_parser *parser, int **color)
{
	if (*color != NULL)
		ft_throw("Color already realised", parser, parser->line);
	*color = (int *)malloc(3 * sizeof(int));
	if (*color == NULL)
		ft_throw("Memory allocation failed", parser, NULL);
}

void	color_loop(char **split_tmp, int **color, t_parser *parser, char *line)
{
	int	tmp;
	int	valuecount;

	valuecount = 0;
	while (split_tmp[valuecount] != NULL)
	{
		tmp = ft_atoi(split_tmp[valuecount]);
		if (tmp < 0 || tmp > 255)
			before_throw("Invalid color range", parser, line, split_tmp);
		if (valuecount > 2)
			before_throw("Too many values for RGB", parser, line, split_tmp);
		(*color)[valuecount++] = tmp;
	}
	if (valuecount != 3)
		before_throw("Invalid argc for RGB", parser, line, split_tmp);
}

void	ft_color_parser(t_parser *parser, char *line, int **color)
{
	int		i;
	char	**split_tmp;

	i = 0;
	color_alloc(parser, color);
	while (line[i] == ' ' || !ft_isdigit(line[i]))
		i++;
	line = &line[i];
	split_tmp = ft_split(line, ',');
	if (split_tmp == NULL)
		ft_throw("Memory allocation failed", parser, line);
	color_loop(split_tmp, color, parser, line);
	i = 0;
	while (split_tmp[i] != NULL)
		free(split_tmp[i++]);
	free(split_tmp);
}
