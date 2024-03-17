/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:59:18 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/17 15:59:18 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_list.h"
#include "libft.h"
#include <stdlib.h>

t_command_list	*_command_list_append(t_command_list *self, const char *command)
{
	char	*copy;
	t_list	*new_command;

	copy = ft_strdup(command);
	if (copy == NULL)
		return (NULL);
	new_command = ft_lstnew(copy);
	if (new_command == NULL)
		return (free(copy), NULL);
	ft_lstadd_back(&self->commands, new_command);
	return (self);
}
