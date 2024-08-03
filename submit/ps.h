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

int			ps_append_cmdlst(t_ps_cmdlst *cmdlst, const char *command);
void		ps_destroy_cmdlst(t_ps_cmdlst *cmdlst);
t_list		*ps_get_cmdlst(t_ps_cmdlst *cmdlst, int n);
t_ps_cmdlst	*ps_new_cmdlst(void);

void		ps_destroy_ps(t_push_swap *ps);
t_push_swap	*ps_new_ps(const int *values, int size);
int			ps_pa(t_push_swap *ps);
int			ps_pb(t_push_swap *ps);
int			ps_ra(t_push_swap *ps);
int			ps_rb(t_push_swap *ps);
int			ps_rr(t_push_swap *ps);
int			ps_rra(t_push_swap *ps);
int			ps_rrb(t_push_swap *ps);
int			ps_rrr(t_push_swap *ps);
int			ps_sa(t_push_swap *ps);
int			ps_sb(t_push_swap *ps);
int			ps_ss(t_push_swap *ps);

bool	ps_validate_no_duplicates(int *values, size_t len);

int			ps_renumber(int *values, int size);
int			*ps_str_to_int_array(const char *strs[], int size);

#endif
