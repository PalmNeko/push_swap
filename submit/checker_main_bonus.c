/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:43:34 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/20 18:43:34 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "validators_bonus.h"
#include "validators.h"
#include "command_list.h"
#include "logics_bonus.h"
#include "logics.h"
#include "printers.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

int				sort_by_commands(t_stack *a, t_command_list *commands);
t_command_list	*read_instructions(int fd);

int	main(int argc, char *argv[])
{
	t_stack			*input_stack;
	t_command_list	*commands;

	if (argc == 1)
		return (0);
	input_stack = generate_stack_strs_to(&argv[1], argc - 1);
	if (input_stack == NULL)
		return (print_error());
	commands = read_instructions(0);
	if (commands == NULL)
		return (destroy_stack(input_stack), print_error());
	if (sort_by_commands(input_stack, commands) == -1)
		return (destroy_stack(input_stack), destroy_command_list(commands),
			print_error());
	if (validate_is_sorted(input_stack) == true)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("NG\n", 1);
	destroy_command_list(commands);
	destroy_stack(input_stack);
	return (0);
}

int	sort_by_commands(t_stack *a, t_command_list *commands)
{
	t_stack	*b;
	t_list	*iter;

	b = create_stack(a->max_len);
	if (b == NULL)
		return (-1);
	iter = commands->commands;
	while (iter != NULL)
	{
		apply_order(a, b, iter->content);
		iter = iter->next;
	}
	destroy_stack(b);
	return (0);
}

t_command_list	*read_instructions(int fd)
{
	t_command_list	*commands;
	char			*instruction;
	char			*find_ptr;

	commands = create_command_list();
	if (commands == NULL)
		return (NULL);
	instruction = get_next_line(fd);
	while (instruction != NULL)
	{
		find_ptr = ft_strrchr(instruction, '\n');
		if (find_ptr == NULL)
			return (free(instruction), NULL);
		*find_ptr = '\0';
		if (validate_instruction_format(instruction) == false)
			return (free(instruction), destroy_command_list(commands), NULL);
		if (commands->append(commands, instruction) == NULL)
			return (free(instruction), destroy_command_list(commands), NULL);
		free(instruction);
		instruction = get_next_line(fd);
	}
	return (commands);
}
