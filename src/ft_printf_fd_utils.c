/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:46:49 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/22 18:22:02 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_output(int fd, uintptr_t num, ssize_t *num_len)
{
	char	c;

	if (num >= 16)
	{
		ft_output(fd, num / 16, num_len);
		ft_output(fd, num % 16, num_len);
	}
	else
	{
		if (num % 16 < 10)
		{
			c = (char)num + '0';
			*num_len += write(fd, &c, 1);
		}
		else
		{
			c = (char)num + 'a' - 10;
			*num_len += write(fd, &c, 1);
		}
	}
}

ssize_t	ft_put_ptr_fd(int fd, uintptr_t num)
{
	ssize_t	num_len;

	num_len = write(fd, "0x", 2);
	if (!num)
		num_len += write(fd, "0", 1);
	else
		ft_output(fd, num, &num_len);
	return (num_len);
}

ssize_t	ft_put_str_fd(int fd, char *str)
{
	if (!str)
		return (write(fd, "(null)", 6));
	return (write(fd, str, ft_strlen(str)));
}

ssize_t	ft_put_char_fd(int fd, char c)
{
	return (write(fd, &c, 1));
}
