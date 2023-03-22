/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:57:23 by dmaldona          #+#    #+#             */
/*   Updated: 2023/03/22 19:05:01 by dmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./solong <map>\n", 1);
		exit(EXIT_FAILURE);
	}
	printf("%s", argv[1]);
	read_map(argv[1]);
	return (0);
}
