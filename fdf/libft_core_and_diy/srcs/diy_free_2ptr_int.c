/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diy_free_2ptr_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 22:28:20 by tnualman          #+#    #+#             */
/*   Updated: 2023/09/29 16:22:33 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The innner_malloc_count for this function must be correct, otherwise
 * either leak(s), or segfault, or invalid free(s), is/are guaranteed to happen!
 * (The boundary value may include the terminating null, if it exists.)
 */
void	diy_free_2ptr_int(int **double_ptr_int, size_t inner_malloc_count)
{
	size_t	i;

	if (!double_ptr_int)
		return ;
	i = 0;
	while (i < inner_malloc_count)
		if (double_ptr_int[i])
			free(double_ptr_int[i++]);
	free(double_ptr_int);
}
