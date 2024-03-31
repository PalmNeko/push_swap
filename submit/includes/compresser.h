/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compresser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:52:55 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/19 17:52:55 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPRESSER_H
# define COMPRESSER_H

# include "command_list.h"
# include "stack.h"

t_command_list	*compress_straight_rotate(
					t_command_list *commands, int stack_size);
t_command_list	*halfcut_straight_rotate(
					t_command_list *commands, int stack_size);
int				renumber_stack(t_stack *stack);

#endif
