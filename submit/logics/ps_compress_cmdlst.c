/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_compress_cmdlst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:20:26 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/08 12:20:26 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_ps_cmdlst	*ps_compress_cmdlst(t_ps_cmdlst *cmdlst)
{
	t_ps_cmdlst	*new_cmdlst;
	t_ps_cmdlst	*tmp;

	new_cmdlst = ps_compress_rotate(cmdlst);
	if (new_cmdlst == NULL)
		return (NULL);
	tmp = ps_compress_swap(new_cmdlst);
	ps_destroy_cmdlst(new_cmdlst);
	if (tmp == NULL)
		return (NULL);
	new_cmdlst = tmp;
	return (new_cmdlst);
}
