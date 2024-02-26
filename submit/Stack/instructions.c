/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:06:48 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/26 17:06:48 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
#include <stddef.h>

void	_stack_push(struct s_stack *self, int value)
{
	if (self->len >= self->max_len)
		return ;
	self->stack[self->len] = value;
	self->len += 1;
	return ;
}

void	_stack_swap(struct s_stack *self)
{
	const int	top_index = self->len - 1;
	int			top_copy;

	if (self->len <= 1)
		return ;
	top_copy = self->stack[top_index];
	self->stack[top_index] = self->stack[top_index - 1];
	self->stack[top_index - 1] = top_copy;
	return ;
}

int	_stack_pop(struct s_stack *self)
{
	const int	top_index = self->len - 1;

	return (self->stack[top_index]);
}

void	_stack_rotate(struct s_stack *self)
{
	const int	top_index = self->len - 1;
	int			top_value;

	if (self->len < 2)
		return ;
	top_value = self->stack[top_index];
	ft_memmove(&self->stack[1], &self->stack[0], sizeof(int) * (self->len - 1));
	self->stack[0] = top_value;
	return ;
}

void	_stack_reverse_rotate(struct s_stack *self)
{
	const int	top_index = self->len - 1;
	const int	bottom_index = 0;
	int			bottom_value;

	if (self->len < 2)
		return ;
	bottom_value = self->stack[bottom_index];
	ft_memmove(&self->stack[0], &self->stack[1], sizeof(int) * (self->len - 1));
	self->stack[top_index] = bottom_value;
	return ;
}
