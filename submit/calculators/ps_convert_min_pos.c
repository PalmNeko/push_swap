/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_convert_min_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:49:08 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/04 18:49:08 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ps_convert_min_pos(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (pos - size);
}
