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

static int		print_error(void);
static t_stack	*generate_stack_strs_to(char *strs[], int len);

int	main(int argc, char *argv[])
{
	t_stack	*input_stack;

	if (argc == 1)
		return (0);
	input_stack = generate_stack_strs_to(&argv[1], argc - 1);
	if (input_stack == NULL)
		return (print_error());
	print_stack(input_stack);
	destroy_stack(input_stack);
	return (0);
}

static int	print_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (0);
}

static t_stack	*generate_stack_strs_to(char *strs[], int len)
{
	int		index;
	int		value;
	t_stack	*stack;

	if (validate_numstrings(strs, len) == false)
		return (NULL);
	stack = create_stack(len);
	if (stack == NULL)
		return (NULL);
	index = len - 1;
	while (index >= 0)
	{
		value = ft_atoi(strs[index]);
		if (errno != 0)
			return (destroy_stack(stack), NULL);
		stack->push(stack, value);
		index--;
	}
	if (validate_not_duplicated(stack->stack, stack->len) == false)
		return (destroy_stack(stack), NULL);
	return (stack);
}
