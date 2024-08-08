/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_target_stack_if_needed.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:07:35 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/08 12:07:35 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include <stdbool.h>

int	ps_swap_target_stack_if_needed(t_push_swap *ps, t_target target)
{
	t_ps_stack	*stack;

	stack = ps_get_target_stack(ps, target);
	if (stack->size < 2)
		return (0);
	if ((target == PS_TA && ps_at(stack, 0) > ps_at(stack, 1))
		|| (target == PS_TB && ps_at(stack, 0) < ps_at(stack, 1)))
	{
		if (ps_swap_target(ps, target) == -1)
			return (0);
	}
	return (0);
}
