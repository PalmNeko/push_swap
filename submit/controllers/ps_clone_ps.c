/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_clone_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:01:53 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/08 16:01:53 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include <stdlib.h>

t_push_swap	*ps_clone_ps(t_push_swap *ps)
{
	t_push_swap	*cloned_ps;

	cloned_ps = (t_push_swap *)ft_calloc(1, sizeof(t_push_swap));
	if (cloned_ps == NULL)
		return (NULL);
	cloned_ps->cmdlst = ps_clone_cmdlst(ps->cmdlst);
	if (cloned_ps->cmdlst == NULL)
		return (ps_destroy_ps(cloned_ps), NULL);
	cloned_ps->stack_a = ps_clone_stack(ps->stack_a);
	if (cloned_ps->stack_a == NULL)
		return (ps_destroy_ps(cloned_ps), NULL);
	cloned_ps->stack_b = ps_clone_stack(ps->stack_b);
	if (cloned_ps->stack_b == NULL)
		return (ps_destroy_ps(cloned_ps), NULL);
	return (cloned_ps);
}
