/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:04:29 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/15 15:59:05 by yshimoda         ###   ########.fr       */
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
	t_data	*data;

	map = read_map(argc, argv);
	data = check_map(map, argv[1]);
	// open()
	ft_mlx(data);
	lst_map_clear(&map);
	return (0);
}

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
// 		// printf("%s\n", tmp->line);
// 		printf("pre  = %p\n", tmp->pre);
// 		printf("now  = %p\n", tmp);
// 		printf("next = %p\n", tmp->next);
// 		printf("%s\n\n", "------------");
// 		tmp = tmp->next;
// 	}
// 	lst_map_clear(&map);
// 	return (0);
// }
