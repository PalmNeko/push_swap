/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_target_until.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:43:35 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/08 19:43:35 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ps_push_target_until(t_push_swap *ps, t_target target, int until)
{
	t_ps_stack	*stack;
	t_cmd		push_command;

	if (until < 0)
		return (0);
	stack = ps_get_target_stack(ps, ps_get_other_target(target));
	push_command = ps_get_target_command(target, ps_pa, ps_pb);
	if (ps_run_to_times(ps, push_command, stack->size - until) == -1)
			return (-1);
	return (0);
}
