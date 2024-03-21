/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_stack_strs_to.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:00:30 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/21 17:00:30 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "validators.h"
#include "libft.h"
#include <stdbool.h>
#include <stddef.h>

t_stack	*generate_stack_strs_to(char *strs[], int len)
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
	if (validate_no_duplicates(stack->stack, stack->len) == false)
		return (destroy_stack(stack), NULL);
	return (stack);
}
