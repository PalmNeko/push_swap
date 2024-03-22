/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 00:47:11 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/15 00:47:11 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATORS_H
# define VALIDATORS_H

# include <stddef.h>
# include <stdbool.h>
# include "stack.h"

bool	validate_no_duplicates(int *values, size_t len);
bool	validate_numstrings(char *strs[], int len);
bool	validate_is_sorted(t_stack *target);

#endif
