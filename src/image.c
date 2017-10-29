/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:45:28 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/29 22:11:38 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_mlx_image		*image_new(void *mlx_core, int width, int height)
{
	t_mlx_image		*image;

	if (!(image = (t_mlx_image*)malloc(sizeof(*image))))
		return (NULL);
	image->image = mlx_new_image(mlx_core, width, height);
	image->pixels = mlx_get_data_addr(
		image
		, &image->bits_per_pixel
		, &image->bytes_width
		, &image->is_big_endian);
	image->size = ft_vec2i(width, height);
	return (image);
}

void			image_free(void *mlx_core, t_mlx_image **image)
{
	if (*image)
	{
		mlx_destroy_image(mlx_core, (*image)->image);
		free(*image);
		*image = NULL;
	}
}

void			image_put_pixel(t_mlx_image *image, t_vec3f pos, int color)
{
	size_t			index;

	index = (((int)pos.y * image->bytes_width) + ((int)pos.x * 4));
	((int*)image->pixels)[index] = color;
}
