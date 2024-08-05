/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_run_to_times.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 23:13:13 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/04 23:13:13 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ps_run_to_times(t_push_swap *ps, int (*f)(t_push_swap *), int cnt)
{
	while (cnt > 0)
	{
		if (f(ps) == -1)
			return (-1);
		cnt--;
	}
	return (0);
}
