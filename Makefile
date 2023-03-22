# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 18:36:08 by dmaldona          #+#    #+#              #
#    Updated: 2023/03/22 19:14:21 by dmaldona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= all
SOURCES			= solong.c \
					src/read_map.c \
					src/validate_map.c
OBJECTS 		= $(SOURCES:%.c=%.o)

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f
CD				= cd

LIBFT_DIR		= src/libft/
LIBFT_SOURCE	= src/libft/libft.a
GNL_DIR			= src/gnl
GNL_SOURCE		= src/gnl/get_next_line.a


%.o: %.c
	$(CC) -c $(CFLAGS) $?

all:	solong

$(NAME): solong

solong:	solong.o
	@ $(MAKE) -C $(LIBFT_DIR)
	@ $(MAKE) -C $(GNL_DIR)
	$(CC) $(CFLAGS) $(LIBFT_SOURCE) $(GNL_SOURCE) -o $@ $<

clean:
	$(RM) solong.o
	@ $(MAKE) clean -C $(LIBFT_DIR)
	@ $(MAKE) clean -C $(GNL_DIR)

fclean: clean
	$(RM) solong
	$(RM) $(LIBFT_SOURCE) $(GNL_SOURCE)

re:	fclean all

norme:
	@norminette	solong.c solong.h src
.PHONY:	all clean fclean re bonus