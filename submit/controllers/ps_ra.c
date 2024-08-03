/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 10:42:54 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 10:42:54 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ps_ra(t_push_swap *ps)
{
	if (ps->stack_a->top == NULL || ps->stack_a->top == ps->stack_a->top->next)
		return (0);
	ps->stack_a->top = ps->stack_a->top->next;
	if (ps_append_cmdlst(ps->cmdlst, "ra") == -1)
		return (-1);
	return (0);
}
