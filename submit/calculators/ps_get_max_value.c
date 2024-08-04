/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_max_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:49:29 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/04 18:49:29 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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
	return (max);
}
