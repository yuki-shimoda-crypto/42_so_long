/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:04:29 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/08 22:21:15 by yshimoda         ###   ########.fr       */
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
	int		fd;
	char	buf[5];
	ssize_t	byte_read;
	char	**map;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	byte_read = read(fd, buf, 5);
	if (byte_read == -1)
	{
		close(fd);
		return (1);
	}
	printf("%s\n", buf);
	close(fd);
	return (0);
}
