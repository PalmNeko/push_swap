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
	int	ra_cnt;

	ra_cnt = ps_get_insert_pos_asc(ps->stack_a, -1);
	if (ps_rotate_two_way(ps, ps_ra, ps_rra, ra_cnt) == -1)
		return (-1);
	return (0);
}
