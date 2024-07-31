/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_destroy_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:28:01 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/31 16:28:01 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_types.h"
#include "libft.h"
#include <stdlib.h>

void	ps_destroy_stack(t_ps_stack *stack)
{
	if (stack == NULL)
		return ;
	ft_lstclear(&stack->top, free);
	free(stack);
	return ;
}
