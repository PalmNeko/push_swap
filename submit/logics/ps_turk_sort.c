/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:31:46 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 12:31:46 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "libft.h"
#include <limits.h>
#include <stdlib.h>

int			ps_init_turk_sort(const int *values, int size, t_push_swap **ps);
void		ps_finalize_turk_sort(t_push_swap **ps);
t_ps_cmdlst	*ps_solve_with_turk_sort(t_push_swap *ps);

t_ps_cmdlst	*ps_turk_sort(int *values, int size)
{
	t_push_swap	*ps;
	t_ps_cmdlst	*cmdlst;

	if (ps_init_turk_sort(values, size, &ps) == -1)
		return (NULL);
	cmdlst = ps_solve_with_turk_sort(ps);
	ps_finalize_turk_sort(&ps);
	return (cmdlst);
}

int	ps_get_min_value(t_ps_stack *stack);
int	ps_get_max_value(t_ps_stack *stack);

t_ps_cmdlst	*ps_solve_with_turk_sort(t_push_swap *ps)
{
	t_ps_cmdlst	*cmdlst;
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
				return (NULL);
			min_ra_cnt--;
			min_rb_cnt--;
		}
		while (min_ra_cnt < 0 && min_rb_cnt < 0)
		{
			if (ps_rrr(ps) == -1)
				return (NULL);
			min_ra_cnt++;
			min_rb_cnt++;
		}
		while (min_rb_cnt > 0)
		{
			if (ps_rb(ps) == -1)
				return (NULL);
			min_rb_cnt--;
		}
		while (min_rb_cnt < 0)
		{
			if (ps_rrb(ps) == -1)
				return (NULL);
			min_rb_cnt++;
		}
		while (min_ra_cnt > 0)
		{
			if (ps_ra(ps) == -1)
				return (NULL);
			min_ra_cnt--;
		}
		while (min_ra_cnt < 0)
		{
			if (ps_rra(ps) == -1)
				return (NULL);
			min_ra_cnt++;
		}
		if (ps_pb(ps) == -1)
			return (NULL);
	}
	// ps_print_ps(2, ps);
	// 最大値が一番上に来るようにスタックBを回転させる。
	rb_cnt = ps_get_insert_pos_desc(ps->stack_b, -1);
	while (rb_cnt > 0)
	{
		if (ps_rb(ps) == -1)
			return (NULL);
		rb_cnt--;
	}
	while (rb_cnt < 0)
	{
		if (ps_rrb(ps) == -1)
			return (NULL);
		rb_cnt++;
	}
	// スタックAをソートする。
	if (ft_lstsize(ps->stack_a->top) == 3 && ps_sort_for_three(ps) == -1)
		return (NULL);
	// スタックAにいい感じにつっこむ
	while (ft_lstsize(ps->stack_b->top) > 0)
	{
		// スタックBの先頭と、スタックAの一番下を比較して、スタックAの方が大きければ、回転。
		ps_print_ps(2, ps);
		min_ra_cnt = ps_get_insert_pos_asc(ps->stack_a, *(int *)ps->stack_b->top->content);
		while (min_ra_cnt > 0)
		{
			if (ps_ra(ps) == -1)
				return (NULL);
			min_ra_cnt--;
		}
		while (min_ra_cnt < 0)
		{
			if (ps_rra(ps) == -1)
				return (NULL);
			min_ra_cnt++;
		}
		if (ps_pa(ps) == -1)
			return (NULL);
	}
	min_ra_cnt = ps_get_insert_pos_asc(ps->stack_a, -1);
	while (min_ra_cnt > 0)
	{
		if (ps_ra(ps) == -1)
			return (NULL);
		min_ra_cnt--;
	}
	while (min_ra_cnt < 0)
	{
		if (ps_rra(ps) == -1)
			return (NULL);
		min_ra_cnt++;
	}
	ps_print_ps(2, ps);
	cmdlst = ps->cmdlst;
	ps->cmdlst = NULL;
	return (cmdlst);
}

int	ps_init_turk_sort(const int *values, int size, t_push_swap **ps)
{
	int			*copy;

	copy = (int *)malloc(sizeof(int) * size);
	if (copy == NULL)
		return (-1);
	ft_memcpy(copy, values, sizeof(int) * size);
	if (ps_validate_no_duplicates(copy, size) == false)
		return (free(copy), -1);
	if (ps_renumber(copy, size) == -1)
		return (free(copy), -1);
	*ps = ps_new_ps(copy, size);
	free(copy);
	if (*ps == NULL)
		return (-1);
	return (0);
}

void	ps_finalize_turk_sort(t_push_swap **ps)
{
	ps_destroy_ps(*ps);
	*ps = NULL;
	return ;
}
