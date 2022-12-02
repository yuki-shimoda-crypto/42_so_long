/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:49:50 by yshimoda          #+#    #+#             */
/*   Updated: 2022/12/02 10:59:11 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_func(const char *str)
{
	ft_printf_fd(STDERR_FILENO, "%s\n", str);
	exit(EXIT_FAILURE);
	return ;
}

void	error_func_map_free(const char *str, t_map *map)
{
	lst_map_clear(&map);
	ft_printf_fd(STDERR_FILENO, "%s\n", str);
	exit(EXIT_FAILURE);
	return ;
}

void	error_func_data_free(const char *str, t_data *data)
{
	lst_map_clear(&(data->map));
	free(data->pixel_size_str);
	free(data);
	ft_printf_fd(STDERR_FILENO, "%s\n", str);
	exit(EXIT_FAILURE);
	return ;
}

void	error_func_data_bfs_free(const char *str, t_data *data, t_bfs *bfs)
{
	bfs_free(bfs);
	error_func_data_free(str, data);
	return ;
}

void	error_func_data_mlx_free(const char *str, t_data *data, int flag)
{
	if (flag >= MLX_IMAGE_FREE)
	{
		mlx_destroy_image(data->mlx_ptr, data->mlx_space_image);
		mlx_destroy_image(data->mlx_ptr, data->mlx_wall_image);
		mlx_destroy_image(data->mlx_ptr, data->mlx_collectible_image);
		mlx_destroy_image(data->mlx_ptr, data->mlx_exit_image);
		mlx_destroy_image(data->mlx_ptr, data->mlx_player_image);
	}
	if (flag >= MLX_WINDOW_FREE)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win_ptr);
	lst_map_clear(&(data->map));
	free(data->pixel_size_str);
	free(data);
	ft_printf_fd(STDERR_FILENO, "%s\n", str);
	exit(EXIT_FAILURE);
	return ;
}

// void	error_func_data_mlx_free(const char *str, t_data *data, int flag)
// {
// 	if (flag >= MLX_IMAGE_FREE)
// 	{
// 		mlx_destroy_image(data->mlx_ptr, data->mlx_space_image);
// 		mlx_destroy_image(data->mlx_ptr, data->mlx_wall_image);
// 		mlx_destroy_image(data->mlx_ptr, data->mlx_collectible_image);
// 		mlx_destroy_image(data->mlx_ptr, data->mlx_exit_image);
// 		mlx_destroy_image(data->mlx_ptr, data->mlx_player_image);
// 	}
// 	if (flag >= MLX_WINDOW_FREE)
// 		mlx_destroy_window(data->mlx_ptr, data->mlx_win_ptr);
// 	if (flag >= MLX_INIT_FREE)
// 	{
// 		mlx_destroy_display(data->mlx_ptr);
// 		free(data->mlx_ptr);
// 	}
// 	lst_map_clear(&(data->map));
// 	free(data->pixel_size_str);
// 	free(data);
// 	ft_printf_fd(STDERR_FILENO, "%s\n", str);
// 	exit(EXIT_FAILURE);
// 	return ;
// }
