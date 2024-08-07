/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_compress_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:36:12 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/06 18:36:12 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include <stdbool.h>

t_ps_cmdlst	*ps_compress_rotate(t_ps_cmdlst *cmdlst)
{
	int			index;
	t_ps_cmdlst	*new_cmdlst;
	t_ps_cmdlst	*tmp_cmdlst;
	char		***cmd_patterns;
	char		**replace_cmds;

	cmd_patterns = (char **[]){
		(char *[]){"ra", "rb", NULL}, (char *[]){"rb", "ra", NULL},
		(char *[]){"rra", "rrb", NULL}, (char *[]){"rrb", "rra", NULL}};
	replace_cmds = (char *[]){"rr", "rr", "rrr", "rrr", NULL};
	new_cmdlst = ps_clone_cmdlst(cmdlst);
	if (new_cmdlst == NULL)
		return (NULL);
	index = 0;
	while (index < 4)
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
