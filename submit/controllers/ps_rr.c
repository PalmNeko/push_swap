/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:17:59 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 11:17:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ps_rr(t_push_swap *ps)
{
	if ((ps->stack_a->top == NULL
			|| ps->stack_a->top == ps->stack_a->top->next)
		&& (ps->stack_b->top == NULL
			|| ps->stack_b->top == ps->stack_b->top->next))
		return (0);
	ps->stack_a->top = ps->stack_a->top->next;
	ps->stack_b->top = ps->stack_b->top->next;
	if (ps_append_cmdlst(ps->cmdlst, "rr") == -1)
		return (-1);
	return (0);
}
