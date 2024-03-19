/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:09:08 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/18 18:09:08 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_list.h"
#include "libft.h"
#include "ft_printf.h"

static void print_command(void *content)
{
	char	*command;

	command = content;
	ft_printf("%s\n", command);
	return ;
}

void	print_commands(t_command_list *commands)
{
	ft_lstiter(commands->commands, print_command);
}
