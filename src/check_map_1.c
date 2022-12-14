/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:53:09 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/12 11:29: by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_rect(t_data *data, t_map *map)
{
	size_t	len;

	if (!map || !map->line)
		error_func_data_free("Error\nmap error", data);
	len = ft_strlen(map->line);
	while (map)
	{
		if (len != ft_strlen(map->line))
			error_func_data_free("Error\nmap is not a rectangle", data);
		map = map->next;
	}
	return ;
}

static void	count_component(t_data *data, t_map *map)
{
	size_t	i;

	while (map)
	{
		i = 0;
		while (map->line[i])
		{
			if (map->line[i] == '0')
				data->num_zero = data->num_zero + 1;
			else if (map->line[i] == '1')
				data->num_one = data->num_one + 1;
			else if (map->line[i] == 'C')
				data->num_c = data->num_c + 1;
			else if (map->line[i] == 'E')
				data->num_e = data->num_e + 1;
			else if (map->line[i] == 'P')
				data->num_p = data->num_p + 1;
			else
				error_func_data_free("Error\nmap component error", data);
			i++;
		}
		map = map->next;
	}
	return ;
}

static void	check_component(t_data *data)
{
	count_component(data, data->map);
	if (data->num_e != 1 || data->num_p != 1 || data->num_c < 1)
		error_func_data_free("Error\nmap component error", data);
	return ;
}

static void	check_file_name(t_data *data, char const *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		error_func_data_free("Error\nmap name error", data);
	if (filename[len - 1] != 'r')
		error_func_data_free("Error\nmap name error", data);
	if (filename[len - 2] != 'e')
		error_func_data_free("Error\nmap name error", data);
	if (filename[len - 3] != 'b')
		error_func_data_free("Error\nmap name error", data);
	if (filename[len - 4] != '.')
		error_func_data_free("Error\nmap name error", data);
	return ;
}

t_data	*check_map(t_map *map, char const *filename)
{
	t_data	*data;

	init_data(&data, map);
	if (!data)
		error_func_map_free("Error\nmalloc error", map);
	check_file_name(data, filename);
	check_component(data);
	check_rect(data, data->map);
	check_surrounded_walls(data, data->map);
	check_valid_path(data, data->map);
	return (data);
}
