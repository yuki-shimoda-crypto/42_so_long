/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:49:50 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/30 00:09:36 by yshimoda         ###   ########.fr       */
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
	free(data->mlx_space_image);
	free(data->mlx_wall_image);
	free(data->mlx_collectible_image);
	free(data->mlx_exit_image);
	free(data->mlx_player_image);
	free(data->mlx_win_ptr);
	free(data->mlx_ptr);
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
