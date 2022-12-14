/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:30:55 by yshimoda          #+#    #+#             */
/*   Updated: 2022/12/02 15:38:27 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	search_valid_path(t_data *data, t_map *map)
{
	t_bfs		*bfs;
	t_queue		*queue;
	size_t		len_col;

	bfs_init(data, &bfs);
	len_col = ft_strlen(map->line);
	while (bfs->bfs_queue)
	{
		queue = bfs->bfs_queue;
		if (bfs_can_move_up(bfs, map, len_col))
			bfs_write_one_add_que(bfs, data, queue->x, queue->y - 1);
		if (bfs_can_move_down(bfs, map, len_col))
			bfs_write_one_add_que(bfs, data, queue->x, queue->y + 1);
		if (bfs_can_move_right(bfs, map, len_col))
			bfs_write_one_add_que(bfs, data, queue->x + 1, queue->y);
		if (bfs_can_move_left(bfs, map, len_col))
			bfs_write_one_add_que(bfs, data, queue->x - 1, queue->y);
		lst_queue_dequeue(&bfs->bfs_queue);
	}
	if (bfs->bfs_num_e != 0)
		error_func_data_bfs_free("Error\nnot exist valid path", data, bfs);
	if (bfs->bfs_num_c != 0)
		error_func_data_bfs_free("Error\ncannot	collect c", data, bfs);
	bfs_free(bfs);
	return ;
}

void	check_valid_path(t_data *data, t_map *map)
{
	find_start(data, map);
	search_valid_path(data, map);
	return ;
}

void	check_surrounded_walls(t_data *data, t_map *map)
{
	size_t	i;
	size_t	len;
	t_map	*tmp;

	if (!map || !map->line)
		error_func_data_free("Error\nmap error", data);
	len = ft_strlen(map->line);
	tmp = map;
	while (tmp)
	{
		if (tmp->line[0] != '1' || tmp->line[len - 1] != '1')
			error_func_data_free("Error\nmap is not walled in", data);
		tmp = tmp->next;
	}
	tmp = lst_map_last(map);
	i = 0;
	while (i < len)
	{
		if (map->line[i] != '1' || tmp->line[i] != '1')
			error_func_data_free("Error\nmap is not walled in", data);
		i++;
	}
	return ;
}
