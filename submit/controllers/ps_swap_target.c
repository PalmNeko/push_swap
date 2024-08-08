/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_target.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:39:50 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/08 11:39:50 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ps_swap_target(t_push_swap *ps, t_target target)
{
	if (target == PS_TA)
		return (ps_sa(ps));
	else if (target == PS_TB)
		return (ps_sb(ps));
	return (-1);
}
