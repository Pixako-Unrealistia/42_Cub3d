/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cs_wc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:45:32 by tnualman          #+#    #+#             */
/*   Updated: 2023/09/07 02:02:59 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function is the combination of ft_split_cs() and ft_split_wc().
 */
static size_t	word_count(char const *s, char *charset)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (ft_strchr(charset, (int)*s) && *s)
			s++;
		if (!ft_strchr(charset, (int)*s))
			count++;
		while (!ft_strchr(charset, (int)*s))
			s++;
	}
	return (count);
}

static char	*word_cutpaste(char const **ptr_s, char *charset)
{
	char	*word;
	size_t	len_word;

	len_word = 0;
	while (!ft_strchr(charset, (int)**ptr_s))
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
	while (ft_strchr(charset, (int)**ptr_s) && **ptr_s)
		*ptr_s += 1;
	return (word);
}

static char	**ft_split_cs_wc_edgecase(char const *s, char *charset,
	size_t *wordcount)
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
		if (wordcount)
			*wordcount = 0;
	}
	else if (!charset || !*charset)
	{
		s_splitted = (char **)ft_calloc(2, sizeof(char *));
		if (!s_splitted)
			return (NULL);
		s_splitted[0] = ft_strdup(s);
		if (wordcount)
			*wordcount = 1;
	}
	return (s_splitted);
}

static void	ft_split_free_on_error(char **s_splitted, size_t i)
{
	while (i-- > 0)
		free(s_splitted[i]);
	free(s_splitted);
}

char	**ft_split_cs_wc(char const *s, char *charset, size_t *wordcount)
{
	char	**s_splitted;
	size_t	i;

	if (!s || !*s || !charset || !*charset)
		return (ft_split_cs_wc_edgecase(s, charset, wordcount));
	s_splitted = (char **)malloc(sizeof(char *) * (word_count(s, charset) + 1));
	if (!s_splitted)
		return (NULL);
	i = 0;
	while (ft_strchr(charset, (int)*s) && *s)
		s++;
	while (*s)
	{
		s_splitted[i] = word_cutpaste(&s, charset);
		if (!s_splitted[i++])
		{
			ft_split_free_on_error(s_splitted, --i);
			return (NULL);
		}
	}
	s_splitted[i] = NULL;
	if (wordcount)
		*wordcount = i;
	return (s_splitted);
}
