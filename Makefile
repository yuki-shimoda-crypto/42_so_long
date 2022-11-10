# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 22:19:36 by yshimoda          #+#    #+#              #
#    Updated: 2022/11/10 18:36:17 by yshimoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
# CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address

SRCS		=	check_map.c			\
				error_func.c		\
				main.c				\
				lst_map_func.c		\
				read_map.c

OBJS		=	$(SRCS:%.c=$(OBJDIR)/%.o)
OBJDIR		=	objs

LIBFT_DIR	=	libft
INCLUDE		=	include

$(OBJDIR)/%.o:%.c
			@mkdir -p $(@D);
			$(CC) -c $< -o $@ $(CFLAGS) -I $(INCLUDE)

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C $(LIBFT_DIR)
			$(CC) $(OBJS) -L $(LIBFT_DIR) -l ft -o $(NAME)

clean:		
			make fclean -C $(LIBFT_DIR)
			$(RM) -r $(OBJDIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
