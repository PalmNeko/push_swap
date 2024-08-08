/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_target_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:45:17 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/08 19:45:17 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_types.h"

t_cmd	ps_get_target_command(t_target target, t_cmd a_cmd, t_cmd b_cmd)
{
	if (target == PS_TA)
		return (a_cmd);
	else if (target == PS_TB)
		return (b_cmd);
	return (NULL);
}
