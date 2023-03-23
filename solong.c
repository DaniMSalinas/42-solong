/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:57:23 by dmaldona          #+#    #+#             */
/*   Updated: 2023/03/23 16:03:51 by dmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int argc, char *argv[])
{
	char	**map;

	if (argc != 2)
	{
		ft_putstr_fd("[ERROR] Usage: ./solong <map>\n", 1);
		exit(EXIT_FAILURE);
	}
	map = read_map(argv[1]);
	if (!map)
		exit(EXIT_FAILURE);
	return (0);
}
