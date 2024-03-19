/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list_append_repeatedly.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:52:23 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/19 14:52:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_list.h"

t_command_list	*_command_list_append_repeatedly(
					t_command_list *self, const char *command, int times)
{
	t_command_list	*work;
	int				count;

	if (times <= 0)
		return (self);
	work = create_command_list();
	if (work == NULL)
		return(NULL);
	count = 0;
	while(count < times)
	{
		if (work->append(work, command) == NULL)
			return (destroy_command_list(work), NULL);
		count += 1;
	}
	ft_lstadd_back(&self->commands, work->commands);
	work->commands = NULL;
	destroy_command_list(work);
	return (self);
}
