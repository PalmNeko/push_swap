/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _logics.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:04:21 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/18 18:04:21 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LOGICS_H
# define _LOGICS_H

# include "stack.h"
# include "command_list.h"

t_command_list	*push_swap_bubble_sort(t_stack *stack_a, t_stack *stack_b);
t_command_list	*compress_commands(t_command_list *commands, int stack_size);

#endif
