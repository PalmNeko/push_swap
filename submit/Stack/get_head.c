/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_head.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:20:22 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/17 17:20:22 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stddef.h>

/**
 * @brief get value from head by index.
 * @param self - target strcut stack.
 * @param index_from_top - index from top.
 * @return not allocated value pointer if success. NULL if range error.
 */
int	*_stack_get_head(t_stack *self, int index_from_top)
{
	int	top_index;
	if (self->len <= 0)
		return (NULL);
	top_index = self->len - 1;
	if (index_from_top > top_index)
		return (NULL);
	return (&self->stack[top_index - index_from_top]);
}
