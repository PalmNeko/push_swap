/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_b_to_desc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:54:45 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/04 22:54:45 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ps_rotate_b_to_desc(t_push_swap *ps)
{
	int			rb_cnt;

	rb_cnt = ps_get_insert_pos_desc(ps->stack_b, -1);
	while (rb_cnt > 0)
	{
		if (ps_rb(ps) == -1)
			return (-1);
		rb_cnt--;
	}
	while (rb_cnt < 0)
	{
		if (ps_rrb(ps) == -1)
			return (-1);
		rb_cnt++;
	}
	return (0);
}
