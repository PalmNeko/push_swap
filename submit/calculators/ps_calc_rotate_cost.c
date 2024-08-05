/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calc_rotate_cost.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:31:09 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/05 14:31:09 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ps_calc_rotate_cost(int rotate_a, int rotate_b)
{
	if (rotate_a * rotate_b > 0)
		return (ft_max(ft_abs(rotate_a), ft_abs(rotate_b)));
	return (ft_abs(rotate_a) + ft_abs(rotate_b));
}
