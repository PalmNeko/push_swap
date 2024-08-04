/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_a_to_asc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 23:05:29 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/04 23:05:29 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ps_rotate_a_to_asc(t_push_swap *ps)
{
	int			min_ra_cnt;

	min_ra_cnt = ps_get_insert_pos_asc(ps->stack_a, -1);
	while (min_ra_cnt > 0)
	{
		if (ps_ra(ps) == -1)
			return (-1);
		min_ra_cnt--;
	}
	while (min_ra_cnt < 0)
	{
		if (ps_rra(ps) == -1)
			return (-1);
		min_ra_cnt++;
	}
	return (0);
}
