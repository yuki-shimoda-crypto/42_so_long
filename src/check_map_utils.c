/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:01:50 by yshimoda          #+#    #+#             */
/*   Updated: 2022/12/02 19:13:26 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*move_map_row(t_map *map, long long y)
{
	long long	i;

	i = 0;
	while (i < y)
	{
		if (!map)
			return (NULL);
		map = map->next;
		i++;
	}
	return (map);
}

void	find_start(t_data *data, t_map *map)
{
	long long	x;
	long long	y;

	y = 0;
	while (map)
	{
		x = 0;
		while (map->line[x])
		{
			if (map->line[x] == 'P')
			{
				data->start_x = x;
				data->start_y = y;
				return ;
				// break ;
			}
			x++;
		}
		map = map->next;
		y++;
	}
	return ;
}

void	init_data(t_data **data, t_map *map)
{
	*data = malloc(sizeof(t_data));
	if (!*data)
		return ;
	ft_memset(data, 0, sizeof(t_data));
	(*data)->map = map;
	(*data)->map_height = 0;
	(*data)->map_width = 0;
	(*data)->num_zero = 0;
	(*data)->num_one = 0;
	(*data)->num_c = 0;
	(*data)->num_e = 0;
	(*data)->num_p = 0;
	(*data)->start_x = -1;
	(*data)->start_y = -1;
	(*data)->mlx_ptr = NULL;
	(*data)->mlx_win_ptr = NULL;
	(*data)->mlx_space_image = NULL;
	(*data)->mlx_wall_image = NULL;
	(*data)->mlx_collectible_image = NULL;
	(*data)->mlx_exit_image = NULL;
	(*data)->mlx_player_image = NULL;
	(*data)->pixel_size_str = NULL;
	(*data)->pixel_size = 0;
	(*data)->xpm_name = NULL;
	(*data)->step = 0;
	(*data)->fd = 0;
}
