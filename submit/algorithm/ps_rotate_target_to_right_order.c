/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_target_to_right_order.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:05:26 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/08 22:05:26 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ps_rotate_target_to_right_order(t_push_swap *ps, t_target target)
{
	t_ps_stack	*stack;
	int			(*get_insert_pos_func)(t_ps_stack *stack, int value);
	int			rotate_cnt;
	t_cmd		rotate_cmd;
	t_cmd		rrotate_cmd;

	get_insert_pos_func = ps_get_func_get_insert_pos(target);
	stack = ps_get_target_stack(ps, target);
	rotate_cnt = get_insert_pos_func(stack, -1);
	rotate_cmd = ps_get_target_command(target, ps_ra, ps_rb);
	rrotate_cmd = ps_get_target_command(target, ps_rra, ps_rrb);
	if (ps_rotate_two_way(ps, rotate_cmd, rrotate_cmd, rotate_cnt) == -1)
		return (-1);
	return (0);
}
