/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:20:45 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/16 18:20:45 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_LIST_H
# define COMMAND_LIST_H

# include "libft.h"

typedef struct s_command_list {
	t_list	*commands;
}	t_command_list;

t_command_list	*create_command_list(void);
void			destroy_command_list(t_command_list *commands);

#endif