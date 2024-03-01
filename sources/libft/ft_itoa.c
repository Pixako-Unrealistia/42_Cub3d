/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:39:12 by schongte          #+#    #+#             */
/*   Updated: 2022/10/15 19:02:26 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	lenofint(int n)
{
	int	counter;

	counter = 0;
	if (n < 0)
		counter++;
	while (n)
	{
		n = n / 10;
		counter++;
	}
	if (counter == 0)
		counter = 1;
	return (counter);
}

char	*emergencymeeting(void)
{
	char	*result;

	result = malloc (sizeof(char) * 12);
	result[0] = '-';
	result[1] = '2';
	result[2] = '1';
	result[3] = '4';
	result[4] = '7';
	result[5] = '4';
	result[6] = '8';
	result[7] = '3';
	result[8] = '6';
	result[9] = '4';
	result[10] = '8';
	result[11] = '\0';
	return (result);
}

char	*emergencyemergency(void)
{
	char	*result;

	result = malloc(sizeof(char) * 2);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	tempo;

	if (n == -2147483648)
		return (emergencymeeting());
	if (n == 0 || n == -0)
		return (emergencyemergency());
	tempo = lenofint(n);
	result = malloc(sizeof(char) * (tempo + 1));
	if (!result)
		return (NULL);
	if (tempo > lenofint(-n))
	{
		result[0] = '-';
		n = -n;
	}
	result[tempo--] = '\0';
	while (n)
	{
		result[tempo] = (n % 10) + '0';
		n = n / 10;
		tempo--;
	}
	return (result);
}
