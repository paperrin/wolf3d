/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:34:16 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/30 07:41:53 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdlib.h>
# include "mlx.h"
# include "x11.h"
# include "libft.h"
# include "ft_math.h"

typedef struct		s_mlx
{
	void			*core;
	void			*win;
}					t_mlx;

typedef struct		s_mlx_image
{
	void			*image;
	int				*pixels;
	int				bits_per_pixel;
	int				bytes_width;
	int				is_big_endian;
	t_vec2i			size;
}					t_mlx_image;

typedef struct		s_player
{
	t_vec2f			pos;
	t_vec2f			dir;
	t_vec2f			plane;
	int				left_pressed;
	int				right_pressed;
	int				up_pressed;
	int				down_pressed;
}					t_player;

typedef struct		s_map
{
	char			*tiles;
	char			border_tile_id;
	unsigned int	face_colors[4];
	t_vec2i			size;
}					t_map;

typedef struct		s_app
{
	t_mlx			mlx;
	t_mlx_image		*draw_buf;
	t_vec2i			size;
	t_player		player;
	t_map			map;
}					t_app;

typedef struct		s_hit
{
	int				hit;
	int				side;
	int				tile_id;
	t_vec2i			map_pos;
	t_vec2f			side_dist;
	t_vec2f			delta_dist;
	t_vec2f			step;
}					t_hit;

void				destroy_app(t_app *app, int exit_code);
int					render(void *param);

void				player_update(t_app *app);
int					map_load(t_map *map);

int					event_key_press(int key, void *param);
int					event_key_release(int key, void *param);
int					event_cross(void *param);

t_mlx_image			*image_new(void *mlx_core, int width, int height);
void				image_free(void *mlx_core, t_mlx_image **image);
void				image_put_pixel(t_mlx_image *image, t_vec2i pos
		, unsigned int color);
void				image_clear(t_mlx_image *image, unsigned int color);
void				image_fill_rect(t_mlx_image *image, t_vec2i pos
		, t_vec2i size, unsigned int color);

#endif
