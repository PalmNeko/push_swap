/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_new_cmdlst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:18:29 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/31 17:18:29 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_types.h"
#include <stdlib.h>

t_ps_cmdlst	*ps_new_cmdlst(void)
{
	t_ps_cmdlst	*cmdlst;

	cmdlst = (t_ps_cmdlst *)malloc(sizeof(t_ps_cmdlst));
	if (cmdlst == NULL)
		return (NULL);
	cmdlst->top = NULL;
	return (cmdlst);
}
