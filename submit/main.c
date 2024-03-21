/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:41:11 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/26 16:41:11 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "stack.h"
#include "errno.h"
#include "ft_printf.h"
#include "validators.h"
#include "command_list.h"
#include "logics.h"
#include "printers.h"

int	main(int argc, char *argv[])
{
	t_stack			*input_stack;
	t_command_list	*commands;


	if (argc == 1)
		return (0);
	input_stack = generate_stack_strs_to(&argv[1], argc - 1);
	if (input_stack == NULL)
		return (print_error());
	commands = generate_sort_commands(input_stack);
	destroy_stack(input_stack);
	if (commands == NULL)
		return (print_error());
	print_commands(commands);
	destroy_command_list(commands);
	return (0);
}
