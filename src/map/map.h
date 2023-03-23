/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:48:23 by dmaldona          #+#    #+#             */
/*   Updated: 2023/03/23 16:13:06 by dmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <fcntl.h>
# include "../libft/libft.h"

char	**read_map(char *map_address);
int		validate_map_size(int rows, int columns);
int		validate_map_structure(char **map, int rows, int columns);
int		get_map_cols(int fd);
int		get_map_rows(int fd);
void	error_handler(char *str);
#endif
