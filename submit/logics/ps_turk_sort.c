/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:31:46 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 12:31:46 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "libft.h"
#include <stdlib.h>

t_ps_cmdlst	*ps_turk_sort(int *values, int size)
{
	t_push_swap	*ps;
	t_ps_cmdlst	*cmdlst;
	int			*copy;

	copy = (int *)malloc(sizeof(int) * size);
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy, values, sizeof(int) * size);
	if (ps_validate_no_duplicates(copy, size) == false)
		return (free(copy), NULL);
	if (ps_renumber(copy, size) == -1)
		return (free(copy), NULL);
	ps = ps_new_ps(copy, size);
	free(copy);
	if (ps == NULL)
		return (NULL);
	if (ft_lstsize(ps->stack_a) == 3 && ps_sort_for_three(ps) == -1)
		return (ps_destroy_ps(ps), NULL);
	cmdlst = ps->cmdlst;
	ps->cmdlst = NULL;
	ps_destroy_ps(ps);
	return (cmdlst);
}
