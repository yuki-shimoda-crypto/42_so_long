/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:53:09 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/10 19:08:16 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_component(t_map *map, size_t map_size)
{
	size_t		i;

	while (map)
	{
		i = 0;
		while (map->line[i])
		{
			if (map->line[i] == '0')
				
			i++;
		}
		map->next;
	}
	return ;
}

static void	check_file_name(t_map *map, char const *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		error_func_map_free("map name error", map);
	if (filename[len - 1] != 'r')
		error_func_map_free("map name error", map);
	if (filename[len - 2] != 'e')
		error_func_map_free("map name error", map);
	if (filename[len - 3] != 'b')
		error_func_map_free("map name error", map);
	if (filename[len - 4] != '.')
		error_func_map_free("map name error", map);
	return ;
}

t_data	*check_map(t_map *map, char const *filename)
{
	size_t	map_size;
	t_data	*data;

	map_size = lst_map_size(map);
	data = init_data(map);
	check_file_name(map, filename);
	check_component(map, map_size);
	printf("%s\n", "OK");
	return (data);
}
