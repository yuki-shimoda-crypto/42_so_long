# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 22:19:36 by yshimoda          #+#    #+#              #
#    Updated: 2022/11/10 16:21:32 by yshimoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
# CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address

SRCS		=	error_func.c		\
				read_map_utils.c	\
				main.c				\
				read_map.c

OBJS		=	$(SRCS:.c=.o)

LIBFT_DIR	=	libft
INCLUDE		=	include

.c.o:
			$(CC) -c $< -o $@ $(CFLAGS) -I $(INCLUDE)

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C $(LIBFT_DIR)
			$(CC) $(OBJS) -L $(LIBFT_DIR) -l ft -o $(NAME)

clean:		
			make fclean -C $(LIBFT_DIR)
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
