/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 10:53:48 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 10:53:48 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ps_rb(t_push_swap *ps)
{
	if (ps->stack_b->top == NULL || ps->stack_b->top == ps->stack_b->top->next)
		return (0);
	ps->stack_b->top = ps->stack_b->top->next;
	if (ps_append_cmdlst(ps->cmdlst, "rb") == -1)
		return (-1);
	return (0);
}
