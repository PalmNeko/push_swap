/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:07:46 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/08 10:07:46 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ps_get_target_size(t_push_swap *ps, t_target target)
{
	if (target == PS_TA)
		return (ps->stack_a->size);
	else if (target == PS_TB)
		return (ps->stack_b->size);
	else
		return (-1);
}
