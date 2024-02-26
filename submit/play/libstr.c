/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:58:36 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/26 18:58:36 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

ssize_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

ssize_t	yeeeah(void)
{
	return (write(1, "yeeeah", 6));
}
