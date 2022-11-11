/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:22:57 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/11 23:55:27 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map	*input_lst(int fd)
{
	char	*line;
	size_t	i;
	t_map	*map;
	t_map	*next;

	map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i = 0;
		while (line[i] != '\n' && line[i] != '\0')
			i++;
		if (line[i] == '\n')
			line[i] = '\0';
		next = lst_map_new(line);
		if (!next)
			error_func_map_free("malloc error", map);
		lst_map_addback(&map, next);
	}
	return (map);
}

t_map	*read_map(int argc, char const **argv)
{
	int		fd;
	t_map	*map;

	if (argc != 2)
		error_func("arg error");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_func("open error");
	map = input_lst(fd);
	close(fd);
	if (!map)
		error_func("blank map, malloc error or read error");
	return (map);
}
