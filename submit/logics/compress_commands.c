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
#include "compresser.h"

t_command_list	*compress_commands(t_command_list *commands, int stack_size)
{
	t_command_list	*compressed;
	t_command_list	*tmp;

	tmp = commands;
	compressed = compress_straight_rotate(tmp, stack_size);
	if (compressed == NULL)
		return (NULL);
	tmp = compressed;
	compressed = halfcut_straight_rotate(tmp, stack_size);
	destroy_command_list(tmp);
	if (compressed == NULL)
		return (NULL);
	return (compressed);
}
