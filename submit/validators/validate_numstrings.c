/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_numstrings.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 01:36:26 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/15 01:36:26 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"

static bool	is_valid_num(char *str);

/**
 * @brief validate 'strs' are number format.
 * @param strs - string array.
 * @param len - strs array length.
 * @return false if len == 0 or included string not number format.
 * true if all strings is number format.
 */
bool	validate_numstrings(char *strs[], int len)
{
	int	index;

	index = 0;
	while (index < len)
	{
		if (is_valid_num(strs[index]) == false)
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
