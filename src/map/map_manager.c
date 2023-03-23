/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:06:26 by dmaldona          #+#    #+#             */
/*   Updated: 2023/03/23 16:32:28 by dmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	error_handler(char *str)
{
	ft_putstr_fd(str, 1);
}

char	**free_map(char **map, int rows_i)
{
	while (rows_i >= 0)
	{
		free(map[rows_i]);
		map[rows_i] = NULL;
		rows_i--;
	}
	free(map);
	map = NULL;
	return (NULL);
}

char	**copy_map(int fd, char **map)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (read(fd, &c, 1) != 0)
	{
		if (c != '\n')
		{
			map[i][j] = c;
			j++;
		}
		else
		{
			j = 0;
			i++;
		}
	}
	return (map);
}

char	**malloc_map(int rows, int colums)
{
	int		rows_i;
	char	**map;

	map = (char **)ft_calloc(rows + 1, sizeof(char *));
	if (!map)
		return (NULL);
	rows_i = 0;
	while (rows_i < rows)
	{
		map[rows_i] = (char *)ft_calloc(colums + 1, sizeof(char));
		if (!map[rows_i])
			free_map(map, rows_i);
		rows_i++;
	}
	return (map);
}

char	**read_map(char *map_address)
{
	int			fd_rows;
	int			fd_cols;
	int			fd_copy;
	static int	size[2];
	char		**map;

	fd_rows = open(map_address, O_RDONLY);
	size[0] = get_map_rows(fd_rows);
	fd_cols = open(map_address, O_RDONLY);
	size[1] = get_map_cols(fd_cols);
	if (!validate_map_size(size[0], size[1]))
		return (NULL);
	map = malloc_map(size[0], size[1]);
	fd_copy = open(map_address, O_RDONLY);
	map = copy_map(fd_copy, map);
	if (!validate_map_structure(map, size[0], size[1]))
		return (NULL);
	return (map);
}
