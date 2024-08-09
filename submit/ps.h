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

/** stack */
void		ps_destroy_stack(t_ps_stack *stack);
t_list		*ps_get_stack(const t_ps_stack *stack, int n);
t_ps_stack	*ps_new_stack(void);
t_list		*ps_pop_stack(t_ps_stack *stack);
int			ps_push_stack(t_ps_stack *stack, int value);
void		ps_swap_stack(const	t_ps_stack *stack);
int			ps_at(t_ps_stack *stack, int at);

/** command */
t_list		*ps_new_command(const char *command);
void		ps_destroy_command(t_list *command);
t_ps_stack	*ps_clone_stack(t_ps_stack *stack);

/** command list */
int			ps_append_cmdlst(t_ps_cmdlst *cmdlst, const char *command);
void		ps_destroy_cmdlst(t_ps_cmdlst *cmdlst);
t_list		*ps_get_cmdlst(t_ps_cmdlst *cmdlst, int n);
t_ps_cmdlst	*ps_new_cmdlst(void);
t_ps_cmdlst	*ps_clone_cmdlst(t_ps_cmdlst *cmdlst);
t_ps_cmdlst	*ps_compress_command(
				t_ps_cmdlst *cmdlst,
				char *const cmd_pattern[],
				const char *replace_command);
t_ps_cmdlst	*ps_compress_commands(
				t_ps_cmdlst *cmdlst,
				char **const *cmd_patterns,
				char *const *replace_cmds,
				int size);
t_ps_cmdlst	*ps_compress_cmdlst(t_ps_cmdlst *cmdlst);

/** push swap */
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
int			ps_get_target_size(t_push_swap *ps, t_target target);
int			(*ps_get_func_get_insert_pos(t_target target))(t_ps_stack *, int);
int			ps_get_value(t_list *lst);
t_ps_stack	*ps_get_target_stack(t_push_swap *ps, t_target target);
int			ps_swap_target(t_push_swap *ps, t_target target);
t_ps_cmdlst	*ps_compress_swap(t_ps_cmdlst *cmdlst);
t_push_swap	*ps_clone_ps(t_push_swap *ps);

/** validate */
bool		ps_validate_no_duplicates(int *values, size_t len);
bool		ps_validate_is_sorted(t_push_swap *ps);

/** calculator */
int			ps_renumber(int *values, int size);
int			*ps_str_to_int_array(const char *strs[], int size);
int			ps_get_insert_pos_desc(t_ps_stack *stack, int value);
int			ps_get_insert_pos_asc(t_ps_stack *stack, int value);
int			ps_get_min_value(t_ps_stack *stack);
int			ps_get_max_value(t_ps_stack *stack);
int			ps_convert_min_pos(int pos, int size);
int			ps_calc_rotate_cost(int rotate_a, int rotate_b);

/** logic */
int			ps_run_to_times(t_push_swap *ps, int (*f)(t_push_swap *), int cnt);
int			ps_rotate_two_stack(t_push_swap *ps, int rotate_a, int rotate_b);
int			ps_rotate_two_way(t_push_swap *ps, t_cmd fr, t_cmd frr, int cnt);
int			ps_push_to_a_until(t_push_swap *ps, int split_cnt, int until);
int			ps_push_to_b_until(t_push_swap *ps, int until);
t_ps_cmdlst	*ps_main(int argc, const char *argv[]);
void		ps_print_cmdlst(int fd, t_ps_cmdlst *cmdlst);
void		ps_print_error(int fd);
void		ps_print_ps(int fd, t_push_swap *ps);
t_ps_cmdlst	*ps_push_swap_sort(int *values, int size);
t_ps_cmdlst	*ps_compress_rotate(t_ps_cmdlst *cmdlst);
int			ps_swap_target_stack_if_needed(t_push_swap *ps, t_target target);

/** algorithm */
int			ps_rotate_target_to_right_order(
				t_push_swap *ps, t_target target);
int			ps_push_to_target_at_sorted_place(t_push_swap *ps, t_target target);
int			ps_push_to_target_at_sorted_place_until_remain(
				t_push_swap *ps, t_target target, int remain);
int			ps_sort_to_serial_number_only_top_three(
				t_push_swap *ps, t_target target);
int			ps_push_target_until(t_push_swap *ps, t_target target, int until);
t_cmd		ps_get_target_command(t_target target, t_cmd a_cmd, t_cmd b_cmd);
t_target	ps_get_other_target(t_target target);
int			ps_run_sort_seq(t_push_swap *ps, const t_cmd *f);
int			ps_turk_sort(t_push_swap *ps);
int			ps_quick_sort(t_push_swap *ps);
int			ps_sort_between_3and5(t_push_swap *ps);

#endif
