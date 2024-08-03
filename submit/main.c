/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:41:11 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 12:59:57 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	main(int argc, char *argv[])
{
	t_ps_cmdlst	*cmdlst;

	if (argc == 1)
		return (0);
	cmdlst = ps_main(argc, argv);
	if (cmdlst == NULL)
	{
		ps_print_error(2);
		return (1);
	}
	ps_print_cmdlst(1, cmdlst);
	return (0);
}
