# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 22:19:36 by yshimoda          #+#    #+#              #
#    Updated: 2022/12/02 07:38:34 by yshimoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror 
# MLX_FLAGS		=	 -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
MLX_FLAGS		=	 -lmlx -framework OpenGL -framework AppKit
# MLX_FLAGS_LINUX	=	-L$(MLX_DIR) -lmlx -lXext -lX11
# MLX_DIR			=	minilibx_opengl_20191021	
# MLX_DIR			=	minilibx_mms_20200219	
MLX_DIR		=	minilibx-linux

SRCS			=	src/bfs_utils_1.c				\
					src/bfs_utils_2.c				\
					src/check_map_1.c				\
					src/check_map_2.c				\
					src/check_map_utils.c			\
					src/error_func.c				\
					src/ft_mlx_1.c					\
					src/ft_mlx_2.c					\
					src/ft_mlx_xpm_file_to_image.c	\
					src/ft_mlx_write_xpm.c			\
					src/ft_printf_fd_.c				\
					src/ft_printf_fd_utils.c		\
					src/main.c						\
					src/lst_map_func.c				\
					src/lst_queue_func.c			\
					src/read_map.c

OBJS			=	$(SRCS:%.c=$(OBJDIR)/%.o)
OBJDIR			=	obj

LIBFT_DIR		=	libft
INCLUDE			=	include

$(OBJDIR)/%.o:%.c
				@mkdir -p $(@D);
				$(CC) -c $< -o $@ $(CFLAGS) -I $(INCLUDE)

all:			$(NAME)

$(NAME):		$(OBJS)
				@make -C $(LIBFT_DIR)
				@make -C $(MLX_DIR)
				$(CC) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) $(MLX_FLAGS_LINUX) -o $(NAME)

clean:		
				make fclean -C $(LIBFT_DIR)
				@make clean -C $(MLX_DIR)
				$(RM) -r $(OBJDIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
