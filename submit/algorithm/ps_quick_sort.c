/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:49:38 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/05 15:49:38 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "libft.h"
#include <limits.h>
#include <stdlib.h>

int	split_five(t_push_swap *ps);

int	ps_quick_sort(t_push_swap *ps)
{
	if (split_five(ps) == -1)
		return (-1);
	while (ft_lstsize(ps->stack_a->top) > 2)
	{
		if (ps_pb(ps) == -1)
			return (-1);
	}
	if (ps_push_to_a_until_three(ps) == -1)
		return (-1);
	if (ps_rotate_a_to_asc(ps) == -1)
		return (-1);
	return (0);
}

int	push_to_b_splitted(t_push_swap *ps, int min, int max)
{
	int			value;
	int			times;

	times = ft_lstsize(ps->stack_a->top);
	while (times > 0)
	{
		value = *(int *)ps->stack_a->top->content;
		if (min <= value && value < max)
		{
			if (ps_pb(ps) == -1)
				return (-1);
			if (value > (min + max) / 2 && ps_rb(ps) == -1)
				return (-1);
		}
		else if (ps_ra(ps) == -1)
			return (-1);
		times--;
	}
	return (0);
}

int	split_five(t_push_swap *ps)
{
	int			unit1;
	int			cnt;

	cnt = 0;
	unit1 = ft_lstsize(ps->stack_a->top) / 6;
	while (cnt < 6)
	{
		if (push_to_b_splitted(ps, unit1 * cnt, unit1 * (cnt + 2)) == -1)
			return (0);
		cnt += 2;
	}
	return (0);
}
