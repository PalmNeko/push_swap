/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_insert_pos_asc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:51:30 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/04 18:51:30 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "libft.h"

/**
 * asc
 */
int	ps_get_insert_pos_asc(t_ps_stack *stack, int value)
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
		if ((max == *(int *)(lst->prev->content)
			&& min == *(int *)(lst->content))
			&& (value > max || value < min))
			return (ps_convert_min_pos(pos, stack->size));
		else if (*(int *)(lst->prev->content) < value
			&& value < *(int *)(lst->content))
			return (ps_convert_min_pos(pos, stack->size));
		pos++;
	}
	return (ps_convert_min_pos(pos, stack->size));
}
