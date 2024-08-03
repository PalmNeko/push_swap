/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:34:10 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 12:34:10 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_ps_cmdlst	*ps_main(int argc, const char *argv[])
{
	int 		*values;
	int			size;
	t_push_swap	*ps;
	t_ps_cmdlst	*cmdlst;

	if (argc == 1)
		return (-1);
	size = argc - 1;
	values = ps_str_to_int_array(argv + 1, size);
	if (values == NULL)
		return (-1);
	cmdlst = ps_turk_sort(values, size);
	free(values);
	return (cmdlst);
}
