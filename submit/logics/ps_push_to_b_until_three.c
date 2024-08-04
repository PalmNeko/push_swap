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

int	ps_push_to_b_until_three(t_push_swap *ps)
{
	int			rb_cnt;
	int			ra_cnt;
	int			min_ra_cnt;
	int			min_rb_cnt;
	t_list		*itr;

	// stack aが3個以下になるまで、いい感じにstack bにプッシュする。
	while (ft_lstsize(ps->stack_a->top) > 3)
	{
		min_ra_cnt = ft_lstsize(ps->stack_a->top);
		min_rb_cnt = ft_lstsize(ps->stack_b->top);
		// ps_print_ps(2, ps);
		itr = ps->stack_a->top;
		ra_cnt = 0;
		while (ft_abs(ra_cnt) < ft_abs(min_ra_cnt) + ft_abs(min_rb_cnt))
		{
			rb_cnt = ps_get_insert_pos_desc(ps->stack_b, *(int *)itr->content);
			if (ft_abs(rb_cnt) + ft_abs(ra_cnt) < ft_abs(min_ra_cnt) + ft_abs(min_rb_cnt))
			{
				min_ra_cnt = ra_cnt;
				min_rb_cnt = rb_cnt;
			}
			itr = itr->next;
			ra_cnt++;
		}
		itr = ps->stack_a->top;
		ra_cnt = 0;
		while (ft_abs(ra_cnt) < ft_abs(min_ra_cnt) + ft_abs(min_rb_cnt))
		{
			rb_cnt = ps_get_insert_pos_desc(ps->stack_b, *(int *)itr->content);
			if (ft_abs(rb_cnt) + ft_abs(ra_cnt) < ft_abs(min_ra_cnt) + ft_abs(min_rb_cnt))
			{
				min_ra_cnt = ra_cnt;
				min_rb_cnt = rb_cnt;
			}
			itr = itr->prev;
			ra_cnt--;
		}
		// min_rb_cntとmin_ra_cntで符号が違う場合は、どちらに合わせたほうがより良いかを判定する。
		while (min_ra_cnt > 0 && min_rb_cnt > 0)
		{
			if (ps_rr(ps) == -1)
				return (-1);
			min_ra_cnt--;
			min_rb_cnt--;
		}
		while (min_ra_cnt < 0 && min_rb_cnt < 0)
		{
			if (ps_rrr(ps) == -1)
				return (-1);
			min_ra_cnt++;
			min_rb_cnt++;
		}
		while (min_rb_cnt > 0)
		{
			if (ps_rb(ps) == -1)
				return (-1);
			min_rb_cnt--;
		}
		while (min_rb_cnt < 0)
		{
			if (ps_rrb(ps) == -1)
				return (-1);
			min_rb_cnt++;
		}
		while (min_ra_cnt > 0)
		{
			if (ps_ra(ps) == -1)
				return (-1);
			min_ra_cnt--;
		}
		while (min_ra_cnt < 0)
		{
			if (ps_rra(ps) == -1)
				return (-1);
			min_ra_cnt++;
		}
		if (ps_pb(ps) == -1)
			return (-1);
	}
	return (0);
}
