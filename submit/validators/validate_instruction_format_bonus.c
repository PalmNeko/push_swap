/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_instruction_format.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:36:35 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/21 16:36:35 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

bool	validate_instruction_format(const char *instruction)
{
	const char	*commands[] = {
		"pa", "pb",
		"sa", "sb", "ss",
		"ra", "rb", "rr",
		"rra", "rrb", "rrr"
	};
	const int	commands_cnt = 11;
	int			index;
	char		*check_command;
	int			len;

	index = 0;
	while (index < commands_cnt)
	{
		check_command = commands[index];
		len = ft_strlen(check_command);
		if (ft_strncmp(check_command, instruction, len + 1) == 0)
			return (true);
		index++;
	}
	return (false);
}
