/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:11:23 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 11:11:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ps_rrb(t_push_swap *ps)
{
	if (ps->stack_b->top == NULL || ps->stack_b->top == ps->stack_b->top->prev)
		return (0);
	ps->stack_b->top = ps->stack_b->top->prev;
	if (ps_append_cmdlst(ps->cmdlst, "rrb") == -1)
		return (-1);
	return (0);
}
