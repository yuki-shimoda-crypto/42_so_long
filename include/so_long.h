/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:59:24 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/14 00:55:55 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
// # include <mlx.h>
# include "libft.h"

typedef struct s_data
{
	struct s_map	*map;
	long long		num_zero;
	long long		num_one;
	long long		num_c;
	long long		num_e;
	long long		num_p;
	long long		start_x;
	long long		start_y;
}			t_data;

typedef struct s_map
{
	char			*line;
	size_t			len_line;
	struct s_map	*pre;
	struct s_map	*next;
}			t_map;

typedef struct s_bfs
{
	long long		bfs_num_c;
	long long		bfs_num_e;
	int				*bfs_map;
	struct s_queue	*bfs_queue;
}			t_bfs;

typedef struct s_queue
{
	long long		x;
	long long		y;
	struct s_queue	*next;
}			t_queue;

void	bfs_init(t_data *data, t_bfs **bfs);
bool	bfs_can_move_up(t_bfs *bfs, t_map *map, size_t len_col);
bool	bfs_can_move_down(t_bfs *bfs, t_map *map, size_t len_col);
bool	bfs_can_move_right(t_bfs *bfs, t_map *map, size_t len_col);
bool	bfs_can_move_left(t_bfs *bfs, t_map *map, size_t len_col);
void	bfs_write_one_add_que(t_bfs *bfs, t_data *data, long long x, long long y);
t_data	*check_map(t_map *map, char const *filename);
void	check_surrounded_walls(t_data *data, t_map *map);
void	check_valid_path(t_data *data, t_map *map);
void	error_func(const char *str);
void	error_func_map_free(const char *str, t_map *map);
void	error_func_data_free(const char *str, t_data *data);
void	find_start(t_data *data, t_map *map);
t_data	*init_data(t_map *map);
t_map	*lst_map_new(char *str);
void	lst_map_addback(t_map **map, t_map *next);
t_map	*lst_map_last(t_map *map);
void	lst_map_clear(t_map **map);
size_t	lst_map_size(t_map *map);
void	lst_queue_clear(t_queue **queue);
void	lst_queue_dequeue(t_queue **queue);
void	lst_queue_enqueue(t_queue **queue, t_queue *next);
t_queue	*lst_queue_last(t_queue *queue);
t_queue	*lst_queue_new(long long x, long long y);
t_map	*move_map_row(t_map *map, long long y);
t_map	*read_map(int argc, char const **argv);

size_t	lst_queue_size(t_queue *queue);
#endif
