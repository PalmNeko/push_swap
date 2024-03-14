/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:40:33 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/26 16:40:33 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "_stack_methods.h"
#include <stdlib.h>
#include <stddef.h>

#include <string.h>
#include <stdio.h>

t_stack	*create_stack(int max_len)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->stack = (int *)malloc(sizeof(int) * max_len);
	if (stack->stack == NULL)
		return (NULL);
	stack->len = 0;
	stack->max_len = max_len;
	stack->push = _stack_push;
	stack->swap = _stack_swap;
	stack->pop = _stack_pop;
	stack->rotate = _stack_rotate;
	stack->reverse_rotate = _stack_reverse_rotate;
	stack->shift_up = _stack_rotate;
	stack->shift_down = _stack_reverse_rotate;
	return (stack);
}
