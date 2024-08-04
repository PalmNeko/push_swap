/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_insert_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 11:51:09 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/04 11:51:09 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "libft.h"

int	ps_get_max_value(t_ps_stack *stack);
int	ps_get_min_value(t_ps_stack *stack);
int	ps_convert_min_pos(int pos, int size);

/**
 * desc
 */
int	ps_get_insert_pos_desc(t_ps_stack *stack, int value)
{
	int		min;
	int		max;
	int		pos;
	t_iter	itr;
	t_list	*lst;

	min = ps_get_min_value(stack);
	max = ps_get_max_value(stack);
	ft_lstinit_itr(stack->top, &itr);
	pos = 0;
	while (itr.has_next(&itr))
	{
		lst = itr.next(&itr);
		if (max == *(int *)(lst->content) && value > max)
			return (ps_convert_min_pos(pos, ft_lstsize(stack->top)));
		else if (min == *(int *)(lst->prev->content) && value < min)
			return (ps_convert_min_pos(pos, ft_lstsize(stack->top)));
		else if (*(int *)(lst->content) < value && value < *(int *)(lst->prev->content))
			return (ps_convert_min_pos(pos, ft_lstsize(stack->top)));
		pos++;
	}
	return (ps_convert_min_pos(pos, ft_lstsize(stack->top)));
}

int	ps_convert_min_pos(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (pos - size);
}

int	ps_get_max_value(t_ps_stack *stack)
{
	t_iter	itr;
	t_list	*lst;
	int		value;
	int		max;

	if (stack->top == NULL)
		return (0);
	ft_lstinit_itr(stack->top, &itr);
	lst = itr.current;
	value = *(int *)lst->content;
	max = value;
	while (itr.has_next(&itr))
	{
		lst = itr.next(&itr);
		value = *(int *)lst->content;
		if (max < value)
			max = value;
	}
	return (value);
}

int	ps_get_min_value(t_ps_stack *stack)
{
	t_iter	itr;
	t_list	*lst;
	int		value;
	int		min;

	if (stack->top == NULL)
		return (0);
	ft_lstinit_itr(stack->top, &itr);
	lst = itr.current;
	value = *(int *)lst->content;
	min = value;
	while (itr.has_next(&itr))
	{
		lst = itr.next(&itr);
		value = *(int *)lst->content;
		if (min > value)
			min = value;
	}
	return (value);
}
