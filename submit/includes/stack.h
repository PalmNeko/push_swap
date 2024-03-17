/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:40:52 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/26 16:40:52 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

/**
 * @param stack - stack data
 * @param len - now stack len
 * @param max_len - max stack len
 * @param push
 * @param swap
 * @param pop
 * @param rotate
 * @param shift_up same rotate
 * @param reverse_rotate
 * @param shift_down same reverse_rotate
 */
typedef struct s_stack {
	int				*stack;
	int				max_len;
	int				len;
	void			(*push)(struct s_stack *self, int value);
	void			(*swap)(struct s_stack *self);
	int				(*pop)(struct s_stack *self);
	void			(*rotate)(struct s_stack *self);
	void			(*shift_up)(struct s_stack *self);
	void			(*reverse_rotate)(struct s_stack *self);
	void			(*shift_down)(struct s_stack *self);
	struct s_stack	*(*clone)(struct s_stack *self);
	int				*(*get_head)(struct s_stack *self, int index_from_top);
}	t_stack;

t_stack	*create_stack(int max_len);
void	destroy_stack(t_stack *stack);
void	print_stack(t_stack *stack);

#endif