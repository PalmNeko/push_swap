/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   halfcut_straight_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:51:36 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/19 17:51:36 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_list.h"

static int	halfcut_ra_statement(
				t_list **command_lst, t_command_list *new, int stack_size);

t_command_list	*halfcut_straight_rotate(
		t_command_list *commands, int stack_size)
{
	t_command_list	*zipped_cmds;
	t_list			*iter;

	zipped_cmds = create_command_list();
	if (zipped_cmds == NULL)
		return (NULL);
	iter = commands->commands;
	while (iter != NULL)
	{
		if (halfcut_ra_statement(
				&iter, zipped_cmds, stack_size) == -1)
			return (destroy_command_list(zipped_cmds), NULL);
		if (ft_strcmp(iter->content, "ra") != 0)
		{
			if (zipped_cmds->append(zipped_cmds, iter->content) == NULL)
				return (destroy_command_list(zipped_cmds), NULL);
		}
		iter = iter->next;
	}
	return (zipped_cmds);
}

static int	count_command(t_list *command_lst, const char *command)
{
	t_list	*iter;
	int		count;

	count = 0;
	iter = command_lst;
	while (iter != NULL)
	{
		if (ft_strcmp(iter->content, command) != 0)
			break ;
		count++;
		iter = iter->next;
	}
	return (count);
}

static int	halfcut_ra_statement(
	t_list **command_lst, t_command_list *new, int stack_size)
{
	t_list			*iter;
	int				ra_count;
	int				times;
	t_command_list	*append_result;

	ra_count = count_command(*command_lst, "ra");
	times = ra_count;
	while (times >= stack_size)
		times -= stack_size;
	append_result = NULL;
	if (times > stack_size / 2)
		append_result = new->append_repeatedly(new, "rra", stack_size - times);
	else
		append_result = new->append_repeatedly(new, "ra", times);
	if (append_result == NULL)
		return (-1);
	times = ra_count;
	iter = *command_lst;
	while (times > 0)
	{
		iter = iter->next;
		times--;
	}
	*command_lst = iter;
	return (0);
}
