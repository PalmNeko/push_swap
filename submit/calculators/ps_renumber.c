/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_renumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:32:03 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 11:32:03 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int cmp_int(const void *a, const void *b);

int	ps_renumber(int *values, int size)
{
	int				*copy;
	t_bsearch_arg	b_arg;
	int				index;
	int				*result;

	copy = (int *)malloc(sizeof(int) * size);
	if (copy == NULL)
		return (-1);
	ft_memcpy(copy, values, sizeof(int) * size);
	ft_selection_sort(values, size, sizeof(int), cmp_int);
	b_arg = (t_bsearch_arg) {.base = copy, .compar = cmp_int,
			.size = sizeof(int), .nmemb = size};
	index = 0;
	while (index < size)
	{
		b_arg.key = &values[index];
		result = (int *)ft_bsearch(&b_arg);
		if (result == NULL)
			return (-1);
		values[index] = (int)(result - copy);
		index++;
	}
	return (0);
}

static int cmp_int(const void *a, const void *b)
{
	if (*(int *)a < *(int *)b)
		return (-1);
	else if (*(int *)a > *(int *)b)
		return (1);
	else
		return (0);
}
