/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:35:07 by dmaldona          #+#    #+#             */
/*   Updated: 2023/03/23 16:11:48 by dmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	validate_map_size(int rows, int columns)
{
	if (rows == 0 || columns == 0)
	{
		error_handler(\
			"[ERROR]: invalid map. Invalid number of rows or columns");
		return (0);
	}
	if (rows == columns)
	{
		error_handler(\
			"[ERROR]: invalid map. Not a rectangular map");
		return (0);
	}
	if (rows < 3 || columns < 4)
	{
		error_handler(\
			"[ERROR]: invalid map. Not enough number of rows or colums");
		return (0);
	}
	return (1);
}

int	get_map_rows(int fd)
{
	int			row;
	char		c;

	row = 0;
	while (read(fd, &c, 1) != 0)
	{
		if (c == '\n' || c == '\0')
			row++;
	}
	return (++row);
}

int	get_map_cols(int fd)
{
	int			column;
	int			prev_column;
	char		c;

	column = 0;
	prev_column = 0;
	while (read(fd, &c, 1) != 0)
	{
		column++;
		if (c == '\n' || c == '\0')
		{
			if (prev_column != 0 && column != prev_column)
				return (0);
			prev_column = column;
			column = 0;
		}
	}
	if (prev_column != 0 && column != --prev_column)
		return (0);
	return (column);
}
