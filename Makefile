# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 22:19:36 by yshimoda          #+#    #+#              #
#    Updated: 2022/11/26 13:08:49by yshimoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
# CC				=	cc
CC				=	clang
CFLAGS			=	-Wall -Wextra -Werror 
# CFLAGS			=	-Wall -Wextra -Werror -fsanitize=address -g
# MLX_FLAGS		=	-lmlx -framework OpenGL -framework AppKit
MLX_FLAGS_LINUX	=	-L$(MLX_DIR) -lmlx -lXext -lX11
MLX_DIR			=	minilibx-linux

SRCS			=	bfs_utils_1.c				\
					bfs_utils_2.c				\
					check_map_1.c				\
					check_map_2.c				\
					check_map_utils.c			\
					error_func.c				\
					ft_mlx_1.c					\
					ft_mlx_2.c					\
					ft_mlx_xpm_file_to_image.c	\
					ft_mlx_write_xpm.c			\
					ft_printf_fd_.c				\
					ft_printf_fd_utils.c		\
					main.c						\
					lst_map_func.c				\
					lst_queue_func.c			\
					read_map.c

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
