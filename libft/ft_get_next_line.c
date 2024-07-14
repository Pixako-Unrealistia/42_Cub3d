/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <schongte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:11:34 by schongte          #+#    #+#             */
/*   Updated: 2024/07/03 23:42:47 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*main_join(char *s1, char *s2)
{
	char	*tempo;

	tempo = util_strjoin(s1, s2);
	free(s1);
	return (tempo);
}

char	*main_parse_next(char *s)
{
	int		i1;
	int		i2;
	char	*line;

	i1 = 0;
	while (s[i1] && s[i1] != '\n')
		i1++;
	if (!s[i1])
	{
		free(s);
		return (NULL);
	}
	line = util_calloc((util_strlen(s) - i1 + 1), sizeof(char));
	i1++;
	i2 = 0;
	while (s[i1])
		line[i2++] = s[i1++];
	free(s);
	return (line);
}

char	*main_parse_line(char *s)
{
	int			counter;
	char		*line;

	counter = 0;
	while (s[counter] && s[counter] != '\n')
		counter++;
	line = util_calloc((counter + 2), sizeof(char));
	counter = 0;
	while (s[counter] && s[counter] != '\n')
	{
		line[counter] = s[counter];
		counter++;
	}
	if (s[counter] == '\n')
	{
		line[counter++] = '\n';
		line[counter] = '\0';
	}
	else
	{
		line[counter] = '\0';
	}
	return (line);
}

char	*main_reader(int fd, char *tmp)
{
	int			bytes;
	char		*tempo;

	if (!tmp)
		tmp = util_calloc(1, 1);
	tempo = util_calloc((BUFFER_SIZE + 1), sizeof(char));
	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, tempo, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(tempo);
			return (NULL);
		}
		tempo[bytes] = '\0';
		tmp = main_join(tmp, tempo);
		if (util_strchr(tmp, '\n'))
			break ;
	}
	free(tempo);
	return (tmp);
}

int	super_get_next_line(int fd, char **line)
{
	static char		*tempo;
	char			*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (-1);
	tempo = main_reader(fd, tempo);
	if (!tempo)
		return (-1);
	str = main_parse_line(tempo);
	tempo = main_parse_next(tempo);
	*line = str;
	return (ft_strlen(*line));
}
