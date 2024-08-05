/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:41:36 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 13:41:36 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "libft.h"
#include "ft_printf.h"

static void	ps_print_stacks(int fd, t_list *a, t_list *b, int max);
static void	ps_console_color_with_max(int fd, int value, int max);
static void	ps_console_color(int fd, int h, bool reset);
static int	ps_to_rgb(int h, int s, int v);

void	ps_print_ps(int fd, t_push_swap *ps)
{
	t_iter	itr_a;
	t_iter	itr_b;
	int		index;
	int		max;

	ft_lstinit_itr(ps->stack_a->top, &itr_a);
	ft_lstinit_itr(ps->stack_b->top, &itr_b);
	index = 0;
	max = ft_lstsize(ps->stack_a->top) + ft_lstsize(ps->stack_b->top) - 1;
	ft_dprintf(fd, "%5s %10s %10s\n", "num", "stack_a", "stack_b");
	while (itr_a.has_next(&itr_a) || itr_b.has_next(&itr_b))
	{
		ft_dprintf(fd, "%5d ", index);
		ps_print_stacks(fd, itr_a.next(&itr_a), itr_b.next(&itr_b), max);
		ft_dprintf(fd, "\n");
		index++;
	}
	return ;
}

static void	ps_print_stacks(int fd, t_list *a, t_list *b, int max)
{
	int	value;

	if (a != NULL)
	{
		value = *(int *)a->content;
		ps_console_color_with_max(fd, value, max);
		ft_dprintf(fd, "%10d ", value);
		ps_console_color(fd, 0, true);
	}
	else
		ft_dprintf(fd, "%10s ", "");
	if (b != NULL)
	{
		value = *(int *)b->content;
		ps_console_color_with_max(fd, value, max);
		ft_dprintf(fd, "%10d", value);
		ps_console_color(fd, 0, true);
	}
	else if (b == NULL)
		ft_dprintf(fd, "%10s", "");
	return ;
}

static void	ps_console_color_with_max(int fd, int value, int max)
{
	if (max == 0)
		ps_console_color(fd, 240, false);
	else
		ps_console_color(fd, 240 - ((double)value / max) * 240, false);
	return ;
}

static void	ps_console_color(int fd, int h, bool reset)
{
	int				rgb;
	unsigned char	colors[3];

	if (reset == true)
	{
		ft_dprintf(fd, "\033[0m");
		return ;
	}
	rgb = ps_to_rgb(h, 255, 255);
	colors[0] = (rgb >> 16) & 0xff;
	colors[1] = (rgb >> 8) & 0xff;
	colors[2] = (rgb >> 0) & 0xff;
	ft_dprintf(fd, "\033[38;2;%d;%d;%dm", colors[0], colors[1], colors[2]);
	return ;
}

/**
 * https://www.peko-step.com/tool/hsvrgb.html#ppick3
 * @return rgb
 */
static int	ps_to_rgb(int h, int s, int v)
{
	int				max;
	int				min;
	unsigned char	**rgb_values;
	int				index;
	int				result;

	max = v;
	min = max - ((s / 255.0) * max);
	index = h / 60;
	rgb_values = (unsigned char *[]){
		(unsigned char []){max, (h / 60.0) * (max - min) + min, min},
		(unsigned char []){((120 - h) / 60.0) *(max - min) + min, max, min},
		(unsigned char []){min, max, ((h - 120) / 60.0) * (max - min) + min},
		(unsigned char []){min, ((240 - h) / 60.0) * (max - min) + min, max},
		(unsigned char []){((h - 240) / 60.0) *(max - min) + min, min, max},
		(unsigned char []){max, min, ((360 - h) / 60.0) * (max - min) + min},
	};
	result = 0;
	result += rgb_values[index][0];
	result <<= 8;
	result += rgb_values[index][1];
	result <<= 8;
	result += rgb_values[index][2];
	return (result);
}
