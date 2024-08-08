/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_to_target_at_sorted_place_until.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:23:11 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/08 21:23:11 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ps_push_to_target_at_sorted_place_until_remain(
		t_push_swap *ps, t_target target, int remain)
{
	t_ps_stack	*from_stack;

	from_stack = ps_get_target_stack(ps, ps_get_other_target(target));
	while (from_stack->size > remain)
	{
		if (ps_push_to_target_at_sorted_place(ps, target) == -1)
			return (-1);
	}
	return (0);
}
