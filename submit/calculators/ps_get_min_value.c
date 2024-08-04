/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_min_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:49:52 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/04 18:49:52 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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
	return (min);
}
