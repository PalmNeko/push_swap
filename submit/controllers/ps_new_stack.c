/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_new_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:20:32 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/31 16:20:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_ps_stack	*ps_new_stack(void)
{
	t_ps_stack	*new_stack;

	new_stack = (t_ps_stack *)malloc(sizeof(t_ps_stack));
	if (new_stack == NULL)
		return (NULL);
	new_stack->top = NULL;
	new_stack->size = 0;
}
