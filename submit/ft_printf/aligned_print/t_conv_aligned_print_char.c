/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_conv_aligned_print_char.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:08:00 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/20 13:14:39 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>
#include "libft.h"
#include "conversion_specification.h"
#include "conversion_specification_utils.h"
#include "aligned_print.h"
#include "string_util.h"

int	left_aligned_print_char(int fd, char c, size_t min_len);
int	right_aligned_print_char(int fd, char c, size_t min_len, int pad_zero);

int	t_conv_aligned_print_char(int fd, t_cs *cs, char c)
{
	int	min_len;
	int	print_len;

	min_len = 0;
	if (cs->is_specified_min_field_width != false)
		min_len = cs->minimum_field_width;
	print_len = -1;
	if (cs->flag_minus == true)
		print_len = left_aligned_print_char(fd, c, min_len);
	else
		print_len = right_aligned_print_char(fd, c, min_len, cs->flag_zero);
	return (print_len);
}

int	left_aligned_print_char(int fd, char c, size_t min_len)
{
	size_t	len;
	int		now_print_len;

	len = 1;
	if (ft_putchar_fd(c, fd) < 0)
		return (-1);
	if (len <= min_len)
	{
		now_print_len = repeat_print_fd(fd, " ", (int)(min_len - len));
		if (now_print_len < 0)
			return (-1);
		len += now_print_len;
	}
	if (len > INT_MAX)
		return (-1);
	return (len);
}

int	right_aligned_print_char(int fd, char c, size_t min_len, int pad_zero)
{
	size_t	len;
	char	*pad_str;
	int		now_print_len;

	len = 1;
	if (pad_zero != 0)
		pad_str = "0";
	else
		pad_str = " ";
	if (len <= min_len)
	{
		now_print_len = repeat_print_fd(fd, pad_str, (int)(min_len - len));
		if (now_print_len < 0)
			return (-1);
		len += now_print_len;
	}
	if (len > INT_MAX)
		return (-1);
	if (ft_putchar_fd(c, fd) < 0)
		return (-1);
	return (len);
}
