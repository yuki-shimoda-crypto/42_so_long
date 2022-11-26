/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_write_xpm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:46:08 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/23 18:08:00 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_xpm_player(t_data *data, char *pixel_size)
{
	long long	i;
	long long	j;

	ft_putstr_fd("/* XPM */\nstatic char *str[] = {\n", data->fd);
	ft_putstr_fd("/*columsn rows colors chars-per-pixel */\n\"", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" ", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" 1 1\",\n\"0 c #FF0000\",\n/* pixels */\n", data->fd);
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

void	write_xpm_exit(t_data *data, char *pixel_size)
{
	long long	i;
	long long	j;

	ft_putstr_fd("/* XPM */\nstatic char *str[] = {\n", data->fd);
	ft_putstr_fd("/*columsn rows colors chars-per-pixel */\n\"", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" ", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" 1 1\",\n\"0 c #00FF00\",\n/* pixels */\n", data->fd);
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

void	write_xpm_collectible(t_data *data, char *pixel_size)
{
	long long	i;
	long long	j;

	ft_putstr_fd("/* XPM */\nstatic char *str[] = {\n", data->fd);
	ft_putstr_fd("/*columsn rows colors chars-per-pixel */\n\"", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" ", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" 1 1\",\n\"0 c #0000FF\",\n/* pixels */\n", data->fd);
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

void	write_xpm_wall(t_data *data, char *pixel_size)
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

void	write_xpm_space(t_data *data, char *pixel_size)
{
	long long	i;
	long long	j;

	// ft_putstr_fd("/* XPM */\nstatic char *str[] = {\n", data->fd);
	// ft_putstr_fd("/*columsn rows colors chars-per-pixel */\n\"", data->fd);
	// ft_putstr_fd(pixel_size, data->fd);
	// ft_putstr_fd(" ", data->fd);
	// ft_putstr_fd(pixel_size, data->fd);
	// ft_putstr_fd(" 1 1\",\n\"0 c #ffffff\",\n/* pixels */\n", data->fd);
	// ft_printf_fd(data->fd, "/* XPM */\nstatic char *str[] = {\n/*columsn rows colors chars-per-pixel */\n\"%s %s 1 1\",\n\"0 c #ffffff\",\n/* pixels */\n", pixel_size, pixel_size);
	ft_printf_fd(data->fd, "static char *str[] = {\n\"%s ", pixel_size);
	ft_printf_fd(data->fd, "%s 1 1\",\n\"0 c ", pixel_size);
	ft_printf_fd(data->fd, "#ffffff\",\n/* pixels */\n");
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
