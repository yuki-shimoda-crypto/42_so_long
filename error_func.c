/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:49:50 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/14 02:08:27 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_func(const char *str)
{
	ft_printf("%s\n", str);
	exit(1);
	return ;
}

void	error_func_map_free(const char *str, t_map *map)
{
	lst_map_clear(&map);
	ft_printf("%s\n", str);
	exit(1);
	return ;
}

void	error_func_data_free(const char *str, t_data *data)
{
	lst_map_clear(&(data->map));
	free(data);
	ft_printf("%s\n", str);
	exit(1);
	return ;
}

void	error_func_data_bfs_free(const char *str, t_data *data, t_bfs *bfs)
{
	bfs_free(bfs);
	error_func_data_free(str, data);
	return ;
}
