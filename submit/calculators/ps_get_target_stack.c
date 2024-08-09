/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_target_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:30:17 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/08 11:30:17 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_types.h"

t_ps_stack	*ps_get_target_stack(t_push_swap *ps, t_target target)
{
	if (target == PS_TA)
		return (ps->stack_a);
	else if (target == PS_TB)
		return (ps->stack_b);
	return (NULL);
}
