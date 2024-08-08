/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_run_sort_seq.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:14:32 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/08 19:14:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_types.h"

/**
 * f array must terminated null.
 */
int	ps_run_sort_seq(t_push_swap *ps, const t_cmd *f)
{
	while (*f != NULL)
	{
		if ((*f)(ps) == -1)
			return (-1);
		f++;
	}
	return (0);
}
