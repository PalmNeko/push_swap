/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_func_get_insert_pos.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:23:40 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/09 16:23:40 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_get_insert_pos_func	ps_get_func_get_insert_pos(t_target target)
{
	if (target == PS_TA)
		return (ps_get_insert_pos_asc);
	else if (target == PS_TB)
		return (ps_get_insert_pos_desc);
	return (NULL);
}
