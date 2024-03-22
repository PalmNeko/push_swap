/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:20:06 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/21 15:20:06 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_list.h"
#include "stack.h"
#include "libft.h"
#include <stdbool.h>
#include <stdio.h>

static bool	push_to(t_stack *from, t_stack *to);
static bool	swap_first_and_second(t_stack *target);
static bool	rotate(t_stack *target);
static bool	reverse_rotate(t_stack *target);

/**
 * @brief Manipulate the stack according to commands.
 * @param a stack a
 * @param b stack b
 * @param command
 * @return true if manipulation possible.
 * false if manipulation impossible.
 */
bool	apply_order(t_stack *a, t_stack *b, char *command)
{
	if (ft_strncmp(command, "pa", 3) == 0)
		push_to(b, a);
	if (ft_strncmp(command, "pb", 3) == 0)
		push_to(a, b);
	if (ft_strncmp(command, "sa", 3) == 0 || ft_strncmp(command, "ss", 3) == 0)
		swap_first_and_second(a);
	if (ft_strncmp(command, "sb", 3) == 0 || ft_strncmp(command, "ss", 3) == 0)
		swap_first_and_second(b);
	if (ft_strncmp(command, "ra", 3) == 0 || ft_strncmp(command, "rr", 3) == 0)
		rotate(a);
	if (ft_strncmp(command, "rb", 3) == 0 || ft_strncmp(command, "rr", 3) == 0)
		rotate(b);
	if (ft_strncmp(command, "rra", 4) == 0 || ft_strncmp(command, "rrr", 4) == 0)
		reverse_rotate(a);
	if (ft_strncmp(command, "rrb", 4) == 0 || ft_strncmp(command, "rrr", 4) == 0)
		reverse_rotate(b);
	return (true);
}

static bool	push_to(t_stack *from, t_stack *to)
{
	if (from->len < 0 || to->len >= to->max_len)
		return (true);
	to->push(to, from->pop(from));
	return (true);
}

static bool	swap_first_and_second(t_stack *target)
{
	target->swap(target);
	return (true);
}

static bool	rotate(t_stack *target)
{
	target->rotate(target);
	return (true);
}

static bool	reverse_rotate(t_stack *target)
{
	target->reverse_rotate(target);
	return (true);
}
