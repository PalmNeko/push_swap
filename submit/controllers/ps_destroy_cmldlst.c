/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_destroy_cmldlst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:23:13 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/31 17:23:13 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_types.h"
#include <stdlib.h>

void	ps_destroy_cmdlst(t_ps_cmdlst *cmdlst)
{
	if (cmdlst == NULL)
		return (NULL);
	ft_lstclear(&cmdlst->top, free);
	free(cmdlst);
}
