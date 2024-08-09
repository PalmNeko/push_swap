/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_two_way.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 23:20:22 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/04 23:20:22 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ps_rotate_two_way(t_push_swap *ps, t_cmd fr, t_cmd frr, int cnt)
{
	while (cnt > 0)
	{
		if (fr(ps) == -1)
			return (-1);
		cnt--;
	}
	while (cnt < 0)
	{
		if (frr(ps) == -1)
			return (-1);
		cnt++;
	}
	return (0);
}
