/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logics.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:08:05 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/18 17:08:05 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGICS_H
# define LOGICS_H

# include "stack.h"
# include "command_list.h"

t_command_list	*generate_sort_commands(t_stack	*input_stack);

#endif
