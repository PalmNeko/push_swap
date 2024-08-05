/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validate_is_sorted.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:13:19 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/05 11:13:19 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include <limits.h>

bool	ps_validate_is_sorted(t_push_swap *ps)
{
	t_iter	itr_a;
	t_list	*cur;
	int		pre_value;

	if (ps->stack_b->top != NULL)
		return (false);
	ft_lstinit_itr(ps->stack_a->top, &itr_a);
	pre_value = INT_MIN;
	while (itr_a.has_next(&itr_a))
	{
		cur = itr_a.next(&itr_a);
		if (*(int *)(cur->content) < pre_value)
			return (false);
	}
	return (true);
}
