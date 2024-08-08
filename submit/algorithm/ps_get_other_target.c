/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_other_target.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:49:07 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/08 19:49:07 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_types.h"

t_target	ps_get_other_target(t_target target)
{
	if (target == PS_TA)
		return (PS_TB);
	else if (target == PS_TB)
		return (PS_TA);
	return (PS_TNONE);
}
