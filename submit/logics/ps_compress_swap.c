/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_compress_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:22:15 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/08 12:22:15 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_ps_cmdlst	*ps_compress_swap(t_ps_cmdlst *cmdlst)
{
	t_ps_cmdlst		*new_cmdlst;
	char **const	*cmd_patterns = (char **[]){
		(char *[]){"sa", "sb", NULL},
		(char *[]){"sb", "sa", NULL}};
	char *const		*replace_cmds = (char *[]){
		"ss",
		"ss", NULL};

	new_cmdlst = ps_compress_commands(cmdlst, cmd_patterns, replace_cmds, 2);
	return (new_cmdlst);
}
