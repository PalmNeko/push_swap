/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:12:41 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 11:12:41 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ps_ss(t_push_swap *ps)
{
	if ((ft_lstat(ps->stack_a->top, 0) == NULL
			|| ft_lstat(ps->stack_a->top, 1) == NULL)
		&& (ft_lstat(ps->stack_b->top, 0) == NULL
			|| ft_lstat(ps->stack_b->top, 1) == NULL))
		return (0);
	ps_swap_stack(ps->stack_a);
	ps_swap_stack(ps->stack_b);
	if (ps_append_cmdlst(ps->cmdlst, "ss") == -1)
		return (-1);
	return (0);
}
