/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 01:04:48 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/12 01:19:01 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
