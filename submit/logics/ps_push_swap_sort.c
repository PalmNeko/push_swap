/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_swap_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:33:59 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/05 15:33:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "libft.h"
#include <limits.h>
#include <stdlib.h>

int			ps_init_push_swap_sort(const int *values, int size, t_push_swap **ps);
void		ps_finalize_push_swap_sort(t_push_swap **ps);

t_ps_cmdlst	*ps_push_swap_sort(int *values, int size)
{
	t_push_swap	*ps;
	t_ps_cmdlst	*cmdlst;
	int			sort_result;

	if (ps_init_push_swap_sort(values, size, &ps) == -1)
		return (NULL);
	sort_result = 0;
	if (ps_validate_is_sorted(ps) == false)
		sort_result = ps_quick_sort(ps);
	if (sort_result == 0)
	{
		cmdlst = ps->cmdlst;
		ps->cmdlst = NULL;
	}
	else
		cmdlst = NULL;
	ps_finalize_push_swap_sort(&ps);
	return (cmdlst);
}

int	ps_init_push_swap_sort(const int *values, int size, t_push_swap **ps)
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

void	ps_finalize_push_swap_sort(t_push_swap **ps)
{
	ps_destroy_ps(*ps);
	*ps = NULL;
	return ;
}
