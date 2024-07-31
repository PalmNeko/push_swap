/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:21:49 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/31 16:21:49 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_TYPES_H
# define PS_TYPES_H

# include "libft.h"

typedef struct s_ps_stack {
	t_list	*top;
	int		size;
}	t_ps_stack;

#endif
