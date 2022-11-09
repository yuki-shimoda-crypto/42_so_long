/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:22:57 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/09 22:38:49 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*read_map(int argc, char const **argv)
{
	int		fd;
	char	*line;
	char	*;
	t_map	*map;
	t_map	*next;

	if (argc != 2)
		error_func("arg error");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_func("open error");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		next = lst_map_new(line);
		if (!next)
		{
			lst_map_clear(&map);
			error_func("malloc error");
		}
		lst_map_addback(&map, next);
	}
	close(fd);
	return (map);
}
