/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:28:27 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/19 14:28:27 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_list.h"

t_command_list	*compress_straight_rotate(
		t_command_list *commands, int stack_size);

t_command_list	*compress_commands(t_command_list *commands, int stack_size)
{
	return (compress_straight_rotate(commands, stack_size));
}

t_command_list	*compress_straight_rotate(t_command_list *commands, int stack_size)
{
	t_command_list	*compressed_commands;
	t_list			*iter;
	int				rotate_count;

	compressed_commands = create_command_list();
	if (compressed_commands == NULL)
		return (NULL);
	rotate_count = 0;
	iter = commands->commands;
	while (iter != NULL)
	{
		if (ft_strncmp(iter->content, "ra", 2) == 0)
			rotate_count += 1;
		else
		{
			if (compressed_commands->append_repeatedly(
				compressed_commands, "ra", rotate_count) == NULL)
				return (destroy_command_list(compressed_commands), NULL);
			compressed_commands->append(compressed_commands, iter->content);
			rotate_count = 0;
		}
		if (rotate_count == stack_size)
			rotate_count = 0;
		iter = iter->next;
	}
	if (compressed_commands->append_repeatedly(
		compressed_commands, "ra", rotate_count) == NULL)
		return (destroy_command_list(compressed_commands), NULL);
	return (compressed_commands);
}
