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

bool	validate_not_duplicated(int *values, size_t len);
bool	validate_numstrings(char *strs[], int len);

#endif
