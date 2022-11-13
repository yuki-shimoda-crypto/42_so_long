/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:01:50 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/13 15:28:35 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bfs_init(t_data *data, t_bfs **bfs)
{
	size_t		len_col;
	size_t		len_row;

	*bfs = malloc(sizeof(t_bfs));
	if (!*bfs)
		error_func_data_free("malloc error", data);
	len_col = ft_strlen(data->map->line);
	len_row = lst_map_size(data->map);
	(*bfs)->bfs_num_c = data->num_c;
	(*bfs)->bfs_num_e = data->num_e;
	(*bfs)->bfs_map = ft_calloc(len_col * len_row, sizeof(int));
	if (!(*bfs)->bfs_map)
	{
		free(bfs);
		error_func_data_free("malloc error", data);
	}
	(*bfs)->bfs_queue = lst_queue_new(data->start_x, data->start_y);
	if (!(*bfs)->bfs_queue)
	{
		free((*bfs)->bfs_map);
		free(bfs);
		error_func_data_free("malloc error", data);
	}
	(*bfs)->bfs_map[len_col * (*bfs)->bfs_queue->y + (*bfs)->bfs_queue->x] = 1;
	return ;
}

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
		if (data->start_x != -1 && data->start_y != -1)
			break ;
		while (map->line[x])
		{
			if (map->line[x] == 'P')
			{
				data->start_x = x;
				data->start_y = y;
				break ;
			}
			x++;
		}
		map = map->next;
		y++;
	}
	return ;
}

t_data	*init_data(t_map *map)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->map = map;
	data->num_zero = 0;
	data->num_one = 0;
	data->num_c = 0;
	data->num_e = 0;
	data->num_p = 0;
	data->start_x = -1;
	data->start_y = -1;
	return (data);
}
