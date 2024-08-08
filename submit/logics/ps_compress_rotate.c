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
	t_ps_cmdlst		*new_cmdlst;
	char **const	*cmd_patterns = (char **[]){
		(char *[]){"ra", "rb", NULL},
		(char *[]){"rb", "ra", NULL},
		(char *[]){"rra", "rrb", NULL},
		(char *[]){"rrb", "rra", NULL}};
	char *const		*replace_cmds = (char *[]){
		"rr", "rr", "rrr", "rrr", NULL};

	new_cmdlst = ps_compress_commands(cmdlst, cmd_patterns, replace_cmds, 4);
	return (new_cmdlst);
}
