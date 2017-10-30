/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:45:28 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/30 06:34:03 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_mlx_image		*image_new(void *mlx_core, int width, int height)
{
	t_mlx_image		*image;

	if (!(image = (t_mlx_image*)malloc(sizeof(*image))))
		return (NULL);
	image->image = mlx_new_image(mlx_core, width, height);
	image->pixels = (int*)mlx_get_data_addr(
		image->image
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

void			image_put_pixel(t_mlx_image *image, t_vec2i pos
		, unsigned int color)
{
	size_t			index;

	index = (((int)pos.y * image->size.x) + ((int)pos.x));
	image->pixels[index] = color;
}

void			image_clear(t_mlx_image *image, unsigned int color)
{
	int		i;

	i = -1;
	while (++i < image->size.x * image->size.y)
		image->pixels[i] = color;
}

void			image_fill_rect(t_mlx_image *image, t_vec2i pos, t_vec2i size
		, unsigned int color)
{
	int		x;
	int		y;

	y = -1;
	while (++y < size.y)
	{
		x = -1;
		while (++x < size.x)
		{
			image_put_pixel(image, ft_vec2i(pos.x + x, pos.y + y), color);
		}
	}
}
