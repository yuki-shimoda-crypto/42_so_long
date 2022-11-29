/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_xpm_file_to_image.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:53:09 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/30 04:28:50 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_xpm_file_to_image_player(t_data *data)
{
	char	*xpm_name;

	xpm_name = ft_strjoin_four(XPM_DIR, "player", data->pixel_size_str, ".xpm");
	if (!xpm_name)
		error_func_data_mlx_free("open error", data, MLX_WINDOW_FREE);
	data->mlx_player_image = mlx_xpm_file_to_image(data->mlx_ptr, xpm_name, &data->pixel_size, &data->pixel_size);
	free(xpm_name);
	if (!data->mlx_player_image)
	{
		mlx_destroy_image(data->mlx_ptr, data->mlx_space_image);
		mlx_destroy_image(data->mlx_ptr, data->mlx_wall_image);
		mlx_destroy_image(data->mlx_ptr, data->mlx_collectible_image);
		mlx_destroy_image(data->mlx_ptr, data->mlx_exit_image);
		error_func_data_mlx_free("mlx error", data, MLX_WINDOW_FREE);
	}
	return ;
}

void	ft_mlx_xpm_file_to_image_exit(t_data *data)
{
	char	*xpm_name;

	xpm_name = ft_strjoin_four(XPM_DIR, "exit", data->pixel_size_str, ".xpm");
	if (!xpm_name)
		error_func_data_mlx_free("open error", data, MLX_WINDOW_FREE);
	data->mlx_exit_image = mlx_xpm_file_to_image(data->mlx_ptr, xpm_name, &data->pixel_size, &data->pixel_size);
	free(xpm_name);
	if (!data->mlx_exit_image)
	{
		mlx_destroy_image(data->mlx_ptr, data->mlx_space_image);
		mlx_destroy_image(data->mlx_ptr, data->mlx_wall_image);
		mlx_destroy_image(data->mlx_ptr, data->mlx_collectible_image);
		error_func_data_mlx_free("mlx error", data, MLX_WINDOW_FREE);
	}
	return ;
}

void	ft_mlx_xpm_file_to_image_collectible(t_data *data)
{
	char	*xpm_name;

	xpm_name = ft_strjoin_four(XPM_DIR, "collectible", data->pixel_size_str, ".xpm");
	if (!xpm_name)
		error_func_data_mlx_free("open error", data, MLX_WINDOW_FREE);
	data->mlx_collectible_image = mlx_xpm_file_to_image(data->mlx_ptr, xpm_name, &data->pixel_size, &data->pixel_size);
	free(xpm_name);
	if (!data->mlx_collectible_image)
	{
		mlx_destroy_image(data->mlx_ptr, data->mlx_space_image);
		mlx_destroy_image(data->mlx_ptr, data->mlx_wall_image);
		error_func_data_mlx_free("mlx error", data, MLX_WINDOW_FREE);
	}
	return ;
}

void	ft_mlx_xpm_file_to_image_wall(t_data *data)
{
	char	*xpm_name;

	xpm_name = ft_strjoin_four(XPM_DIR, "wall", data->pixel_size_str, ".xpm");
	if (!xpm_name)
		error_func_data_mlx_free("open error", data, MLX_WINDOW_FREE);
	data->mlx_wall_image = mlx_xpm_file_to_image(data->mlx_ptr, xpm_name, &data->pixel_size, &data->pixel_size);
	free(xpm_name);
	if (!data->mlx_wall_image)
	{
		mlx_destroy_image(data->mlx_ptr, data->mlx_space_image);
		error_func_data_mlx_free("mlx error", data, MLX_WINDOW_FREE);
	}
	return ;
}

void	ft_mlx_xpm_file_to_image_space(t_data *data)
{
	char	*xpm_name;

	xpm_name = ft_strjoin_four(XPM_DIR, "space", data->pixel_size_str, ".xpm");
	if (!xpm_name)
		error_func_data_mlx_free("open error", data, MLX_WINDOW_FREE);
	data->mlx_space_image = mlx_xpm_file_to_image(data->mlx_ptr, xpm_name, &data->pixel_size, &data->pixel_size);
	free(xpm_name);
	if (!data->mlx_space_image)
		error_func_data_mlx_free("mlx error", data, MLX_WINDOW_FREE);
	return ;
}
