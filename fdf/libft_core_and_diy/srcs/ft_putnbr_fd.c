/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:20:19 by tnualman          #+#    #+#             */
/*   Updated: 2022/09/19 03:42:31 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_static_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static char	*ft_static_strrev(char *s)
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

void	ft_putnbr_fd(int n, int fd)
{
	char	s[12];
	int		i;

	i = 0;
	if (n < 0)
		s[i++] = '-';
	if (!n)
		s[i++] = '0';
	while (n)
	{
		s[i++] = '0' + ft_static_abs(n % 10);
		n /= 10;
	}
	s[i] = '\0';
	if (s[0] == '-')
		ft_static_strrev(s + 1);
	else
		ft_static_strrev(s);
	write(fd, s, ft_strlen(s));
}
