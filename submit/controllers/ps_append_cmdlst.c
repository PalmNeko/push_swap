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

#include "ps_types.h"
#include <stdlib.h>

int	ps_append_cmdlst(t_ps_cmdlst *cmdlst, const char *command)
{
	char	*dup_str;
	t_list	*append_lst;

	dup_str = ft_strdup(command);
	if (dup_str == NULL)
		return (-1);
	append_lst = ft_lstnew(dup_str);
	if (append_lst == NULL)
		return (free(dup_str), -1);
	ft_lstadd_back(&cmdlst->top, append_lst);
	return (0);
}
