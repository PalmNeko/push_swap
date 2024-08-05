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
#include <limits.h>
#include <stdlib.h>

int			ps_init_turk_sort(const int *values, int size, t_push_swap **ps);
void		ps_finalize_turk_sort(t_push_swap **ps);
t_ps_cmdlst	*ps_solve_with_turk_sort(t_push_swap *ps);

t_ps_cmdlst	*ps_turk_sort(int *values, int size)
{
	t_push_swap	*ps;
	t_ps_cmdlst	*cmdlst;

	if (ps_init_turk_sort(values, size, &ps) == -1)
		return (NULL);
	cmdlst = ps_solve_with_turk_sort(ps);
	ps_finalize_turk_sort(&ps);
	return (cmdlst);
}

t_ps_cmdlst	*ps_solve_with_turk_sort(t_push_swap *ps)
{
	t_ps_cmdlst	*cmdlst;

	if (ps_push_to_b_until_three(ps) == -1)
		return (NULL);
	if (ps_rotate_b_to_desc(ps) == -1)
		return (NULL);
	if (ps_sort_for_three(ps) == -1)
		return (NULL);
	if (ps_push_to_a_until_zero(ps) == -1)
		return (NULL);
	if (ps_rotate_a_to_asc(ps) == -1)
		return (NULL);
	cmdlst = ps->cmdlst;
	ps->cmdlst = NULL;
	return (cmdlst);
}

int	ps_init_turk_sort(const int *values, int size, t_push_swap **ps)
{
	int			*copy;

	copy = (int *)malloc(sizeof(int) * size);
	if (copy == NULL)
		return (-1);
	ft_memcpy(copy, values, sizeof(int) * size);
	if (ps_validate_no_duplicates(copy, size) == false)
		return (free(copy), -1);
	if (ps_renumber(copy, size) == -1)
		return (free(copy), -1);
	*ps = ps_new_ps(copy, size);
	free(copy);
	if (*ps == NULL)
		return (-1);
	return (0);
}

void	ps_finalize_turk_sort(t_push_swap **ps)
{
	ps_destroy_ps(*ps);
	*ps = NULL;
	return ;
}
