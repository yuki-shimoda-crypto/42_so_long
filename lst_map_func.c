/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:20:16 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/10 18:51:18 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	lst_map_size(t_map *map)
{
	size_t	i;

	i = 0;
	while (map)
	{
		map = map->next;
		i++;
	}
	return (i);
}

void	lst_map_clear(t_map **map)
{
	t_map	*tmp;

	if (!map || !*map)
		return ;
	while (*map)
	{
		tmp = (*map)->next;
		free((*map)->line);
		free(*map);
		*map = NULL;
		*map = tmp;
	}
	return ;
}

t_map	*lst_map_last(t_map *map)
{
	if (!map)
		return (NULL);
	while (map->next)
		map = map->next;
	return (map);
}

void	lst_map_addback(t_map **map, t_map *next)
{
	t_map	*last;

	if (!map || !next)
		return ;
	if (!*map)
	{
		*map = next;
		return ;
	}
	last = lst_map_last(*map);
	last->next = next;
	return ;
}

t_map	*lst_map_new(char *str)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->line = str;
	map->next = NULL;
	map->len_line = ft_strlen(str);
	return (map);
}
