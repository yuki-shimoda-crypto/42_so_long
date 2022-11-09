/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:04:29 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/09 22:36:16 by yshimoda         ###   ########.fr       */
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

int main(int argc, char const *argv[])
{
	t_map	*map;
	t_map	*tmp;

	map = read_map(argc, argv);
	tmp = map;
	while (tmp)
	{
		printf("%lld\n", tmp->len_line);
		printf("%s", tmp->line);
		// printf("%s\n", "-----------");
		tmp = tmp->next;
	}
	lst_map_clear(&map);
	return (0);
}
