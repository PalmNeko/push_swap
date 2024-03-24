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

static int	run_ra(t_command_list *commands, t_stack *a, t_stack *b)
{
	(void)b;
	a->shift_up(a);
	if (commands->append(commands, "ra") == NULL)
		return (-1);
	return (0);
}

static int	run_sa(t_command_list *commands, t_stack *a, t_stack *b)
{
	(void)b;
	a->swap(a);
	if (commands->append(commands, "sa") == NULL)
		return (-1);
	return (0);
}

static int	swap_for_asc(t_command_list *commands, t_stack *a, t_stack *b,
	int loop_times)
{
	int	counter;
	int	cmp_result;

	counter = 0;
	while (counter < loop_times)
	{
		cmp_result = ft_intcmp_pointer(a->get_head(a, 0), a->get_head(a, 1));
		if (cmp_result > 0 && counter < loop_times - 1)
		{
			if (run_sa(commands, a, b) < 0)
				return (-1);
		}
		if (run_ra(commands, a, b) < 0)
			return (-1);
		counter++;
	}
	return (0);
}

t_command_list	*push_swap_bubble_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_command_list	*commands;
	int				loop_times;
	int				counter;

	(void)stack_b;
	commands = create_command_list();
	if (commands == NULL)
		return (NULL);
	loop_times = stack_a->len;
	counter = 0;
	while (counter < loop_times)
	{
		if (swap_for_asc(commands, stack_a, stack_b, loop_times) < 0)
			return (destroy_command_list(commands), NULL);
		counter++;
	}
	return (commands);
}
