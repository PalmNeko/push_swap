/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:31:46 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 12:31:46 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "libft.h"
#include <limits.h>
#include <stdlib.h>

t_ps_cmdlst	*ps_solve_with_turk_sort(t_push_swap *ps)
{
	t_ps_cmdlst	*cmdlst;

	if (ps_push_to_b_until_three(ps) == -1)
		return (NULL);
	if (ps_rotate_b_to_desc(ps) == -1)
		return (NULL);
	while (ft_lstsize(ps->stack_a->top) > 3)
	{
		if (ps_pb(ps) == -1)
			return (NULL);
	}
	if (ps_sort_for_three(ps) == -1)
		return (NULL);
	if (ps_push_to_a_until_zero(ps) == -1)
		return (NULL);
	if (ps_rotate_a_to_asc(ps) == -1)
		return (NULL);
	cmdlst = ps->cmdlst;
	ps->cmdlst = NULL;
	return (cmdlst);
}
