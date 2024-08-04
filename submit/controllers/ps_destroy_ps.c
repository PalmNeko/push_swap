/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_destroy_ps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 10:08:32 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 10:08:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ps.h"

void	ps_destroy_ps(t_push_swap *ps)
{
	if (ps == NULL)
		return ;
	ps_destroy_cmdlst(ps->cmdlst);
	ps_destroy_stack(ps->stack_a);
	ps_destroy_stack(ps->stack_b);
	free(ps);
	return ;
}
