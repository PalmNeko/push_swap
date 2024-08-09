/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_two_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:03:30 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/06 11:03:30 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ps_rotate_two_stack(t_push_swap *ps, int rotate_a, int rotate_b)
{
	while (rotate_a > 0 && rotate_b > 0)
	{
		if (ps_rr(ps) == -1)
			return (-1);
		rotate_a--;
		rotate_b--;
	}
	while (rotate_a < 0 && rotate_b < 0)
	{
		if (ps_rrr(ps) == -1)
			return (-1);
		rotate_a++;
		rotate_b++;
	}
	if (ps_rotate_two_way(ps, ps_rb, ps_rrb, rotate_b) == -1)
		return (-1);
	if (ps_rotate_two_way(ps, ps_ra, ps_rra, rotate_a) == -1)
		return (-1);
	return (0);
}
