/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_to_a_until_zero.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:57:45 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/04 22:57:45 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ps_push_to_a_until_zero(t_push_swap *ps)
{
	int	ra_cnt;

	while (ft_lstsize(ps->stack_b->top) > 0)
	{
		// スタックBの先頭と、スタックAの一番下を比較して、スタックAの方が大きければ、回転。
		ps_print_ps(2, ps);
		ra_cnt = ps_get_insert_pos_asc(ps->stack_a, *(int *)ps->stack_b->top->content);
		if (ps_rotate_two_way(ps, ps_ra, ps_rra, ra_cnt) == -1)
			return (-1);
		if (ps_pa(ps) == -1)
			return (-1);
	}
	return (0);
}
