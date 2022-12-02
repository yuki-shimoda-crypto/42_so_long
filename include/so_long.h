/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:59:24 by yshimoda          #+#    #+#             */
/*   Updated: 2022/12/02 07:53:42 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SCREEN_HEIGHT 1080
# define SCREEN_WIDTH 1920
// # define KEY_LEFT 65361
// # define KEY_UP 65362
// # define KEY_RIGHT 65363
// # define KEY_DOWN 65364
// # define KEY_W 'w'
// # define KEY_A 'a'
// # define KEY_S 's'
// # define KEY_D 'd'
// # define KEY_ESC 65307
# define KEY_LEFT 123
# define KEY_UP 126
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define XPM_DIR "xpm/"
# define MLX_NO_FREE 0
# define MLX_INIT_FREE 1
# define MLX_WINDOW_FREE 2
# define MLX_IMAGE_FREE 3

# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
// # include "../minilibx_mms_20200219/mlx.h"
// # include "../minilibx_opengl_20191021/mlx.h"
// # include "../minilibx-linux/mlx.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	struct s_map	*map;
	long long		map_height;
	long long		map_width;
	long long		num_zero;
	long long		num_one;
	long long		num_c;
	long long		num_e;
	long long		num_p;
	long long		start_x;
	long long		start_y;
	void			*mlx_ptr;
	void			*mlx_win_ptr;
	void			*mlx_space_image;
	void			*mlx_wall_image;
	void			*mlx_collectible_image;
	void			*mlx_exit_image;
	void			*mlx_player_image;
	char			*pixel_size_str;
	int				pixel_size;
	char			*xpm_name;
	long long		step;
	int				fd;
}					t_data;

typedef struct s_map
{
	char			*line;
	size_t			len_line;
	struct s_map	*pre;
	struct s_map	*next;
}					t_map;

typedef struct s_bfs
{
	long long		bfs_num_c;
	long long		bfs_num_e;
	int				*bfs_map;
	struct s_queue	*bfs_queue;
}					t_bfs;

typedef struct s_queue
{
	long long		x;
	long long		y;
	struct s_queue	*next;
}					t_queue;

void				bfs_init(t_data *data, t_bfs **bfs);
bool				bfs_can_move_up(t_bfs *bfs, t_map *map, size_t len_col);
bool				bfs_can_move_down(t_bfs *bfs, t_map *map, size_t len_col);
bool				bfs_can_move_right(t_bfs *bfs, t_map *map, size_t len_col);
bool				bfs_can_move_left(t_bfs *bfs, t_map *map, size_t len_col);
void				bfs_free(t_bfs *bfs);
void				bfs_write_one_add_que(t_bfs *bfs, t_data *data, long long x,
						long long y);
t_data				*check_map(t_map *map, char const *filename);
void				check_surrounded_walls(t_data *data, t_map *map);
void				check_valid_path(t_data *data, t_map *map);
void				error_func(const char *str);
void				error_func_map_free(const char *str, t_map *map);
void				error_func_data_free(const char *str, t_data *data);
void				error_func_data_bfs_free(const char *str, t_data *data,
						t_bfs *bfs);
void				error_func_data_mlx_free(const char *str, t_data *data,
						int flag);
void				find_start(t_data *data, t_map *map);
void				ft_mlx(t_data *data);
int					ft_mlx_destroy(t_data *data);
int					ft_mlx_move_map(int key_num, t_data *data);
int					ft_mlx_put_image_to_window(t_data *data);
void				ft_mlx_xpm_file_to_image_space(t_data *data);
void				ft_mlx_xpm_file_to_image_wall(t_data *data);
void				ft_mlx_xpm_file_to_image_collectible(t_data *data);
void				ft_mlx_xpm_file_to_image_exit(t_data *data);
void				ft_mlx_xpm_file_to_image_player(t_data *data);
ssize_t				ft_put_char_fd(int fd, char c);
ssize_t				ft_put_str_fd(int fd, char *str);
ssize_t				ft_put_ptr_fd(int fd, uintptr_t num);
int					ft_printf_fd(int fd, const char *format, ...);
void				init_data(t_data **data, t_map *map);
t_map				*lst_map_new(char *str);
void				lst_map_addback(t_map **map, t_map *next);
t_map				*lst_map_last(t_map *map);
void				lst_map_clear(t_map **map);
size_t				lst_map_size(t_map *map);
void				lst_queue_clear(t_queue **queue);
void				lst_queue_dequeue(t_queue **queue);
void				lst_queue_enqueue(t_queue **queue, t_queue *next);
t_queue				*lst_queue_last(t_queue *queue);
t_queue				*lst_queue_new(long long x, long long y);
t_map				*move_map_row(t_map *map, long long y);
t_map				*read_map(int argc, char const **argv);
void				write_xpm_space_to_file(t_data *d, char *pixel_size,
						long long i, long long j);
void				write_xpm_wall_to_file(t_data *d, char *pixel_size,
						long long i, long long j);
void				write_xpm_collectible_to_file(t_data *d, char *pixel_size,
						long long i, long long j);
void				write_xpm_exit_to_file(t_data *d, char *pixel_size,
						long long i, long long j);
void				write_xpm_player_to_file(t_data *d, char *pixel_size,
						long long i, long long j);

#endif
