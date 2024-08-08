/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_to_target_at_sorted_place.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:12:57 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/08 21:12:57 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ps_push_to_target_at_sorted_place(t_push_swap *ps, t_target target)
{
	int			(*insert_pos_func)(t_ps_stack *stack, int value);
	int			rotate_cnt;
	t_ps_stack	*to_stack;
	t_ps_stack	*from_stack;

	to_stack = ps_get_target_stack(ps, target);
	from_stack = ps_get_target_stack(ps, ps_get_other_target(target));
	insert_pos_func = NULL;
	if (target == PS_TA)
		insert_pos_func = ps_get_insert_pos_asc;
	else if (target == PS_TB)
		insert_pos_func = ps_get_insert_pos_desc;
	rotate_cnt = insert_pos_func(to_stack, ps_at(from_stack, 0));
	if (ps_rotate_two_way(ps,
			ps_get_target_command(target, ps_ra, ps_rb),
			ps_get_target_command(target, ps_rra, ps_rrb), rotate_cnt) == -1)
		return (-1);
	if ((ps_get_target_command(target, ps_pa, ps_pb))(ps) == -1)
		return (-1);
	return (0);
}
