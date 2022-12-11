# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 22:19:36 by yshimoda          #+#    #+#              #
#    Updated: 2022/12/11 17:05:26 by yshimoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror 
CFLAGS_DEBUG	=	-g -fsanitize=address -fsanitize=leak -fsanitize=undefined
MLX_DIR			=	minilibx-linux

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

MAP_TURE		=	map/t_map01_subject_1.ber	\
					map/t_map02_subject_2.ber	\
					map/t_map03_minimam.ber		\
					map/t_map04_middle.ber		\
					map/t_map05_big.ber			\
					map/t_map06_ultra_big.ber	\
					map/t_map07_one_raw.ber		\
					map/t_map08_one_line.ber	\
					map/t_map09_github_nop.ber	\
					map/t_map10_maze.ber		\
					map/t_map11_maze.ber		\
					map/t_map12_seto.ber

MAP_FALSE		=	map/f_map00_name_error.berr					\
					map/f_map01_two_E.ber						\
					map/f_map02_two_P.ber						\
					map/f_map03_zero_C.ber						\
					map/f_map04_zero_E.ber						\
					map/f_map05_zero_P.ber						\
					map/f_map06_blank_map.ber					\
					map/f_map07_not_rect.ber					\
					map/f_map08_top_blank_line.ber				\
					map/f_map10_middle_blank_line.ber			\
					map/f_map11_not_walled_upper_left.ber		\
					map/f_map12_not_walled_upper_right.ber		\
					map/f_map13_not_walled_lower_left.ber		\
					map/f_map14_not_walled_lower_right.ber		\
					map/f_map15_middle_of_the_top_row.ber		\
					map/f_map16_middle_of_the_bottom_row.ber	\
					map/f_map17_middle_of_the_left_column.ber	\
					map/f_map18_middle_of_the_right_column.ber	\
					map/f_map19_one_line.ber					\
					map/f_map20_two_line.ber					\
					map/f_map21_invalid_path.ber				\
					map/f_map22_cannot_collect_c.ber			\
					map/f_map23_cannot_collect_c.ber

OBJS			=	$(SRCS:%.c=$(OBJDIR)/%.o)
OBJDIR			=	obj

LIBFT_DIR		=	libft
INCLUDE			=	-I include -I $(MLX_DIR)

OS				=	$(shell uname)

ifeq ($(OS), Linux)
MLX_FLAGS		=	-L$(MLX_DIR) -lmlx -lXext -lX11
else
MLX_FLAGS		=	 -lmlx -framework OpenGL -framework AppKit
# MLX_FLAGS		=	 -lmlx -L . -lX11 -lXext -L /usr/X11R6/lib -framework OpenGL
endif

$(OBJDIR)/%.o:%.c
				@mkdir -p $(@D);
				$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

$(NAME):		$(OBJS)
				@make -C $(LIBFT_DIR)
				@make -C $(MLX_DIR)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS)

PHONY			=	all
all:			$(NAME)

PHONY			+=	clean
clean:		
				make fclean -C $(LIBFT_DIR)
				@make clean -C $(MLX_DIR)
				$(RM) -r $(OBJDIR)

PHONY			+=	fclean
fclean:			clean
				$(RM) $(NAME)

PHONY			+=	re
re:				fclean all

PHONY			+=	play
play:			all
				for map in $(MAP_TURE) ; do	\
				echo $$map;					\
				./$(NAME) $$map;			\
				echo -e "\n"; done
				@echo "----finish----"

PHONY			+=	error
error:			all
				for error_map in $(MAP_FALSE) ; do	\
				echo $$error_map;					\
				./$(NAME) $$error_map;				\
				echo -e "\n"; done
				@echo "----finish----"

PHONY			+=	debug
debug:			CFLAGS += $(CFLAGS_DEBUG)
debug:			fclean
debug:			all

.PHONY:			$(PHONY)
