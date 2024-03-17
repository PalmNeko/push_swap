/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _command_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:57:44 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/17 15:57:44 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _COMMAND_LIST_H
# define _COMMAND_LIST_H

# include "command_list.h"

t_command_list	*_command_list_append(
					t_command_list *self, const char *command);

#endif
