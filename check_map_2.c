/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:30:55 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/13 15:28:44 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	search_valid_path(t_data *data, t_map *map)
{
	size_t		len_column;
	size_t		len_row;
	t_bfs		*bfs;

	len_column = ft_strlen(map->line);
	len_row = lst_map_size(map);
	bfs_init(data, &bfs);
	// while (bfs_queue)
	// {
	// }

	size_t		i = 0;
	size_t		j = 0;
	while (i < len_row)
	{
		j = 0;
		while (j < len_column)
		{
			printf("%d", bfs->bfs_map[len_column * i + j]);
			j++;
		}
		printf("\n");
		i++;
	}
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
		error_func_data_free("map error", data);
	len = ft_strlen(map->line);
	tmp = map;
	while (tmp)
	{
		if (tmp->line[0] != '1' || tmp->line[len - 1] != '1')
			error_func_data_free("Error, map is not walled in", data);
		tmp = tmp->next;
	}
	tmp = lst_map_last(map);
	i = 0;
	while (i < len)
	{
		if (map->line[i] != '1' || tmp->line[i] != '1')
			error_func_data_free("Error, map is not walled in", data);
		i++;
	}
	return ;
}
