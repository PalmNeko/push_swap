/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 10:39:18 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 10:39:18 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ps_sa(t_push_swap *ps)
{
	if (ft_lstat(ps->stack_a->top, 0) == NULL
		|| ft_lstat(ps->stack_a->top, 1) == NULL)
		return (0);
	ps_swap_stack(ps->stack_a);
	if (ps_append_cmdlst(ps->cmdlst, "sa") == -1)
		return (-1);
	return (0);
}
