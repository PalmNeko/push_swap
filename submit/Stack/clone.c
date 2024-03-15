/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:44:10 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/15 22:44:10 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
#include <stddef.h>

struct s_stack	*_stack_clone(struct s_stack *self)
{
	t_stack	*deep_copy;

	deep_copy = create_stack(self->max_len);
	if (deep_copy == NULL)
		return (NULL);
	ft_memcpy(deep_copy->stack, self->stack, self->len);
	deep_copy->len = self->len;
	return (deep_copy);
}
