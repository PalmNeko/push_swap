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

typedef struct s_ps_cmdlst {
	t_list	*top;
}	t_ps_cmdlst;

typedef struct s_push_swap {
	t_ps_cmdlst	*cmdlst;
	t_ps_stack	*stack_a;
	t_ps_stack	*stack_b;
}	t_push_swap;

/** target stack */
typedef enum e_target {
	PS_TA,
	PS_TB,
	PS_TNONE,
}	t_target;

typedef int	(*t_cmd)(t_push_swap *);

#endif
