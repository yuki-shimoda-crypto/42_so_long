/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:59:24 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/10 19:00:30 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"

typedef struct s_data
{
	struct s_map	*map;
	long long		c_zero;
	long long		c_one;
	long long		c_c;
	long long		c_e;
	long long		c_p;
}			t_data;

typedef struct s_map
{
	char			*line;
	long long		len_line;
	struct s_map	*next;
}			t_map;

t_data	*check_map(t_map *map, char const *filename);
void	error_func(const char *str);
void	error_func_map_free(const char *str, t_map *map);
t_map	*lst_map_new(char *str);
void	lst_map_addback(t_map **map, t_map *next);
t_map	*lst_map_last(t_map *map);
void	lst_map_clear(t_map **map);
size_t	lst_map_size(t_map *map);
t_map	*read_map(int argc, char const **argv);

#endif
