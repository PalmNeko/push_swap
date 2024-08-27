/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validate_no_duplicates.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 00:02:37 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/27 11:01:56 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>

static int	cmp_int_asc(const void *v1, const void *v2)
{
	return (*(int *)v1 - *(int *)v2);
}

/**
 * @brief validate no duplicates.
 * @param values number array.
 * @param len values array length.
 * @return false if length == 0 or duplicates.
 * true if no duplicates.
 */
bool	ps_validate_no_duplicates(int *values, size_t len)
{
	int		*copy_values;
	size_t	index;
	int		pre_value;

	if (len == 0)
		return (false);
	copy_values = (int *)malloc(sizeof(int) * len);
	if (copy_values == NULL)
		return (false);
	ft_memcpy(copy_values, values, sizeof(int) * len);
	ft_selection_sort(copy_values, len, sizeof(int), cmp_int_asc);
	pre_value = copy_values[0];
	index = 1;
	while (index < len)
	{
		if (pre_value == copy_values[index])
			return (free(copy_values), false);
		pre_value = copy_values[index];
		index++;
	}
	free(copy_values);
	return (true);
}
