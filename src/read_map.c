/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:06:26 by dmaldona          #+#    #+#             */
/*   Updated: 2023/03/22 19:04:57 by dmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

char	**read_map(char *map_address)
{
	int		fd;
	int		line;
	char	**hola;

	line = 0;
	fd = open(map_address, O_RDONLY);
	while (fd)
	{
		get_next_line(fd);
		line++;
	}
	return (hola);
}
