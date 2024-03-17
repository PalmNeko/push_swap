/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _stack_methods.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:40:43 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/26 16:40:43 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STACK_METHODS_H
# define _STACK_METHODS_H

# include "stack.h"

void			_stack_push(struct s_stack *self, int value);
void			_stack_swap(struct s_stack *self);
int				_stack_pop(struct s_stack *self);
void			_stack_rotate(struct s_stack *self);
void			_stack_reverse_rotate(struct s_stack *self);
struct s_stack	*_stack_clone(struct s_stack *self);
int				*_stack_get_head(t_stack *self, int index_from_top);

#endif