/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:10:11 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 11:10:11 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ps_rra(t_push_swap *ps)
{
	if (ps->stack_a->top == NULL || ps->stack_a->top == ps->stack_a->top->prev)
		return (0);
	ps->stack_a->top = ps->stack_a->top->prev;
	if (ps_append_cmdlst(ps->cmdlst, "rra") == -1)
		return (-1);
	return (0);
}
