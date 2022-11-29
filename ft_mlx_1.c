/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:29:22 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/30 04:23:52 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_mlx_xpm_file_to_image(t_data *data)
{
	ft_mlx_xpm_file_to_image_space(data);
	ft_mlx_xpm_file_to_image_wall(data);
	ft_mlx_xpm_file_to_image_collectible(data);
	ft_mlx_xpm_file_to_image_exit(data);
	ft_mlx_xpm_file_to_image_player(data);
	return ;
}

static void	ft_mlx_make_xpm(t_data *data)
{
	long long	i;
	long long	j;

	i = 0;
	j = 0;
	write_xpm_space_to_file(data, data->pixel_size_str, i, j);
	write_xpm_wall_to_file(data, data->pixel_size_str, i, j);
	write_xpm_collectible_to_file(data, data->pixel_size_str, i, j);
	write_xpm_exit_to_file(data, data->pixel_size_str, i, j);
	write_xpm_player_to_file(data, data->pixel_size_str, i, j);
	return ;
}

static void	ft_mlx_init_new_window(t_data *d)
{
	d->map_height = lst_map_size(d->map);
	d->map_width = ft_strlen(d->map->line);
	d->pixel_size = SCREEN_HEIGHT / d->map_height;
	if (d->pixel_size > SCREEN_WIDTH / d->map_width)
		d->pixel_size = SCREEN_WIDTH / d->map_width;
	if (d->pixel_size <= 0)
		d->pixel_size = 1;
	d->mlx_ptr = mlx_init();
	if (!d->mlx_ptr)
		error_func_data_mlx_free("malloc error", d, MLX_NO_FREE);
	d->mlx_win_ptr = mlx_new_window(d->mlx_ptr, d->pixel_size * d->map_width,
			d->pixel_size * d->map_height, "so_long");
	if (!d->mlx_win_ptr)
		error_func_data_mlx_free("malloc error", d, MLX_INIT_FREE);
	d->pixel_size_str = ft_ltoa(d->pixel_size);
	if (!d->pixel_size_str)
		error_func_data_mlx_free("malloc error", d, MLX_WINDOW_FREE);
	return ;
}

void	ft_mlx(t_data *data)
{
	ft_mlx_init_new_window(data);
	ft_mlx_make_xpm(data);
	ft_mlx_xpm_file_to_image(data);
	mlx_loop_hook(data->mlx_ptr, ft_mlx_put_image_to_window, data);
	mlx_hook(data->mlx_win_ptr, 2, 1L << 0, ft_mlx_move_map, data);
	mlx_hook(data->mlx_win_ptr, 17, 1L << 2, ft_mlx_destroy, data);
	mlx_loop(data->mlx_ptr);
	return ;
}
