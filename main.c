/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:04:29 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/30 04:04:47 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char const *argv[])
{
	t_map	*map;
	t_data	*data;

	map = read_map(argc, argv);
	data = check_map(map, argv[1]);
	ft_mlx(data);
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q so_long");
// }


// #include <stdio.h>
// int main(void)
// {
// 	void	*mlx_ptr;
// 	void	*mlx_image;

// 	mlx_ptr = mlx_init();
// 	mlx_image = NULL;
// 	mlx_destroy_image(mlx_ptr, mlx_image);
// 	return (0);
// }