/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:03:44 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/30 02:05:47 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	bfs_can_move_left(t_bfs *bfs, t_map *map, size_t len_col)
{
	int		*bfs_map;
	t_queue	*queue;

	bfs_map = bfs->bfs_map;
	queue = bfs->bfs_queue;
	map = move_map_row(map, queue->y);
	if (bfs_map[len_col * (queue->y) + queue->x - 1] == 1)
		return (false);
	if (map->line[queue->x - 1] == '1')
		return (false);
	return (true);
}

bool	bfs_can_move_right(t_bfs *bfs, t_map *map, size_t len_col)
{
	int		*bfs_map;
	t_queue	*queue;

	bfs_map = bfs->bfs_map;
	queue = bfs->bfs_queue;
	map = move_map_row(map, queue->y);
	if (bfs_map[len_col * (queue->y) + queue->x + 1] == 1)
		return (false);
	if (map->line[queue->x + 1] == '1')
		return (false);
	return (true);
}

bool	bfs_can_move_down(t_bfs *bfs, t_map *map, size_t len_col)
{
	int		*bfs_map;
	t_queue	*queue;

	bfs_map = bfs->bfs_map;
	queue = bfs->bfs_queue;
	map = move_map_row(map, queue->y);
	map = map->next;
	if (bfs_map[len_col * (queue->y + 1) + queue->x] == 1)
		return (false);
	if (map->line[queue->x] == '1')
		return (false);
	return (true);
}

bool	bfs_can_move_up(t_bfs *bfs, t_map *map, size_t len_col)
{
	int		*bfs_map;
	t_queue	*queue;

	bfs_map = bfs->bfs_map;
	queue = bfs->bfs_queue;
	map = move_map_row(map, queue->y);
	map = map->pre;
	if (bfs_map[len_col * (queue->y - 1) + queue->x] == 1)
		return (false);
	if (map->line[queue->x] == '1')
		return (false);
	return (true);
}

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
	(*bfs)->bfs_map = NULL;
	(*bfs)->bfs_queue = NULL;
	(*bfs)->bfs_map = ft_calloc(len_col * len_row, sizeof(int));
	(*bfs)->bfs_queue = lst_queue_new(data->start_x, data->start_y);
	if (!(*bfs)->bfs_map || !(*bfs)->bfs_queue)
	{
		free((*bfs)->bfs_queue);
		free((*bfs)->bfs_map);
		free(bfs);
		error_func_data_free("malloc error", data);
	}
	(*bfs)->bfs_map[len_col * (*bfs)->bfs_queue->y + (*bfs)->bfs_queue->x] = 1;
	return ;
}
