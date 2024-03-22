/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_is_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:54:32 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/21 16:54:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "printers.h"
#include <stdbool.h>
#include <limits.h>

bool	validate_is_sorted(t_stack *target)
{
	int	pre_value;
	int	offset;

	offset = target->len;
	pre_value = INT_MIN;
	while (offset > 0)
	{
		if (target->stack[offset - 1] < pre_value)
			return (false);
		pre_value = target->stack[offset - 1];
		offset--;
	}
	return (true);
}
