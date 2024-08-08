/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:31:46 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 12:31:46 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "libft.h"
#include <limits.h>
#include <stdlib.h>

int	ps_turk_sort(t_push_swap *ps)
{
	if (ps_push_to_b_until(ps, 15) == -1)
		return (-1);
	if (ps_rotate_target_to_right_order(ps, PS_TB) == -1)
		return (-1);
	if (ps_push_target_until(ps, PS_TB, 3) == -1)
		return (-1);
	if (ps_sort_to_serial_number_only_top_three(ps, PS_TA) == -1)
		return (-1);
	if (ps_push_to_target_at_sorted_place_until_remain(ps, PS_TA, 0) == -1)
		return (-1);
	if (ps_rotate_target_to_right_order(ps, PS_TA) == -1)
		return (-1);
	return (0);
}
