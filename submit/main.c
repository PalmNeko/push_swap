/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:23:34 by marvin            #+#    #+#             */
/*   Updated: 2024/02/24 00:23:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"

static bool	validate_argument(int argc, char *argv[]);
static bool	is_valid_num(char *str);
static int	print_error(void);

int main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	if (validate_argument(argc, argv))
		return (print_error());
}

static bool	validate_argument(int argc, char *argv[])
{
	int	index;

	index = 0;
	while (index < argc)
	{
		if (is_valid_num(argv[index]))
			return (false);
		index++;
	}
	return (true);
}

static bool	is_valid_num(char *str)
{
	if (*str < '1' || *str > '9')
		return (false);
	while (*str != '\0' && ft_isdigit(*str))
		str++;
	if (*str != '\0')
		return (false);
	return (true);
}

static int	print_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (0);
}