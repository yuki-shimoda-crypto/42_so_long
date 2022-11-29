/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 04:20:34 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/30 04:21:07 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mlx_destroy(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->mlx_space_image);
	mlx_destroy_image(data->mlx_ptr, data->mlx_wall_image);
	mlx_destroy_image(data->mlx_ptr, data->mlx_collectible_image);
	mlx_destroy_image(data->mlx_ptr, data->mlx_exit_image);
	mlx_destroy_image(data->mlx_ptr, data->mlx_player_image);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	lst_map_clear(&(data->map));
	free(data->mlx_ptr);
	free(data->pixel_size_str);
	free(data);
	printf("%s\n", "finish");
	exit(EXIT_SUCCESS);
	return (0);
}

static void	move_player(t_data *data, int x, int y)
{
	t_map	*map;

	map = move_map_row(data->map, data->start_y + y);
	if (map->line[data->start_x + x] != '1')
	{
		if (map->line[data->start_x + x] != 'E')
		{
			if (map->line[data->start_x + x] == 'C')
				data->num_c = data->num_c - 1;
			map->line[data->start_x + x] = 'P';
			map = move_map_row(data->map, data->start_y);
			map->line[data->start_x] = '0';
			data->step++;
			printf("step is %lld\n", data->step);
			data->start_x += x;
			data->start_y += y;
		}
		else if (map->line[data->start_x + x] == 'E' && data->num_c == 0)
		{
			data->step++;
			printf("step is %lld\n", data->step);
			ft_mlx_destroy(data);
		}
	}
}

int	ft_mlx_move_map(int key_num, t_data *data)
{
	if (key_num == KEY_ESC)
		ft_mlx_destroy(data);
	else if (key_num == 'a' || key_num == KEY_LEFT)
		move_player(data, -1, 0);
	else if (key_num == 'w' || key_num == KEY_UP)
		move_player(data, 0, -1);
	else if (key_num == 'd' || key_num == KEY_RIGHT)
		move_player(data, 1, 0);
	else if (key_num == 's' || key_num == KEY_DOWN)
		move_player(data, 0, 1);
	return (0);
}

static void	put_image(t_data *data, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, data->mlx_space_image, data->pixel_size * x, data->pixel_size * y);
	else if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, data->mlx_wall_image, data->pixel_size * x, data->pixel_size * y);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, data->mlx_collectible_image, data->pixel_size * x, data->pixel_size * y);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, data->mlx_exit_image, data->pixel_size * x, data->pixel_size * y);
	else if (c == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, data->mlx_player_image, data->pixel_size * x, data->pixel_size * y);
	return ;
}

int	ft_mlx_put_image_to_window(t_data *data)
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