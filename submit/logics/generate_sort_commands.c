/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_sort_commands.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:59:20 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/17 16:59:20 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_list.h"
#include "stack.h"
#include "_logics.h"

static t_command_list	*solve_push_swap(t_stack *stack_a, t_stack *stack_b);

t_command_list	*generate_sort_commands(t_stack	*input_stack)
{
	t_stack			*stack_b;
	t_command_list	*commands;
	t_command_list	*compressed;

	stack_b = create_stack(input_stack->max_len);
	if (stack_b == NULL)
		return (NULL);
	commands = solve_push_swap(input_stack, stack_b);
	if (commands == NULL)
		return (destroy_stack(stack_b), NULL);
	compressed = compress_commands(commands, input_stack->max_len);
	destroy_command_list(commands);
	if (compressed == NULL)
		return (NULL);
	return (compressed);
}

t_command_list	*solve_push_swap(t_stack *stack_a, t_stack *stack_b)
{
	return (push_swap_bubble_sort(stack_a, stack_b));
}
