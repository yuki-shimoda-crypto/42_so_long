/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:29:22 by yshimoda          #+#    #+#             */
/*   Updated: 2022/11/15 22:21:38 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_data *data, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, data->mlx_space_image, data->pixel_size * x, data->pixel_size * y);
	if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, data->mlx_wall_image, data->pixel_size * x, data->pixel_size * y);
	if (c == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, data->mlx_collectible_image, data->pixel_size * x, data->pixel_size * y);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, data->mlx_exit_image, data->pixel_size * x, data->pixel_size * y);
	if (c == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, data->mlx_player_image, data->pixel_size * x, data->pixel_size * y);
	return ;
}

void	ft_mlx_put_image(t_data *data)
{
	int		x;
	int		y;
	t_map	*map;

	y = 0;
	map = data->map;
	while (map)
	{
		x = 0;
		while (map->line[x])
		{
			put_image(data, map->line[x], x, y);
			x++;
		}
		map = map->next;
		y++;
	}
	return ;
}

void	ft_mlx_init_image_player(t_data *data, char *xpm_name)
{
	data->mlx_player_image = mlx_xpm_file_to_image(data->mlx_ptr, xpm_name, &data->pixel_size, &data->pixel_size);
	if (!data->mlx_player_image)
	{
		free(xpm_name);
		free(data->pixel_size_str);
		error_func_data_free("mlx error", data);
	}
	return ;
}

void	ft_mlx_init_image_exit(t_data *data, char *xpm_name)
{
	data->mlx_exit_image = mlx_xpm_file_to_image(data->mlx_ptr, xpm_name, &data->pixel_size, &data->pixel_size);
	if (!data->mlx_exit_image)
	{
		free(xpm_name);
		free(data->pixel_size_str);
		error_func_data_free("mlx error", data);
	}
	return ;
}

void	ft_mlx_init_image_collectible(t_data *data, char *xpm_name)
{
	data->mlx_collectible_image = mlx_xpm_file_to_image(data->mlx_ptr, xpm_name, &data->pixel_size, &data->pixel_size);
	if (!data->mlx_collectible_image)
	{
		free(xpm_name);
		free(data->pixel_size_str);
		error_func_data_free("mlx error", data);
	}
	return ;
}

void	ft_mlx_init_image_wall(t_data *data, char *xpm_name)
{
	data->mlx_wall_image = mlx_xpm_file_to_image(data->mlx_ptr, xpm_name, &data->pixel_size, &data->pixel_size);
	if (!data->mlx_wall_image)
	{
		free(xpm_name);
		free(data->pixel_size_str);
		error_func_data_free("mlx error", data);
	}
	return ;
}


void	ft_mlx_init_image_space(t_data *data, char *xpm_name)
{
	data->mlx_space_image = mlx_xpm_file_to_image(data->mlx_ptr, xpm_name, &data->pixel_size, &data->pixel_size);
	if (!data->mlx_space_image)
	{
		free(xpm_name);
		free(data->pixel_size_str);
		error_func_data_free("mlx error", data);
	}
	return ;
}

void	ft_mlx_init_image(t_data *data, const char *content, char *xpm_name)
{
	if (!ft_strncmp(content, "space", ft_strlen("space")))
	{
		data->mlx_space_image = mlx_xpm_file_to_image(data->mlx_ptr, xpm_name, &data->pixel_size, &data->pixel_size);
	}
		ft_mlx_init_image_space(data, xpm_name);
	if (!ft_strncmp(content, "wall", ft_strlen("wall")))
		ft_mlx_init_image_wall(data, xpm_name);
	if (!ft_strncmp(content, "collectible", ft_strlen("collectible")))
		ft_mlx_init_image_collectible(data, xpm_name);
	if (!ft_strncmp(content, "exit", ft_strlen("exit")))
		ft_mlx_init_image_exit(data, xpm_name);
	if (!ft_strncmp(content, "player", ft_strlen("player")))
		ft_mlx_init_image_player(data, xpm_name);
	return ;
}

static void write_xpm_player(t_data *data, char *pixel_size)
{
	long long	i;
	long long	j;

	ft_putstr_fd("/* XPM */\nstatic char *str[] = {\n", data->fd);
	// ft_putstr_fd(xpm_name, data->fd);
	// ft_putstr_fd("[] = {\n", data->fd);
	ft_putstr_fd("/*columsn rows colors chars-per-pixel */\n\"", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" ", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" 1 1\",\n\"0 c #333333\",\n/* pixels */\n", data->fd);
	i = 0;
	while (i < data->pixel_size)
	{
		write(data->fd, "\"", 1);
		j = 0;
		while (j < data->pixel_size)
		{
			write(data->fd, "0", 1);
			j++;
		}
		write(data->fd, "\",\n", 3);
		i++;
	}
	write(data->fd, "};\n", 3);
	return ;
}

static void write_xpm_exit(t_data *data, char *pixel_size)
{
	long long	i;
	long long	j;

	ft_putstr_fd("/* XPM */\nstatic char *str[] = {\n", data->fd);
	// ft_putstr_fd(xpm_name, data->fd);
	// ft_putstr_fd("[] = {\n", data->fd);
	ft_putstr_fd("/*columsn rows colors chars-per-pixel */\n\"", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" ", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" 1 1\",\n\"0 c #999999\",\n/* pixels */\n", data->fd);
	i = 0;
	while (i < data->pixel_size)
	{
		write(data->fd, "\"", 1);
		j = 0;
		while (j < data->pixel_size)
		{
			write(data->fd, "0", 1);
			j++;
		}
		write(data->fd, "\",\n", 3);
		i++;
	}
	write(data->fd, "};\n", 3);
	return ;
}

static void write_xpm_collectible(t_data *data, char *pixel_size)
{
	long long	i;
	long long	j;

	ft_putstr_fd("/* XPM */\nstatic char *str[] = {\n", data->fd);
	// ft_putstr_fd(xpm_name, data->fd);
	// ft_putstr_fd("[] = {\n", data->fd);
	ft_putstr_fd("/*columsn rows colors chars-per-pixel */\n\"", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" ", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" 1 1\",\n\"0 c #777777\",\n/* pixels */\n", data->fd);
	i = 0;
	while (i < data->pixel_size)
	{
		write(data->fd, "\"", 1);
		j = 0;
		while (j < data->pixel_size)
		{
			write(data->fd, "0", 1);
			j++;
		}
		write(data->fd, "\",\n", 3);
		i++;
	}
	write(data->fd, "};\n", 3);
	return ;
}

static void write_xpm_wall(t_data *data, char *pixel_size)
{
	long long	i;
	long long	j;

	ft_putstr_fd("/* XPM */\nstatic char *str[] = {\n", data->fd);
	// ft_putstr_fd(xpm_name, data->fd);
	// ft_putstr_fd("[] = {\n", data->fd);
	ft_putstr_fd("/*columsn rows colors chars-per-pixel */\n\"", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" ", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" 1 1\",\n\"0 c #000000\",\n/* pixels */\n", data->fd);
	i = 0;
	while (i < data->pixel_size)
	{
		write(data->fd, "\"", 1);
		j = 0;
		while (j < data->pixel_size)
		{
			write(data->fd, "0", 1);
			j++;
		}
		write(data->fd, "\",\n", 3);
		i++;
	}
	write(data->fd, "};\n", 3);
	return ;
}

static void write_xpm_space(t_data *data, char *pixel_size)
{
	long long	i;
	long long	j;

	ft_putstr_fd("/* XPM */\nstatic char *str[] = {\n", data->fd);
	// ft_putstr_fd(xpm_name, data->fd);
	// ft_putstr_fd("[] = {\n", data->fd);
	ft_putstr_fd("/*columsn rows colors chars-per-pixel */\n\"", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" ", data->fd);
	ft_putstr_fd(pixel_size, data->fd);
	ft_putstr_fd(" 1 1\",\n\"0 c #ffffff\",\n/* pixels */\n", data->fd);
	i = 0;
	while (i < data->pixel_size)
	{
		write(data->fd, "\"", 1);
		j = 0;
		while (j < data->pixel_size)
		{
			write(data->fd, "0", 1);
			j++;
		}
		write(data->fd, "\",\n", 3);
		i++;
	}
	write(data->fd, "};\n", 3);
	return ;
}

static void	write_xpm(t_data *data, const char *content, char *pixel_size)
{
	if (!ft_strncmp(content, "space", ft_strlen("space")))
		write_xpm_space(data, pixel_size);
	if (!ft_strncmp(content, "wall", ft_strlen("wall")))
		write_xpm_wall(data, pixel_size);
	if (!ft_strncmp(content, "collectible", ft_strlen("collectible")))
		write_xpm_collectible(data, pixel_size);
	if (!ft_strncmp(content, "exit", ft_strlen("exit")))
		write_xpm_exit(data, pixel_size);
	if (!ft_strncmp(content, "player", ft_strlen("player")))
		write_xpm_player(data, pixel_size);
	return ;
}

static void	put_xpm(t_data *data, const char *content, char *pixel_size)
{
	char	*xpm_name;

	xpm_name = ft_strjoin_four(XPM_DIR, content, pixel_size, ".xpm");
	if (!xpm_name)
	{
		free(pixel_size);
		error_func_data_free("open error", data);
	}
	printf("%s\n", xpm_name);
	data->fd = open(xpm_name, O_RDWR | O_CREAT, 0644);
	if (data->fd == -1)
	{
		free(pixel_size);
		free(xpm_name);
		error_func_data_free("open error", data);
	}
	write_xpm(data, content, pixel_size);
	ft_mlx_init_image(data, content, xpm_name);
	close(data->fd);
	free(xpm_name);
	return ;
}

static void	ft_mlx_make_xpm(t_data *data)
{
	data->pixel_size_str = ft_ltoa(data->pixel_size);
	if (!data->pixel_size_str)
		error_func_data_free("malloc error", data);
	put_xpm(data, "space", data->pixel_size_str);
	put_xpm(data, "wall", data->pixel_size_str);
	put_xpm(data, "collectible", data->pixel_size_str);
	put_xpm(data, "exit", data->pixel_size_str);
	put_xpm(data, "player", data->pixel_size_str);
	free(data->pixel_size_str);
	return ;
}

static void	ft_mlx_init(t_data *d)
{
	d->map_height = lst_map_size(d->map);
	d->map_width = ft_strlen(d->map->line);
	d->pixel_size = SCREEN_HEIGHT / d->map_height;
	if (d->pixel_size > SCREEN_WIDTH / d->map_width)
		d->pixel_size = SCREEN_WIDTH / d->map_width;
	if (d->pixel_size <= 0)
		d->pixel_size = 1;
	d->mlx_ptr = mlx_init();
	if (!d->mlx_ptr)
		error_func_data_free("mlx init error", d);
	d->mlx_win_ptr = mlx_new_window(d->mlx_ptr, d->pixel_size * d->map_width,
			d->pixel_size * d->map_height, "so_long");
	if (!d->mlx_win_ptr)
		error_func_data_free("mlx new window error", d);
	return ;
}

void	ft_mlx(t_data *data)
{
	ft_mlx_init(data);
	ft_mlx_make_xpm(data);
	mlx_loop_hook(data->mlx_ptr, mlx_put_image_to_window, data);
	// ft_mlx_put_image(data, data->map, data);
	mlx_loop(data->mlx_ptr);
	return ;
}
