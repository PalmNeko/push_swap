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

static bool	validate_argument(int argc, char *argv[]);
static bool	is_valid_num(char *str);
static int	print_error(void);
static t_stack	*generate_stack_strs_to(char *strs[], int len);

int main(int argc, char *argv[])
{
	t_stack	*input_stack;
	int		index;

	if (argc == 1)
		return (0);
	if (validate_argument(argc, argv))
		return (print_error());
	input_stack = generate_stack_strs_to(&argv[1], argc - 1);
	if (input_stack == NULL)
		return (print_error());
	index = input_stack->len - 1;
	ft_putstr_fd("top\n", 1);
	while (index >= 0)
	{
		ft_printf("%d\n", input_stack->stack[index]);
		index--;
	}
	destroy_stack(input_stack);
	return (0);
}

static bool	validate_argument(int argc, char *argv[])
{
	int	index;

	index = 0;
	while (index < argc)
	{
		if (is_valid_num(argv[index]))
			return (false);
		index++;
	}
	return (true);
}

static bool	is_valid_num(char *str)
{
	if (*str < '1' || *str > '9')
		return (false);
	while (*str != '\0' && ft_isdigit(*str))
		str++;
	if (*str != '\0')
		return (false);
	return (true);
}

static int	print_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (0);
}

static t_stack	*generate_stack_strs_to(char *strs[], int len)
{
	int	index;
	int	value;
	t_stack	*stack;

	stack = create_stack(len);
	if (stack == NULL)
		return (NULL);
	index = len - 1;
	while (index >= 0)
	{
		value = ft_atoi(strs[index]);
		if (errno != 0)
		{
			destroy_stack(stack);
			return (NULL);
		}
		stack->push(stack, value);
		index--;
	}
	if (validate_not_duplicated(stack->stack, stack->len) == false)
	{
		destroy_stack(stack);
		return (NULL);
	}
	return (stack);
}
