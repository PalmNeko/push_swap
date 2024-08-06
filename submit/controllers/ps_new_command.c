/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_new_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:38:40 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/06 18:38:40 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ps_new_command(const char *command)
{
	char	*dup_str;
	t_list	*lst;

	dup_str = ft_strdup(command);
	if (dup_str == NULL)
		return (NULL);
	lst = ft_lstnew(dup_str);
	if (lst == NULL)
		return (free(dup_str), NULL);
	return (lst);
}
