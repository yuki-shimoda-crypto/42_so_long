/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:53:09 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/11 02:35:04 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_component(t_data *data, t_map *map)
{
	size_t	i;

	printf("%p\n", map);
	while (map)
	{
		i = 0;
		while (map->line[i])
		{
			if (map->line[i] == '0')
				data->c_zero = data->c_zero + 1;
			else if (map->line[i] == '1')
				data->c_one = data->c_one + 1;
			else if (map->line[i] == 'C')
				data->c_c = data->c_c + 1;
			else if (map->line[i] == 'E')
				data->c_e = data->c_e + 1;
			else if (map->line[i] == 'P')
				data->c_p = data->c_p + 1;
			else
				error_func_data_free("map component error", data);
			i++;
		}
		map = map->next;
	}
	return ;
}

static void	check_component(t_data *data)
{
	printf("%p\n", data->map);
	count_component(data, data->map);
	printf("%p\n", data->map);
	if (data->c_e != 1 || data->c_p != 1 || data->c_c < 1)
	{
		printf("%lld\n", data->c_zero);
		printf("%lld\n", data->c_one);
		printf("%lld\n", data->c_c);
		printf("%lld\n", data->c_e);
		printf("%lld\n", data->c_p);
		printf("%s\n", "afa");
		error_func_data_free("map component error", data);
	}
	return ;
}

static void	check_file_name(t_data *data, char const *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		error_func_data_free("map name error", data);
	if (filename[len - 1] != 'r')
		error_func_data_free("map name error", data);
	if (filename[len - 2] != 'e')
		error_func_data_free("map name error", data);
	if (filename[len - 3] != 'b')
		error_func_data_free("map name error", data);
	if (filename[len - 4] != '.')
		error_func_data_free("map name error", data);
	return ;
}

t_data	*check_map(t_map *map, char const *filename)
{
	t_data	*data;

	printf("%p\n", map);
	data = init_data(map);
	if (!data)
		error_func_map_free("malloc error", map);
	check_file_name(data, filename);
	check_component(data);
	printf("%s\n", "OK");
	return (data);
}
