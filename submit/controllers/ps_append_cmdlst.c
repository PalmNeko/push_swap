/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_append_cmdlst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:26:57 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/31 17:26:57 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include <stdlib.h>

int	ps_append_cmdlst(t_ps_cmdlst *cmdlst, const char *command)
{
	t_list	*append_lst;

	append_lst = ps_new_command(command);
	if (append_lst == NULL)
		return (-1);
	ft_lstadd_back(&cmdlst->top, append_lst);
	return (0);
}
