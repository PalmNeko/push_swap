/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:53:02 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/11 15:20:53 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_UTIL_BONUS_H
# define STRING_UTIL_BONUS_H

# include "conversion_specification_bonus.h"

int		repeat_print_fd(int fd, const char *str, int repeat_cnt);
char	*pad_zero_str(char *str, int min_len);
char	*zero_pad_with_cs(t_cs *cs, char *num_str);

#endif
