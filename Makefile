# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 18:36:08 by dmaldona          #+#    #+#              #
#    Updated: 2023/03/23 18:26:56 by dmaldona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= all
SOURCES			= solong.c \
					src/map/map_manager.c \
					src/map/validate_map_size.c \
					src/map/validate_map_structure.c

OBJECTS 		= $(SOURCES:%.c=%.o)

CC				= gcc
CFLAGS			= -Wall -Wextra
RM				= rm -f
CD				= cd

LIBFT_DIR		= src/libft/
LIBFT_SOURCE	= src/libft/libft.a
MLX_DIR			= mlx/
MLX_SOURCE		= mlx/libmlx.a

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJECTS)
	@ $(MAKE) -C $(LIBFT_DIR)
	@ $(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_SOURCE) $(MLX_SOURCE) -Lmlx -lmlx -framework OpenGL -framework AppKit -L. -o $(NAME)

clean:
	$(RM) solong.o
	@ $(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) solong.o
	$(RM) src/map/*.o
	@ $(MAKE) clean -C $(LIBFT_DIR)

re:	fclean all

norme:
	@norminette
	
.PHONY:	all clean fclean re bonus