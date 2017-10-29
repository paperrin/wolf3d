/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 22:15:30 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/29 22:25:53 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		map_load(t_map *map)
{
	t_vec2i		pos;

	map->size = ft_vec2i(11, 11);
	if (!(map->tiles = (char*)ft_memalloc(
			sizeof(char) * map->size.x * map->size.y)))
		return (0);
	pos = ft_vec2i(0, 0);
	while (pos.y < map->size.y)
	{
		pos.x = 0;
		while (pos.x < map->size.x)
		{
			if (pos.x == 0 || pos.x == map->size.x - 1
					|| pos.y == 0 || pos.y == map->size.y - 1)
				map->tiles[pos.y * map->size.x + pos.x] = 1;
			pos.x++;
		}
		pos.y++;
	}
	return (1);
}
