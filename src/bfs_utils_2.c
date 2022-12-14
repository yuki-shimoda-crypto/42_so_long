/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:10:03 by yshimoda          #+#    #+#             */
/*   Updated: 2022/12/02 15:33:18 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bfs_free(t_bfs *bfs)
{
	free(bfs->bfs_map);
	lst_queue_clear(&bfs->bfs_queue);
	free(bfs);
	return ;
}

void	bfs_write_one_add_que(t_bfs *bfs, t_data *data,
		long long x, long long y)
{
	t_queue	*queue_next;
	t_map	*map_tmp;

	bfs->bfs_map[ft_strlen(data->map->line) * y + x] = 1;
	map_tmp = move_map_row(data->map, y);
	if (map_tmp->line[x] == 'E')
		bfs->bfs_num_e -= 1;
	else
	{
		if (map_tmp->line[x] == 'C')
			bfs->bfs_num_c -= 1;
		queue_next = lst_queue_new(x, y);
		if (!queue_next)
			error_func_data_bfs_free("Error\nmalloc error", data, bfs);
		lst_queue_enqueue(&bfs->bfs_queue, queue_next);
	}
	return ;
}
