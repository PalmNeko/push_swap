/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_to_b_until_three.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:49:25 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/04 22:49:25 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		ps_rotate_two_stack(t_push_swap *ps, int rotate_a, int rotate_b);
void	update_min_counts_a_rotate(
			t_push_swap *ps, int *min_ra_cnt, int *min_rb_cnt, int min);
void	update_min_counts_a_reverse(
			t_push_swap *ps, int *min_ra_cnt, int *min_rb_cnt, int min);

int	ps_push_to_a_until_three(t_push_swap *ps)
{
	int			min_ra_cnt;
	int			min_rb_cnt;
	int			max_b;
	int			cnt;
	int			unit1;

	unit1 = (ft_lstsize(ps->stack_a->top) + ft_lstsize(ps->stack_b->top)) / 6;
	cnt = 5;
	while (ft_lstsize(ps->stack_b->top) > 0)
	{
		min_ra_cnt = ft_lstsize(ps->stack_a->top);
		min_rb_cnt = ft_lstsize(ps->stack_b->top);
		max_b = ps_get_max_value(ps->stack_b);
		if (unit1 * cnt >= max_b)
			cnt -= 1;
		update_min_counts_a_rotate(ps, &min_ra_cnt, &min_rb_cnt, unit1 * cnt);
		update_min_counts_a_reverse(ps, &min_ra_cnt, &min_rb_cnt, unit1 * cnt);
		if (ps_rotate_two_stack(ps, min_ra_cnt, min_rb_cnt) == -1)
			return (-1);
		if (ps_pa(ps) == -1)
			return (-1);
	}
	return (0);
}

void	update_min_counts_a_rotate(
		t_push_swap *ps, int *min_ra_cnt, int *min_rb_cnt, int min)
{
	int		ra_cnt;
	int		rb_cnt;
	int		value;
	t_list	*itr;

	rb_cnt = 0;
	itr = ps->stack_b->top;
	while (ft_abs(rb_cnt) < ps_calc_rotate_cost(*min_ra_cnt, *min_rb_cnt))
	{
		value = *(int *)itr->content;
		ra_cnt = ps_get_insert_pos_asc(ps->stack_a, value);
		if (value >= min && ps_calc_rotate_cost(ra_cnt, rb_cnt)
			< ps_calc_rotate_cost(*min_ra_cnt, *min_rb_cnt))
		{
			*min_ra_cnt = ra_cnt;
			*min_rb_cnt = rb_cnt;
		}
		itr = itr->next;
		rb_cnt += 1;
	}
	return ;
}

void	update_min_counts_a_reverse(
		t_push_swap *ps, int *min_ra_cnt, int *min_rb_cnt, int min)
{
	int		ra_cnt;
	int		rb_cnt;
	int		value;
	t_list	*itr;

	rb_cnt = 0;
	itr = ps->stack_b->top;
	while (ft_abs(rb_cnt) < ps_calc_rotate_cost(*min_ra_cnt, *min_rb_cnt))
	{
		value = *(int *)itr->content;
		ra_cnt = ps_get_insert_pos_asc(ps->stack_a, value);
		if (value >= min && ps_calc_rotate_cost(ra_cnt, rb_cnt)
			< ps_calc_rotate_cost(*min_ra_cnt, *min_rb_cnt))
		{
			*min_ra_cnt = ra_cnt;
			*min_rb_cnt = rb_cnt;
		}
			itr = itr->prev;
		rb_cnt += -1;
	}
	return ;
}
