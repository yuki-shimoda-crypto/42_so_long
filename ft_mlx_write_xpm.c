/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_write_xpm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:46:08 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/30 03:47:52 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_xpm_player_to_file(t_data *data, char *pixel_size, long long i, long long j)
{
	data->xpm_name = ft_strjoin_four(XPM_DIR, "player", pixel_size, ".xpm");
	if (!data->xpm_name)
		error_func_data_mlx_free("malloc error", data, MLX_WINDOW_FREE);
	data->fd = open(data->xpm_name, O_RDWR | O_CREAT, 0644);
	if (data->fd == -1)
		error_func_data_mlx_free("open error", data, MLX_WINDOW_FREE);
	ft_printf_fd(data->fd, "static char *str[] = {\n\"%s ", pixel_size);
	ft_printf_fd(data->fd, "%s 1 1\",\n\"0 c ", pixel_size);
	ft_printf_fd(data->fd, "#FF0000\",\n/* pixels */\n");
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
	close(data->fd);
	free(data->xpm_name);
	return ;
}


void	write_xpm_exit_to_file(t_data *data, char *pixel_size, long long i, long long j)
{
	data->xpm_name = ft_strjoin_four(XPM_DIR, "exit", pixel_size, ".xpm");
	if (!data->xpm_name)
		error_func_data_mlx_free("malloc error", data, MLX_WINDOW_FREE);
	data->fd = open(data->xpm_name, O_RDWR | O_CREAT, 0644);
	if (data->fd == -1)
		error_func_data_mlx_free("open error", data, MLX_WINDOW_FREE);
	ft_printf_fd(data->fd, "static char *str[] = {\n\"%s ", pixel_size);
	ft_printf_fd(data->fd, "%s 1 1\",\n\"0 c ", pixel_size);
	ft_printf_fd(data->fd, "#00FF00\",\n/* pixels */\n");
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
	close(data->fd);
	free(data->xpm_name);
	return ;
}

void	write_xpm_collectible_to_file(t_data *data, char *pixel_size, long long i, long long j)
{
	data->xpm_name = ft_strjoin_four(XPM_DIR, "collectible", pixel_size, ".xpm");
	if (!data->xpm_name)
		error_func_data_mlx_free("malloc error", data, MLX_WINDOW_FREE);
	data->fd = open(data->xpm_name, O_RDWR | O_CREAT, 0644);
	if (data->fd == -1)
		error_func_data_mlx_free("open error", data, MLX_WINDOW_FREE);
	ft_printf_fd(data->fd, "static char *str[] = {\n\"%s ", pixel_size);
	ft_printf_fd(data->fd, "%s 1 1\",\n\"0 c ", pixel_size);
	ft_printf_fd(data->fd, "#0000FF\",\n/* pixels */\n");
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
	close(data->fd);
	free(data->xpm_name);
	return ;
}

void	write_xpm_wall_to_file(t_data *data, char *pixel_size, long long i, long long j)
{
	data->xpm_name = ft_strjoin_four(XPM_DIR, "wall", pixel_size, ".xpm");
	if (!data->xpm_name)
		error_func_data_mlx_free("malloc error", data, MLX_WINDOW_FREE);
	data->fd = open(data->xpm_name, O_RDWR | O_CREAT, 0644);
	if (data->fd == -1)
		error_func_data_mlx_free("open error", data, MLX_WINDOW_FREE);
	ft_printf_fd(data->fd, "static char *str[] = {\n\"%s ", pixel_size);
	ft_printf_fd(data->fd, "%s 1 1\",\n\"0 c ", pixel_size);
	ft_printf_fd(data->fd, "#000000\",\n/* pixels */\n");
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
	close(data->fd);
	free(data->xpm_name);
	return ;
}

void	write_xpm_space_to_file(t_data *data, char *pixel_size,
		long long i, long long j)
{
	data->xpm_name = ft_strjoin_four(XPM_DIR, "space", pixel_size, ".xpm");
	if (!data->xpm_name)
		error_func_data_mlx_free("malloc error", data, MLX_WINDOW_FREE);
	data->fd = open(data->xpm_name, O_RDWR | O_CREAT, 0644);
	if (data->fd == -1)
		error_func_data_mlx_free("open error", data, MLX_WINDOW_FREE);
	ft_printf_fd(data->fd, "static char *str[] = {\n\"%s ", pixel_size);
	ft_printf_fd(data->fd, "%s 1 1\",\n\"0 c ", pixel_size);
	ft_printf_fd(data->fd, "#ffffff\",\n/* pixels */\n");
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
	close(data->fd);
	free(data->xpm_name);
	return ;
}
