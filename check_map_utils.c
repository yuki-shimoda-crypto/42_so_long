/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:01:50 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/11 02:18:50 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*init_data(t_map *map)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->map = map;
	data->c_zero = 0;
	data->c_one = 0;
	data->c_c = 0;
	data->c_e = 0;
	data->c_p = 0;
	return (data);
}
