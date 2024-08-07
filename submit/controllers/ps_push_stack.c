/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:30:52 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/31 16:30:52 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_types.h"
#include <stdlib.h>

int	ps_push_stack(t_ps_stack *stack, int value)
{
	t_list	*new_node;
	int		*vptr;

	vptr = (int *)malloc(sizeof(int));
	if (vptr == NULL)
		return (-1);
	*vptr = value;
	new_node = ft_lstnewcircular(vptr);
	if (new_node == NULL)
		return (free(vptr), -1);
	ft_lstpush(&stack->top, new_node);
	stack->size += 1;
	return (0);
}
