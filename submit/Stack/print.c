/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 01:21:53 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/15 01:21:53 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_printf.h"
#include "libft.h"

void	print_stack(t_stack *stack)
{
	int		index;

	index = stack->len - 1;
	ft_putstr_fd("top\n", 1);
	while (index >= 0)
	{
		ft_printf("%d\n", stack->stack[index]);
		index--;
	}
}
