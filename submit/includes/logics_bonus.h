/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logics_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:51:23 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/21 16:51:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGICS_BONUS_H
# define LOGICS_BONUS_H

# include "stack.h"
# include <stdbool.h>

bool	apply_order(t_stack *a, t_stack *b, char *command);

#endif
