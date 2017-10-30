/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 22:15:30 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/30 08:29:27 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		map_load(t_map *map)
{
	map->size = ft_vec2i(11, 11);
	if (!(map->tiles = (char*)ft_memalloc(
			sizeof(char) * map->size.x * map->size.y)))
		return (0);
	map->face_colors[0] = 0xFF0000;
	map->face_colors[1] = 0xFF00FF;
	map->face_colors[2] = 0x0000FF;
	map->face_colors[3] = 0x00FF00;
	map->tiles[19] = 1;
	map->tiles[42] = 1;
	map->tiles[78] = 1;
	map->tiles[72] = 1;
	map->tiles[73] = 1;
	return (1);
}
