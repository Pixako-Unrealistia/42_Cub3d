/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:06:45 by schongte          #+#    #+#             */
/*   Updated: 2023/08/21 16:06:46 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen_nonl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

void	remove_one_nl(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	if (map[0][i - 1] == '\n')
		map[0][i - 1] = '\0';
}

void	ft_remove_spaces(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
