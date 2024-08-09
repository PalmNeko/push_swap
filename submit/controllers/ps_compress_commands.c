/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_compress_commands.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:24:56 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/08 12:24:56 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_ps_cmdlst	*ps_compress_commands(
	t_ps_cmdlst *cmdlst,
	char **const *cmd_patterns,
	char *const *replace_cmds,
	int size)
{
	int			index;
	t_ps_cmdlst	*new_cmdlst;
	t_ps_cmdlst	*tmp_cmdlst;

	new_cmdlst = ps_clone_cmdlst(cmdlst);
	if (new_cmdlst == NULL)
		return (NULL);
	index = 0;
	while (index < size)
	{
		tmp_cmdlst = ps_compress_command(
				new_cmdlst, cmd_patterns[index], replace_cmds[index]);
		ps_destroy_cmdlst(new_cmdlst);
		if (tmp_cmdlst == NULL)
			return (NULL);
		new_cmdlst = tmp_cmdlst;
		index++;
	}
	return (new_cmdlst);
}
