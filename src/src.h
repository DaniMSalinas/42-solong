/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:55:05 by dmaldona          #+#    #+#             */
/*   Updated: 2023/03/22 19:02:29 by dmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H
# include <fcntl.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
#endif

int     validate_map();
char    **read_map(char *map_address);

