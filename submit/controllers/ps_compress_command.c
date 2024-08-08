/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_compress_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:53:22 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/07 17:53:22 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include <stdbool.h>

int		ps_replace_commands(
			t_ps_cmdlst *cmdlst,
			t_ps_cmdlst *new_cmdlst,
			char *const cmd_pattern[],
			const char *replace_command);
bool	ps_match_cmd_pattern(t_list *cmdlst, char *const cmd_pattern[]);
int		ps_count_command_len(char *const cmd_pattern[]);
t_list	*ps_skiped_list(t_list *lst, int cnt);

t_ps_cmdlst	*ps_compress_command(
				t_ps_cmdlst *cmdlst,
				char *const cmd_pattern[],
				const char *replace_command)
{
	t_ps_cmdlst	*new_cmdlst;

	if (cmdlst == NULL)
		return (NULL);
	new_cmdlst = ps_new_cmdlst();
	if (new_cmdlst == NULL)
		return (NULL);
	if (ps_replace_commands(
			cmdlst, new_cmdlst, cmd_pattern, replace_command) == -1)
		return (ps_destroy_cmdlst(new_cmdlst), NULL);
	return (new_cmdlst);
}

int	ps_replace_commands(
		t_ps_cmdlst *cmdlst,
		t_ps_cmdlst *new_cmdlst,
		char *const cmd_pattern[],
		const char *replace_command)
{
	t_list		*itr;
	const char	*append_command;
	bool		is_match;

	if (cmdlst == NULL)
		return (-1);
	itr = cmdlst->top;
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
			return (-1);
	}
	return (0);
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

int	ps_count_command_len(char *const cmd_pattern[])
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

t_list	*ps_skiped_list(t_list *lst, int cnt)
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
