/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schongte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:16:15 by schongte          #+#    #+#             */
/*   Updated: 2022/08/27 23:02:27 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(char arg)
{
	if (((arg >= 65 && arg <= 90) || (arg >= 97 && arg <= 122))
		|| ((arg >= 48) && (arg <= 57)))
		return (1);
	return (0);
}
