/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renumber_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:45:55 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/26 17:45:55 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

static int cmp_int(const void *a, const void *b)
{
	if (*(int *)a < *(int *)b)
		return (-1);
	else if (*(int *)a > *(int *)b)
		return (1);
	else
		return (0);
}

int	renumber_stack(t_stack *stack)
{
	t_stack			*copy;
	t_bsearch_arg	b_arg;
	int				index;
	int				*result;

	copy = stack->clone(stack);
	if (copy == NULL)
		return (-1);
	ft_selection_sort(copy->stack, copy->len, sizeof(int), cmp_int);
	b_arg = (t_bsearch_arg) {.base = copy->stack, .compar = cmp_int,
			.size = sizeof(int), .nmemb = copy->len};
	index = 0;
	while (index < stack->len)
	{
		b_arg.key = &stack->stack[index];
		result = ft_bsearch(&b_arg);
		if (result == NULL)
			return (-1);
		stack->stack[index] = result - copy->stack;
		index++;
	}
	return (0);
}
