/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_at.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:12:03 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/08 12:12:03 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ps_at(t_ps_stack *stack, int at)
{
	t_list	*item;
	int		value;

	item = ps_get_stack(stack, at);
	value = ps_get_value(item);
	return (value);
}
