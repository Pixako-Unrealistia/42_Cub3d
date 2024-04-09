/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:45:32 by tnualman          #+#    #+#             */
/*   Updated: 2023/09/07 02:02:59 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static char	*word_cutpaste(char const **ptr_s, char c)
{
	char	*word;
	size_t	len_word;

	len_word = 0;
	while (**ptr_s != c && **ptr_s)
	{
		*ptr_s += 1;
		len_word++;
	}
	*ptr_s -= len_word;
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, *ptr_s, len_word + 1);
	*ptr_s += len_word;
	while (**ptr_s == c)
		*ptr_s += 1;
	return (word);
}

static char	**ft_split_edgecase(char const *s, char c)
{
	char	**s_splitted;

	if (!s)
		return (NULL);
	s_splitted = NULL;
	if (!*s)
	{
		s_splitted = (char **)ft_calloc(1, sizeof(char *));
		if (!s_splitted)
			return (NULL);
	}
	else if (!c)
	{
		s_splitted = (char **)ft_calloc(2, sizeof(char *));
		if (!s_splitted)
			return (NULL);
		s_splitted[0] = ft_strdup(s);
	}
	return (s_splitted);
}

static void	ft_split_free_on_error(char **s_splitted, size_t i)
{
	while (i-- > 0)
		free(s_splitted[i]);
	free(s_splitted);
}

char	**ft_split(char const *s, char c)
{
	char	**s_splitted;
	size_t	i;

	if (!s || !*s || !c)
		return (ft_split_edgecase(s, c));
	s_splitted = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!s_splitted)
		return (NULL);
	i = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		s_splitted[i] = word_cutpaste(&s, c);
		if (!s_splitted[i++])
		{
			ft_split_free_on_error(s_splitted, --i);
			return (NULL);
		}
	}
	s_splitted[i] = NULL;
	return (s_splitted);
}
