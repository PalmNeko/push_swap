/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:43:34 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/07 18:26:27 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "libft.h"
#include "get_next_line.h"
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

int		ps_checker_main(int argc, const char *argv[]);
t_cmd	ps_get_command_function(const char *command);
int		ps_sort_by_standard_input(t_push_swap *ps);

int	main(int argc, const char *argv[])
{
	int	result;

	if (argc == 1)
		return (0);
	result = ps_checker_main(argc, argv);
	if (result == -1)
	{
		ps_print_error(2);
		return (1);
	}
	else if (result == 0)
	{
		ft_putstr_fd("OK\n", 1);
		return (0);
	}
	else
	{
		ft_putstr_fd("NG\n", 1);
		return (1);
	}
	return (0);
}

int	ps_checker_main(int argc, const char *argv[])
{
	int			*values;
	int			size;
	bool		is_sorted;
	t_push_swap	*ps;

	size = argc - 1;
	values = ps_str_to_int_array(argv + 1, size);
	if (values == NULL)
		return (-1);
	if (ps_validate_no_duplicates(values, size) == false)
		return (free(values), -1);
	if (ps_renumber(values, size) == -1)
		return (free(values), -1);
	ps = ps_new_ps(values, size);
	free(values);
	if (ps == NULL)
		return (-1);
	if (ps_sort_by_standard_input(ps) == -1)
		return (ps_destroy_ps(ps), -1);
	is_sorted = ps_validate_is_sorted(ps);
	ps_destroy_ps(ps);
	if (is_sorted == true)
		return (0);
	else
		return (1);
}

int	ps_sort_by_standard_input(t_push_swap *ps)
{
	char	*carry_up;
	char	*line;
	t_cmd	cmd;

	carry_up = NULL;
	errno = 0;
	line = get_next_line2(0, &carry_up);
	while (line != NULL)
	{
		if (ft_replace_last_newline(line) == false)
			return (free(carry_up), -1);
		cmd = ps_get_command_function(line);
		free(line);
		if (cmd == NULL)
			return (free(carry_up), -1);
		if (cmd(ps) == -1)
			return (free(carry_up), -1);
		line = get_next_line2(0, &carry_up);
	}
	free(carry_up);
	if (errno != 0)
		return (-1);
	return (0);
}

t_cmd	ps_get_command_function(const char *command)
{
	const char	*cmp_str[] = {
		"sa", "pa", "ra", "rra",
		"sb", "pb", "rb", "rrb",
		"ss", "rr", "rrr"
	};
	const t_cmd	ret_funcs[] = {
		ps_sa, ps_pa, ps_ra, ps_rra,
		ps_sb, ps_pb, ps_rb, ps_rrb,
		ps_ss, ps_rr, ps_rrr
	};
	int			index;

	index = 0;
	while (index < 11)
	{
		if (ft_strcmp(cmp_str[index], command) == 0)
			return (ret_funcs[index]);
		index++;
	}
	return (NULL);
}
