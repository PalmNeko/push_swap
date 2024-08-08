/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_clone_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:04:28 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/08 16:04:28 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include <stdlib.h>

t_ps_stack	*ps_clone_stack(t_ps_stack *stack)
{
	t_ps_stack	*cloned_stack;

	cloned_stack = ps_new_stack();
	if (cloned_stack == NULL)
		return (NULL);
	cloned_stack->top = ft_lstmap(
			stack->top, (void *(*)(void *))ft_strdup, free);
	if (stack->top != NULL && cloned_stack->top == NULL)
		return (ps_destroy_stack(cloned_stack), NULL);
	ft_lsttocircular(cloned_stack->top);
	cloned_stack->size = stack->size;
	return (cloned_stack);
}
