/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:00:07 by tnualman          #+#    #+#             */
/*   Updated: 2023/09/01 21:10:13 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Refactored to be a part of tnualman's libft in a single file.

#include "libft.h"

static int	check_buffer(char **p_buf);
static char	*line_join(char *line, char *next);
static char	*cycle_buffer(int fd, char *buf);
static char	*read_into_buffer(int fd, char **p_buf, char **p_next);

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	char		*next;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!check_buffer(&buf))
		return (NULL);
	line = NULL;
	next = cycle_buffer(fd, buf);
	while (next)
	{
		line = line_join(line, next);
		if (!line)
			break ;
		if (ft_strchr(next, '\n'))
		{
			diy_free_then_null((void **)&next);
			return (line);
		}
		diy_free_then_null((void **)&next);
		next = cycle_buffer(fd, buf);
	}
	diy_free_then_null((void **)&buf);
	return (line);
}

static int	check_buffer(char **p_buf)
{
	if (*p_buf)
		return (1);
	*p_buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*p_buf)
		return (0);
	**p_buf = '\0';
	return (1);
}

/* NOTE: This routine only frees the first argument; the second argument must
 * be freed outside! Reason: it will be re-used to check for \n, thus it must
 * be freed later.
 */
static char	*line_join(char *line, char *next)
{
	char	*joined;

	if (line)
	{
		joined = ft_strjoin(line, next);
		diy_free_then_null((void **)&line);
	}
	else
		joined = ft_strdup(next);
	return (joined);
}

static char	*cycle_buffer(int fd, char *buf)
{
	char	*next;
	char	*p_newline;

	p_newline = ft_strchr(buf, '\n');
	if (p_newline)
	{
		*p_newline = '\0';
		next = ft_strjoin(buf, "\n");
		while (*(++p_newline))
		{
			*buf = *p_newline;
			buf++;
		}
		*buf = '\0';
		return (next);
	}
	next = NULL;
	if (*buf)
		next = ft_strdup(buf);
	*buf = '\0';
	return (read_into_buffer(fd, &buf, &next));
}

/* Subroutine for cycle_buffer() */
static char	*read_into_buffer(int fd, char **p_buf, char **p_next)
{
	ssize_t	n;

	n = read(fd, *p_buf, BUFFER_SIZE);
	if (n < 0)
	{
		diy_free_then_null((void **)p_next);
		return (NULL);
	}
	*(*p_buf + n) = '\0';
	if (n > 0 && !*p_next)
		*p_next = ft_strdup("");
	return (*p_next);
}
