/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bubble_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:55:32 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/18 16:55:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_list.h"
#include "stack.h"

static int	ft_intcmp_pointer(int *a, int *b)
{
	if (a == NULL || b == NULL)
		return (0);
	return (*a - *b);
}

t_command_list	*push_swap_bubble_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_command_list	*commands;
	int				loop_times;
	int				counter;
	int				outer_counter;
	int				cmp_result;

	(void)stack_b;
	commands = create_command_list();
	if (commands == NULL)
		return (NULL);
	loop_times = stack_a->len;
	outer_counter = 0;
	while (outer_counter < loop_times)
	{
		counter = 0;
		while (counter < loop_times)
		{
			cmp_result = ft_intcmp_pointer(
					stack_a->get_head(stack_a, 0),
					stack_a->get_head(stack_a, 1));
			if (cmp_result > 0 && counter < loop_times - 1)
			{
				stack_a->swap(stack_a);
				commands->append(commands, "sa");
			}
			stack_a->shift_up(stack_a);
			commands->append(commands, "ra");
			counter++;
		}
		outer_counter++;
	}
	return (commands);
}