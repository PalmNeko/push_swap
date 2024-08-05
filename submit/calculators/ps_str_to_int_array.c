/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_str_to_int_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:41:03 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 11:41:03 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int	*ps_str_to_int_array(const char *strs[], int size)
{
	int		*array;
	int		index;
	char	*endptr;
	long	tmp;

	array = (int *)malloc(sizeof(int) * size);
	if (array == NULL)
		return (NULL);
	index = 0;
	while (index < size)
	{
		errno = 0;
		tmp = ft_strtol(strs[index], &endptr, 10);
		if (strs[index][0] == '\0' || *endptr != '\0' || errno != 0
			|| tmp < INT_MIN || tmp > INT_MAX)
			return (free(array), NULL);
		array[index] = (int)tmp;
		index++;
	}
	return (array);
}
