/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:29:03 by tnualman          #+#    #+#             */
/*   Updated: 2023/07/26 18:31:32 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	itoa_len(int n)
{
	int	len;

	len = 0;
	if (n < 1)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_strrev(char *s)
{
	size_t	i;
	size_t	j;
	char	temp;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		j--;
		i++;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		i;

	len = itoa_len(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	i = 0;
	if (!n)
		s[i++] = '0';
	while (n)
	{
		s[i++] = '0' + ft_abs(n % 10);
		n /= 10;
	}
	if (i < len)
		s[i++] = '-';
	s[i] = '\0';
	ft_strrev(s);
	return (s);
}
