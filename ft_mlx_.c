/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:29:22 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/22 17:14:21 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_data *data, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, data->mlx_space_image, data->pixel_size * x, data->pixel_size * y);
	if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, data->mlx_wall_image, data->pixel_size * x, data->pixel_size * y);
	if (c == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, data->mlx_collectible_image, data->pixel_size * x, data->pixel_size * y);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, data->mlx_exit_image, data->pixel_size * x, data->pixel_size * y);
	if (c == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, data->mlx_player_image, data->pixel_size * x, data->pixel_size * y);
	return ;
}

int	ft_mlx_put_image(t_data *data)
{
	int		x;
	int		y;
	t_map	*map;

	y = 0;
	map = data->map;
	while (map)
	{
		x = 0;
		while (map->line[x])
		{
			put_image(data, map->line[x], x, y);
			x++;
		}
		map = map->next;
		y++;
	}
	return (0);
}

void	ft_mlx_init_image(t_data *data)
{
	ft_mlx_init_image_space(data);
	ft_mlx_init_image_wall(data);
	ft_mlx_init_image_collectible(data);
	ft_mlx_init_image_exit(data);
	ft_mlx_init_image_player(data);
	return ;
}

static void	put_xpm(t_data *data, const char *content, char *pixel_size)
{
	char	*xpm_name;

	xpm_name = ft_strjoin_four(XPM_DIR, content, pixel_size, ".xpm");
	if (!xpm_name)
		error_func_data_free("open error", data);
	data->fd = open(xpm_name, O_RDWR | O_CREAT, 0644);
	if (data->fd == -1)
	{
		free(xpm_name);
		error_func_data_free("open error", data);
	}
	if (!ft_strncmp(content, "space", ft_strlen("space")))
		write_xpm_space(data, pixel_size);
	if (!ft_strncmp(content, "wall", ft_strlen("wall")))
		write_xpm_wall(data, pixel_size);
	if (!ft_strncmp(content, "collectible", ft_strlen("collectible")))
		write_xpm_collectible(data, pixel_size);
	if (!ft_strncmp(content, "exit", ft_strlen("exit")))
		write_xpm_exit(data, pixel_size);
	if (!ft_strncmp(content, "player", ft_strlen("player")))
		write_xpm_player(data, pixel_size);
	close(data->fd);
	free(xpm_name);
	return ;
}

static void	ft_mlx_make_xpm(t_data *data)
{
	put_xpm(data, "space", data->pixel_size_str);
	put_xpm(data, "wall", data->pixel_size_str);
	put_xpm(data, "collectible", data->pixel_size_str);
	put_xpm(data, "exit", data->pixel_size_str);
	put_xpm(data, "player", data->pixel_size_str);
	return ;
}

static void	ft_mlx_init(t_data *d)
{
	d->map_height = lst_map_size(d->map);
	d->map_width = ft_strlen(d->map->line);
	d->pixel_size = SCREEN_HEIGHT / d->map_height;
	if (d->pixel_size > SCREEN_WIDTH / d->map_width)
		d->pixel_size = SCREEN_WIDTH / d->map_width;
	if (d->pixel_size <= 0)
		d->pixel_size = 1;
	d->mlx_ptr = mlx_init();
	d->mlx_win_ptr = mlx_new_window(d->mlx_ptr, d->pixel_size * d->map_width,
			d->pixel_size * d->map_height, "so_long");
	if (!d->mlx_ptr || !d->mlx_win_ptr)
		error_func_data_free("malloc error", d);
	d->pixel_size_str = ft_ltoa(d->pixel_size);
	if (!d->pixel_size_str)
		error_func_data_free("malloc error", d);
	return ;
}

// static void	move_map(int keycode, t_data *data)
// {
// 	if (keycode == )
// 		/* code */
// }


void	ft_mlx(t_data *data)
{
	ft_mlx_init(data);
	ft_mlx_make_xpm(data);
	ft_mlx_init_image(data);
	mlx_loop_hook(data->mlx_ptr, ft_mlx_put_image, data);
	// mlx_hook(data->mlx_win_ptr, 2, 1L << 0, move_map, data);
	// mlx_hook(data->mlx_win_ptr, 17, 1L << 2, destroy_mlx, data);
	// ft_mlx_put_image(data, data->map, data);
	mlx_loop(data->mlx_ptr);
	return ;
}
