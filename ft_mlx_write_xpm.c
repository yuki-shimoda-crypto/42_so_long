/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_write_xpm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:46:08 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/30 04:43:30 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_xpm_player_to_file(t_data *d, char *pixel_size, long long i,
		long long j)
{
	d->xpm_name = ft_strjoin_four(XPM_DIR, "player", pixel_size, ".xpm");
	if (!d->xpm_name)
		error_func_data_mlx_free("malloc error", d, MLX_WINDOW_FREE);
	d->fd = open(d->xpm_name, O_RDWR | O_CREAT, 0644);
	if (d->fd == -1)
		error_func_data_mlx_free("open error", d, MLX_WINDOW_FREE);
	ft_printf_fd(d->fd, "static char *str[] = {\n\"%s ", pixel_size);
	ft_printf_fd(d->fd, "%s 1 1\",\n\"0 c ", pixel_size);
	ft_printf_fd(d->fd, "#FF0000\",\n/* pixels */\n");
	while (i < d->pixel_size)
	{
		write(d->fd, "\"", 1);
		j = 0;
		while (j < d->pixel_size)
		{
			write(d->fd, "0", 1);
			j++;
		}
		write(d->fd, "\",\n", 3);
		i++;
	}
	write(d->fd, "};\n", 3);
	close(d->fd);
	free(d->xpm_name);
	return ;
}

void	write_xpm_exit_to_file(t_data *d, char *pixel_size, long long i,
		long long j)
{
	d->xpm_name = ft_strjoin_four(XPM_DIR, "exit", pixel_size, ".xpm");
	if (!d->xpm_name)
		error_func_data_mlx_free("malloc error", d, MLX_WINDOW_FREE);
	d->fd = open(d->xpm_name, O_RDWR | O_CREAT, 0644);
	if (d->fd == -1)
		error_func_data_mlx_free("open error", d, MLX_WINDOW_FREE);
	ft_printf_fd(d->fd, "static char *str[] = {\n\"%s ", pixel_size);
	ft_printf_fd(d->fd, "%s 1 1\",\n\"0 c ", pixel_size);
	ft_printf_fd(d->fd, "#00FF00\",\n/* pixels */\n");
	while (i < d->pixel_size)
	{
		write(d->fd, "\"", 1);
		j = 0;
		while (j < d->pixel_size)
		{
			write(d->fd, "0", 1);
			j++;
		}
		write(d->fd, "\",\n", 3);
		i++;
	}
	write(d->fd, "};\n", 3);
	close(d->fd);
	free(d->xpm_name);
	return ;
}

void	write_xpm_collectible_to_file(t_data *d, char *pixel_size, long long i,
		long long j)
{
	d->xpm_name = ft_strjoin_four(XPM_DIR, "collectible", pixel_size, ".xpm");
	if (!d->xpm_name)
		error_func_data_mlx_free("malloc error", d, MLX_WINDOW_FREE);
	d->fd = open(d->xpm_name, O_RDWR | O_CREAT, 0644);
	if (d->fd == -1)
		error_func_data_mlx_free("open error", d, MLX_WINDOW_FREE);
	ft_printf_fd(d->fd, "static char *str[] = {\n\"%s ", pixel_size);
	ft_printf_fd(d->fd, "%s 1 1\",\n\"0 c ", pixel_size);
	ft_printf_fd(d->fd, "#0000FF\",\n/* pixels */\n");
	while (i < d->pixel_size)
	{
		write(d->fd, "\"", 1);
		j = 0;
		while (j < d->pixel_size)
		{
			write(d->fd, "0", 1);
			j++;
		}
		write(d->fd, "\",\n", 3);
		i++;
	}
	write(d->fd, "};\n", 3);
	close(d->fd);
	free(d->xpm_name);
	return ;
}

void	write_xpm_wall_to_file(t_data *d, char *pixel_size, long long i,
		long long j)
{
	d->xpm_name = ft_strjoin_four(XPM_DIR, "wall", pixel_size, ".xpm");
	if (!d->xpm_name)
		error_func_data_mlx_free("malloc error", d, MLX_WINDOW_FREE);
	d->fd = open(d->xpm_name, O_RDWR | O_CREAT, 0644);
	if (d->fd == -1)
		error_func_data_mlx_free("open error", d, MLX_WINDOW_FREE);
	ft_printf_fd(d->fd, "static char *str[] = {\n\"%s ", pixel_size);
	ft_printf_fd(d->fd, "%s 1 1\",\n\"0 c ", pixel_size);
	ft_printf_fd(d->fd, "#000000\",\n/* pixels */\n");
	while (i < d->pixel_size)
	{
		write(d->fd, "\"", 1);
		j = 0;
		while (j < d->pixel_size)
		{
			write(d->fd, "0", 1);
			j++;
		}
		write(d->fd, "\",\n", 3);
		i++;
	}
	write(d->fd, "};\n", 3);
	close(d->fd);
	free(d->xpm_name);
	return ;
}

void	write_xpm_space_to_file(t_data *d, char *pixel_size, long long i,
		long long j)
{
	d->xpm_name = ft_strjoin_four(XPM_DIR, "space", pixel_size, ".xpm");
	if (!d->xpm_name)
		error_func_data_mlx_free("malloc error", d, MLX_WINDOW_FREE);
	d->fd = open(d->xpm_name, O_RDWR | O_CREAT, 0644);
	if (d->fd == -1)
		error_func_data_mlx_free("open error", d, MLX_WINDOW_FREE);
	ft_printf_fd(d->fd, "static char *str[] = {\n\"%s ", pixel_size);
	ft_printf_fd(d->fd, "%s 1 1\",\n\"0 c ", pixel_size);
	ft_printf_fd(d->fd, "#ffffff\",\n/* pixels */\n");
	while (i < d->pixel_size)
	{
		write(d->fd, "\"", 1);
		j = 0;
		while (j < d->pixel_size)
		{
			write(d->fd, "0", 1);
			j++;
		}
		write(d->fd, "\",\n", 3);
		i++;
	}
	write(d->fd, "};\n", 3);
	close(d->fd);
	free(d->xpm_name);
	return ;
}
