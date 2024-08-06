/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_clone_cmdlst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:22:17 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/06 19:22:17 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include <stdlib.h>

t_ps_cmdlst	*ps_clone_cmdlst(t_ps_cmdlst *cmdlst)
{
	t_ps_cmdlst	*cloned_cmdlst;
	t_list		*cloned_lst;

	cloned_cmdlst = ps_new_cmdlst();
	if (cloned_cmdlst == NULL)
		return (NULL);
	cloned_lst = ft_lstmap(cmdlst->top, (void *(*)(void *))ft_strdup, free);
	if (cloned_lst == NULL)
		return (ps_destroy_cmdlst(cloned_cmdlst), NULL);
	cloned_cmdlst->top = cloned_lst;
	return (cloned_cmdlst);
}
