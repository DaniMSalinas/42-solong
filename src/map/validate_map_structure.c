/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_structure.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:59:38 by dmaldona          #+#    #+#             */
/*   Updated: 2023/03/23 15:54:47 by dmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/* Map is composed by 5 different characters: 
	- 0 for free space
	- 1 for a wall
	- C for coleccionable
	- E to exit the map
	- P for the initial position */

int	validate_hoz_walls(char **map, int rows, int columns)
{
	int	i;

	i = 0;
	while (i < columns)
	{
		if (map[0][i] != '1')
		{
			error_handler("[ERROR]: invalid top wall\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < columns)
	{
		if (map[rows - 1][i] != '1')
		{
			error_handler("[ERROR]: invalid bottom wall\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	validate_vert_walls(char **map, int rows, int columns)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (map[i][0] != '1')
		{
			error_handler("[ERROR]: invalid left wall\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < rows)
	{
		if (map[i][columns - 1] != '1')
		{
			error_handler("[ERROR]: invalid bottom wall\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	validate_map_components1(char **map, int rows, int columns)
{
	int	i;
	int	j;
	int	start;
	int	exit;

	i = 0;
	start = 0;
	exit = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			if (map[i][j] == 'E')
				exit++;
			else if (map[i][j] == 'P')
				start++;
			j++;
		}
		i++;
	}
	if (start != 1 || exit != 1)
		return (0);
	return (1);
}

int	validate_map_components2(char **map, int rows, int columns)
{
	int	i;
	int	j;
	int	objects;

	i = 0;
	objects = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			if (map[i][j] == 'C')
				objects++;
			j++;
		}
		i++;
	}
	if (objects < 1)
		return (0);
	return (1);
}

int	validate_map_structure(char **map, int rows, int columns)
{
	if (!validate_hoz_walls(map, rows, columns))
		return (0);
	if (!validate_vert_walls(map, rows, columns))
		return (0);
	if (!validate_map_components1(map, rows, columns))
	{
		error_handler(\
			"[ERROR]: invalid map components. More then 1 exit or start\n");
		return (0);
	}
	if (!validate_map_components2(map, rows, columns))
	{
		error_handler(\
			"[ERROR]: invalid map components. Less than 1 object\n");
		return (0);
	}
	return (1);
}
