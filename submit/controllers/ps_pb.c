/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 10:36:59 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 10:36:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ps_pb(t_push_swap *ps)
{
	t_list	*top_a;

	top_a = ps_pop_stack(ps->stack_a);
	if (top_a == NULL)
		return (0);
	if (ps_push_stack(ps->stack_b, *(int *)top_a->content) == -1)
		return (-1);
	if (ps_append_cmdlst(ps->cmdlst, "pb") == -1)
		return (-1);
	return (0);
}
