/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diy_free_2ptr_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 22:28:20 by tnualman          #+#    #+#             */
/*   Updated: 2023/09/07 16:32:44 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The argument for this function must be null-terminated by, AND ONLY BY, its
 * last member, following the convention of argc/argv and ft_split().
 */
void	diy_free_2ptr_char(char **array_s)
{
	size_t	i;

	if (!array_s)
		return ;
	i = 0;
	while (array_s[i])
		free(array_s[i++]);
	free(array_s);
}
