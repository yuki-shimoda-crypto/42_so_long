/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:04:29 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/11 02:35:35 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int main(void)
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;

// 	mlx_ptr = mlx_init();
// 	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "minilibx");
// 	mlx_loop(mlx_ptr);
// 	return (0);
// }

int	main(int argc, char const *argv[])
{
	t_map	*map;
	// t_data	*data;

	map = read_map(argc, argv);
	printf("%p\n", map);
	// data = check_map(map, argv[1]);
	check_map(map, argv[1]);
	lst_map_clear(&map);
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q so_long");
// }

// __attribute__((destructor)) static void destructor()
// {
// 	system("valgrind so_long");
// }

// int	main(int argc, char const *argv[])
// {
// 	t_map	*map;
// 	t_map	*tmp;

// 	map = read_map(argc, argv);
// 	tmp = map;
// 	while (tmp)
// 	{
// 		printf("%s\n", tmp->line);
// 		tmp = tmp->next;
// 	}
// 	check_map(map, argv[1]);
// 	lst_map_clear(&map);
// 	return (0);
// }
