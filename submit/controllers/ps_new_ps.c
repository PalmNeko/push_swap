/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_new_ps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 10:03:22 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 10:03:22 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include <stdlib.h>

t_push_swap	*ps_new_ps(const int *values, int size)
{
	int			index;
	t_push_swap	*ps;

	ps = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (ps == NULL)
		return (NULL);
	*ps = (t_push_swap){.cmdlst = NULL, .stack_a = NULL, .stack_b = NULL};
	ps->stack_a = ps_new_stack();
	if (ps->stack_a == NULL)
		return (ps_destroy_ps(ps), NULL);
	ps->stack_b = ps_new_stack();
	if (ps->stack_b == NULL)
		return (ps_destroy_ps(ps), NULL);
	ps->cmdlst = ps_new_cmdlst();
	if (ps->cmdlst == NULL)
		return (ps_destroy_ps(ps), NULL);
	index = size - 1;
	while (index >= 0)
	{
		if (ps_push_stack(ps->stack_a, values[index]) == -1)
			return (ps_destroy_ps(ps), NULL);
		index--;
	}
	return (ps);
}
