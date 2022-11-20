/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_write_xpm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:46:08 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/20 03:22:26 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void write_xpm_player(t_data *data, char *pixel_size)
{
	long long	i;
	long long	j;

	ft_putstr_fd("/* XPM */\nstatic char *str[] = {\n", data->fd);
	ft_putstr_fd("/*columsn rows colors chars-per-pixel */\n\"", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" ", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" 1 1\",\n\"0 c #333333\",\n/* pixels */\n", data->fd);
	i = 0;
	while (i < data->pixel_size)
	{
		write(data->fd, "\"", 1);
		j = 0;
		while (j < data->pixel_size)
		{
			write(data->fd, "0", 1);
			j++;
		}
		write(data->fd, "\",\n", 3);
		i++;
	}
	write(data->fd, "};\n", 3);
	return ;
}

void write_xpm_exit(t_data *data, char *pixel_size)
{
	long long	i;
	long long	j;

	ft_putstr_fd("/* XPM */\nstatic char *str[] = {\n", data->fd);
	ft_putstr_fd("/*columsn rows colors chars-per-pixel */\n\"", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" ", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" 1 1\",\n\"0 c #999999\",\n/* pixels */\n", data->fd);
	i = 0;
	while (i < data->pixel_size)
	{
		write(data->fd, "\"", 1);
		j = 0;
		while (j < data->pixel_size)
		{
			write(data->fd, "0", 1);
			j++;
		}
		write(data->fd, "\",\n", 3);
		i++;
	}
	write(data->fd, "};\n", 3);
	return ;
}

void write_xpm_collectible(t_data *data, char *pixel_size)
{
	long long	i;
	long long	j;

	ft_putstr_fd("/* XPM */\nstatic char *str[] = {\n", data->fd);
	ft_putstr_fd("/*columsn rows colors chars-per-pixel */\n\"", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" ", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" 1 1\",\n\"0 c #777777\",\n/* pixels */\n", data->fd);
	i = 0;
	while (i < data->pixel_size)
	{
		write(data->fd, "\"", 1);
		j = 0;
		while (j < data->pixel_size)
		{
			write(data->fd, "0", 1);
			j++;
		}
		write(data->fd, "\",\n", 3);
		i++;
	}
	write(data->fd, "};\n", 3);
	return ;
}

void write_xpm_wall(t_data *data, char *pixel_size)
{
	long long	i;
	long long	j;

	ft_putstr_fd("/* XPM */\nstatic char *str[] = {\n", data->fd);
	ft_putstr_fd("/*columsn rows colors chars-per-pixel */\n\"", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" ", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" 1 1\",\n\"0 c #000000\",\n/* pixels */\n", data->fd);
	i = 0;
	while (i < data->pixel_size)
	{
		write(data->fd, "\"", 1);
		j = 0;
		while (j < data->pixel_size)
		{
			write(data->fd, "0", 1);
			j++;
		}
		write(data->fd, "\",\n", 3);
		i++;
	}
	write(data->fd, "};\n", 3);
	return ;
}

void write_xpm_space(t_data *data, char *pixel_size)
{
	long long	i;
	long long	j;

	ft_putstr_fd("/* XPM */\nstatic char *str[] = {\n", data->fd);
	ft_putstr_fd("/*columsn rows colors chars-per-pixel */\n\"", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" ", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" 1 1\",\n\"0 c #ffffff\",\n/* pixels */\n", data->fd);
	i = 0;
	while (i < data->pixel_size)
	{
		write(data->fd, "\"", 1);
		j = 0;
		while (j < data->pixel_size)
		{
			write(data->fd, "0", 1);
			j++;
		}
		write(data->fd, "\",\n", 3);
		i++;
	}
	write(data->fd, "};\n", 3);
	return ;
}
