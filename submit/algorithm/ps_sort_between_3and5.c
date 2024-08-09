/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:46:29 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/08 09:46:29 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	is_swap(t_push_swap *ps);
int	ps_push_and_rotate(t_push_swap *ps);
int ps_rotate_stack_a_when_min_values_placed_bottom(t_push_swap *ps);
int	ps_swap_stack_a_to_take_min_cost(t_push_swap *ps);

int	ps_sort_between_3and5(t_push_swap *ps)
{
	if (ps_rotate_stack_a_when_min_values_placed_bottom(ps) == -1)
		return (-1);
	if (ps_push_target_until(ps, PS_TB, 3) == -1)
		return (-1);
	if (ps_sort_to_serial_number_only_top_three(ps, PS_TA) == -1)
		return (-1);
	if (ps_swap_stack_a_to_take_min_cost(ps) == -1)
		return (-1);
	if (ps_push_to_target_at_sorted_place_until_remain(ps, PS_TA, 0) == -1)
		return (-1);
	if (ps_rotate_target_to_right_order(ps, PS_TA) == -1)
		return (-1);
	return (0);
}

int ps_rotate_stack_a_when_min_values_placed_bottom(t_push_swap *ps)
{
	if (ps_at(ps->stack_a, 3) <= 1 && ps_at(ps->stack_a, 4) <= 1)
	{
		if (ps_run_to_times(ps, ps_rra, 2) == -2)
			return (-1);
	}
	return (0);
}

int	ps_swap_stack_a_to_take_min_cost(t_push_swap *ps)
{
	if (is_swap(ps) == 1)
	{
		if (ps_sb(ps) == -1)
			return (-1);
	}
	return (0);
}

int	is_swap(t_push_swap *ps)
{
	t_push_swap	*parallel_ps1;
	t_push_swap	*parallel_ps2;
	int			is_swap;

	parallel_ps1 = ps_clone_ps(ps);
	if (parallel_ps1 == NULL)
		return (-1);
	parallel_ps2 = ps_clone_ps(ps);
	if (parallel_ps2 == NULL)
		return (-1);
	if (ps_sb(parallel_ps1) == -1)
		return (-1);
	if (ps_push_and_rotate(parallel_ps1) == -1)
		return (-1);
	if (ps_push_and_rotate(parallel_ps2) == -1)
		return (-1);
	if (ft_lstsize(parallel_ps1->cmdlst->top) - 1
		< ft_lstsize(parallel_ps2->cmdlst->top))
		is_swap = 1;
	else
		is_swap = 0;
	return (ps_destroy_ps(parallel_ps1), ps_destroy_ps(parallel_ps2), is_swap);
}

int	ps_push_and_rotate(t_push_swap *ps)
{
	if (ps_push_to_target_at_sorted_place_until_remain(ps, PS_TA, 0) == -1)
		return (-1);
	if (ps_rotate_target_to_right_order(ps, PS_TA) == -1)
		return (-1);
	return (0);
}
