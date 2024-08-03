/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_for_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:09:41 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 12:09:41 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "libft.h"

int	ps_sort_for_three(t_push_swap *ps)
{
	int	max;
	int min;
	int	first;
	int	second;
	int	third;

	if (ft_lstsize(ps->stack_a->top) != 3)
		return (0);
	first = *(int *)ft_lstat(ps->stack_a->top, 0)->content;
	second = *(int *)ft_lstat(ps->stack_a->top, 1)->content;
	third = *(int *)ft_lstat(ps->stack_a->top, 2)->content;
	max = ft_max(first, ft_max(second, third));
	if (max == first && ps_ra(ps) == -1)
		return (-1);
	if (max == second && ps_rra(ps) == -1)
		return (-1);
	first = *(int *)ft_lstat(ps->stack_a->top, 0)->content;
	second = *(int *)ft_lstat(ps->stack_a->top, 1)->content;
	third = *(int *)ft_lstat(ps->stack_a->top, 2)->content;
	min = ft_min(first, ft_min(second, third));
	if (min != first && ps_sa(ps) == -1)
		return (-1);
	return (0);
}
