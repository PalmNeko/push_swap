/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:51:23 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/31 16:51:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_types.h"

void	ps_swap_stack(const	t_ps_stack *stack)
{
	t_list	*first;
	t_list	*second;

	first = ft_lstat(stack->top, 0);
	second = ft_lstat(stack->top, 1);
	if (first == NULL || second == NULL)
		return ;
	ft_memswap(first->content, second->content, sizeof(int));
	return ;
}
