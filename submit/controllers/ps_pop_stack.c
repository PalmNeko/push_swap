/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pop_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:46:50 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/31 16:46:50 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_types.h"

t_list	*ps_pop_stack(t_ps_stack *stack)
{
	t_list	*pop_stack;

	pop_stack = ft_lstpop(&(stack->top));
	return (pop_stack);
}
