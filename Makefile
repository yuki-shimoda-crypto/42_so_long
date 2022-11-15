# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 22:19:36 by yshimoda          #+#    #+#              #
#    Updated: 2022/11/14 18:21:54 by yshimoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	cc
# CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
# CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address

SRCS		=	bfs_utils_1.c		\
				bfs_utils_2.c		\
				check_map_1.c		\
				check_map_2.c		\
				check_map_utils.c	\
				error_func.c		\
				ft_mlx.c			\
				main.c				\
				lst_map_func.c		\
				lst_queue_func.c	\
				read_map.c

OBJS		=	$(SRCS:%.c=$(OBJDIR)/%.o)
OBJDIR		=	obj

LIBFT_DIR	=	libft
MLX_DIR		=	minilibx-linux
MLX_FLAGS	=	-lmlx -lXext -lX11
# MLX_LINUX	=	mlx_Linux
INCLUDE		=	include

$(OBJDIR)/%.o:%.c
			@mkdir -p $(@D);
			$(CC) -c $< -o $@ $(CFLAGS) -I $(INCLUDE)

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C $(LIBFT_DIR)
			@make -C $(MLX_DIR)
			$(CC) $(OBJS) -L $(LIBFT_DIR) -l ft -L $(MLX_DIR) $(MLX_FLAGS) -o $(NAME)

clean:		
			make fclean -C $(LIBFT_DIR)
			@make clean -C $(MLX_DIR)
			$(RM) -r $(OBJDIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

test:
			@make -C minilibx-linux

.PHONY:		all clean fclean re
