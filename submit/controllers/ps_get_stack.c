/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:42:48 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/31 16:42:48 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_types.h"

t_list	*ps_get_stack(const t_ps_stack *stack, int n)
{
	t_list	*at_stack;

	at_stack = ft_lstat(stack->top, n);
	if (at_stack == NULL)
		return (NULL);
	return (at_stack);
}
