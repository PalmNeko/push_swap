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
#include <stdlib.h>

t_ps_cmdlst	*ps_main(int argc, const char *argv[])
{
	int			*values;
	int			size;
	t_ps_cmdlst	*cmdlst;
	t_ps_cmdlst	*compressed_cmdlst;

	if (argc == 1)
		return (NULL);
	size = argc - 1;
	values = ps_str_to_int_array(argv + 1, size);
	if (values == NULL)
		return (NULL);
	cmdlst = ps_push_swap_sort(values, size);
	free(values);
	if (cmdlst == NULL)
		return (NULL);
	compressed_cmdlst = ps_compress_cmdlst(cmdlst);
	ps_destroy_cmdlst(cmdlst);
	return (compressed_cmdlst);
}
