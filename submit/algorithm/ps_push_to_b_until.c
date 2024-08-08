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

void	update_min_counts(
			t_push_swap *ps, int *min_ra_cnt, int *min_rb_cnt, int step);

int	ps_push_to_b_until(t_push_swap *ps, int until)
{
	int			min_ra_cnt;
	int			min_rb_cnt;

	while (ps->stack_a->size > until)
	{
		min_ra_cnt = ps->stack_a->size;
		min_rb_cnt = ps->stack_b->size;
		update_min_counts(ps, &min_ra_cnt, &min_rb_cnt, 1);
		update_min_counts(ps, &min_ra_cnt, &min_rb_cnt, -1);
		if (ps_rotate_two_stack(ps, min_ra_cnt, min_rb_cnt) == -1)
			return (-1);
		if (ps_pb(ps) == -1)
			return (-1);
	}
	return (0);
}

void	update_min_counts(
		t_push_swap *ps, int *min_ra_cnt, int *min_rb_cnt, int step)
{
	int		ra_cnt;
	int		rb_cnt;
	t_list	*itr;

	ra_cnt = 0;
	itr = ps->stack_a->top;
	while (ft_abs(ra_cnt) < ps_calc_rotate_cost(*min_ra_cnt, *min_rb_cnt))
	{
		rb_cnt = ps_get_insert_pos_desc(ps->stack_b, *(int *)itr->content);
		if (ps_calc_rotate_cost(ra_cnt, rb_cnt)
			< ps_calc_rotate_cost(*min_ra_cnt, *min_rb_cnt))
		{
			*min_ra_cnt = ra_cnt;
			*min_rb_cnt = rb_cnt;
		}
		if (step > 0)
			itr = itr->next;
		else
			itr = itr->prev;
		ra_cnt += step;
	}
	return ;
}
