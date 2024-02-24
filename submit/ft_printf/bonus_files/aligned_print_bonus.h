/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aligned_print_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:56:23 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/20 13:15:56 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALIGNED_PRINT_BONUS_H
# define ALIGNED_PRINT_BONUS_H

# include <stddef.h>
# include "conversion_specification_bonus.h"

int	t_conv_aligned_print(int fd, t_cs *cs, const char *str);
int	t_conv_aligned_print_char(int fd, t_cs *cs, char c);

#endif
