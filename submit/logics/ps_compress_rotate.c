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

t_ps_cmdlst	*ps_compress_command(
				t_ps_cmdlst *cmdlst,
				char *const cmd_pattern[],
				const char *replace_command);
bool		ps_match_cmd_pattern(t_list *cmdlst, char *const cmd_pattern[]);
int			ps_count_command_len(char *const cmd_pattern[]);
t_list		*ps_skiped_list(t_list *lst, int cnt);

t_ps_cmdlst	*ps_compress_rotate(t_ps_cmdlst *cmdlst)
{
	int			index;
	t_ps_cmdlst	*new_cmdlst;
	t_ps_cmdlst	*tmp_cmdlst;
	char		***cmd_patterns;
	char		**replace_cmds;

	cmd_patterns = (char **[]) {
		(char *[]){"ra", "rb", NULL}, (char *[]){"rb", "ra", NULL},
		(char *[]){"rra", "rrb", NULL}, (char *[]){"rrb", "rra", NULL}};
	replace_cmds = (char *[]) {"rr", "rr", "rrr", "rrr", NULL};
	new_cmdlst = ps_clone_cmdlst(cmdlst);
	if (new_cmdlst == NULL)
		return (NULL);
	index = 0;
	while (index < 4)
	{
		tmp_cmdlst = ps_compress_command(new_cmdlst, cmd_patterns[index], replace_cmds[index]);
		ps_destroy_cmdlst(new_cmdlst);
		if (tmp_cmdlst == NULL)
			return (NULL);
		new_cmdlst = tmp_cmdlst;
		index++;
	}
	return (new_cmdlst);
}

t_ps_cmdlst	*ps_compress_command(
				t_ps_cmdlst *cmdlst,
				char *const cmd_pattern[],
				const char *replace_command)
{
	t_list		*itr;
	t_ps_cmdlst	*new_cmdlst;
	const char	*append_command;
	bool		is_match;

	itr = cmdlst->top;
	new_cmdlst = ps_new_cmdlst();
	if (new_cmdlst == NULL)
		return (NULL);
	while (itr != NULL)
	{
		is_match = ps_match_cmd_pattern(itr, cmd_pattern);
		if (is_match)
			append_command = replace_command;
		else
			append_command = itr->content;
		if (is_match)
			itr = ps_skiped_list(itr, ps_count_command_len(cmd_pattern));
		else
			itr = itr->next;
		if (ps_append_cmdlst(new_cmdlst, append_command) == -1)
			return (ps_destroy_cmdlst(new_cmdlst), NULL);
	}
	return (new_cmdlst);
}

bool	ps_match_cmd_pattern(t_list *cmdlst, char *const cmd_pattern[])
{
	while (*cmd_pattern != NULL)
	{
		if (cmdlst == NULL)
			return (false);
		if (ft_strcmp(cmdlst->content, *cmd_pattern) != 0)
			return (false);
		cmd_pattern ++;
		cmdlst = cmdlst->next;
	}
	return (true);
}

int			ps_count_command_len(char *const cmd_pattern[])
{
	int	cnt;

	cnt = 0;
	while (*cmd_pattern != NULL)
	{
		cmd_pattern++;
		cnt++;
	}
	return (cnt);
}

t_list		*ps_skiped_list(t_list *lst, int cnt)
{
	int	index;

	index = 0;
	while (lst != NULL && index < cnt)
	{
		lst = lst->next;
		index++;
	}
	return (lst);
}
