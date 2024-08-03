/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_cmdlst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:51:19 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 12:51:19 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "libft.h"

void	ps_print_cmdlst(int fd, t_ps_cmdlst *cmdlst)
{
	t_list	*itr;

	itr = cmdlst->top;
	while (itr != NULL)
	{
		ft_putstr_fd(itr->content, fd);
		itr = itr->next;
	}
	return ;
}
