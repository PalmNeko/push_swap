/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 10:20:06 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 10:20:06 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ps_pa(t_push_swap *ps)
{
	t_list	*top_b;

	top_b = ps_pop_stack(ps->stack_b);
	if (top_b == NULL)
		return (0);
	if (ps_push_stack(ps->stack_a, *(int *)top_b->content) == -1)
		return (-1);
	if (ps_append_cmdlst(ps->cmdlst, "pa") == -1)
		return (-1);
	return (0);
}
