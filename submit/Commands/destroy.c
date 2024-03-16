/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:22:34 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/16 18:22:34 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "command_list.h"
#include <stdlib.h>

static void	del_command(void *content)
{
	free(content);
}

void	destroy_command_list(t_command_list *commands)
{
	ft_lstclear(&commands->commands, del_command);
	free(commands);
}
