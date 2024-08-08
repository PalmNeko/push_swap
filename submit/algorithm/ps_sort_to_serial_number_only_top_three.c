/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_to_serial_number_only_top_three.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:06:22 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/08 21:06:22 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

/**
 *
 * swap(top-medium) pattern:
 * top medium bottom
 * 2 1 3 : 2 > 1 < 3 > 2
 * 1 3 2 : 1 < 3 > 2 > 1
 * 3 2 1 : 3 > 2 > 1 < 3
 * no swap pattern:
 * 1 2 3
 * 3 1 2
 * 2 3 1
 */
int	ps_sort_to_serial_number_only_top_three(t_push_swap *ps, t_target target)
{
	int			first;
	int			second;
	int			third;
	t_ps_stack	*stack;

	stack = ps_get_target_stack(ps, target);
	first = ps_get_value(ps_get_stack(stack, 0));
	second = ps_get_value(ps_get_stack(stack, 1));
	third = ps_get_value(ps_get_stack(stack, 2));
	if ((first > second && second < third && third > first)
		|| (first < second && second > third && third > first)
		|| (first > second && second > third && third < first))
	{
		if (ps_swap_target(ps, target) == -1)
			return (-1);
	}
	return (0);
}
