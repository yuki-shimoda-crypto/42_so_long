/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:47:19 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/14 18:30:26 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		error_func_data_free("mlx init error", data);
	data->mlx_win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "so_long");
	if (!data->mlx_win_ptr)
		error_func_data_free("mlx new window error", data);
	mlx_loop(data->mlx_ptr);
	return ;
}
