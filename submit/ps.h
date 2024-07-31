/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:21:25 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/31 16:21:25 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include "ps_types.h"

void		ps_destroy_stack(t_ps_stack *stack);
t_list		*ps_get_stack(const t_ps_stack *stack, int n);
t_ps_stack	*ps_new_stack(void);
t_list		*ps_pop_stack(const t_ps_stack *stack);
int			ps_push_stack(t_ps_stack *stack, int value);
void		ps_swap_stack(const	t_ps_stack *stack);

#endif
