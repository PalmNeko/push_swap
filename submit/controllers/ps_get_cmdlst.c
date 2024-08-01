/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_cmdlst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:58:04 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/31 17:58:04 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_types.h"

t_list	*ps_get_cmdlst(t_ps_cmdlst *cmdlst, int n)
{
	return (ft_lstat(cmdlst->top, n));
}
