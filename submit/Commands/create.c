/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:20:42 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/16 18:20:42 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "command_list.h"
#include <stdlib.h>

t_command_list	*create_command_list(void)
{
	t_command_list	*commands;

	commands = (t_command_list *)malloc(sizeof(t_command_list));
	if (commands == NULL)
		return (NULL);
	commands->commands = NULL;
	return (commands);
}
