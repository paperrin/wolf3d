/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 21:59:54 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/30 04:07:56 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_hit	do_collision_checks(t_map map, t_hit hit)
{
	hit.hit = 0;
	hit.tile_id = map.border_tile_id;
	while (!hit.hit)
	{
		if (hit.side_dist.x < hit.side_dist.y)
		{
			hit.side_dist.x += hit.delta_dist.x;
			hit.map_pos.x += hit.step.x;
			hit.side = 0;
		}
		else
		{
			hit.side_dist.y += hit.delta_dist.y;
			hit.map_pos.y += hit.step.y;
			hit.side = 1;
		}
		if (hit.map_pos.x < 0 || hit.map_pos.x >= map.size.x
				|| hit.map_pos.y < 0 || hit.map_pos.y >= map.size.y)
			break ;
		if ((hit.tile_id = map.tiles[hit.map_pos.y * map.size.x
					+ hit.map_pos.x]) > 0)
			hit.hit = 1;
	}
	return (hit);
}

static void		draw_line(t_app *app, int x, float wall_dist, int face)
{
	int		line_height;
	int		y_min;
	int		y_max;

	(void)face;
	line_height = app->size.y / wall_dist;
	y_min = app->size.y / 2 - line_height / 2;
	if (y_min < 0)
		y_min = 0;
	y_max = app->size.y / 2 + line_height / 2;
	if (y_max >= app->size.y)
		y_max = app->size.y - 1;
	while (y_min <= y_max)
	{
		image_put_pixel(app->draw_buf, ft_vec3f(x, y_min, 0), 0xFF0000);
		y_min++;
	}
}

static void		cast_ray(t_app *app, int x, t_vec2f orig, t_vec2f dir)
{
	t_hit		hit;
	float		wall_dist;

	hit.delta_dist = ft_vec2f(sqrt(1 + (dir.y * dir.y) / (dir.x * dir.x))
			, sqrt(1 + (dir.x * dir.x) / (dir.y * dir.y)));
	hit.step.x = (dir.x < 0) ? -1 : 1;
	hit.step.y = (dir.y < 0) ? -1 : 1;
	hit.map_pos = ft_vec2i(floor(orig.x), floor(orig.y));
	if (dir.x < 0)
		hit.side_dist.x = (orig.x - hit.map_pos.x) * hit.delta_dist.x;
	else
		hit.side_dist.x = (hit.map_pos.x + 1 - orig.x) * hit.delta_dist.x;
	if (dir.y < 0)
		hit.side_dist.y = (orig.y - hit.map_pos.y) * hit. delta_dist.y;
	else
		hit.side_dist.y = (hit.map_pos.y + 1 - orig.y) * hit.delta_dist.y;
	hit = do_collision_checks(app->map, hit);
	if (hit.side == 0)
		wall_dist = (hit.map_pos.x - orig.x + (1 - hit.step.x) / 2) / dir.x;
	else
		wall_dist = (hit.map_pos.y - orig.y + (1 - hit.step.y) / 2) / dir.y;
	hit.side = dir.x < 0 ? 3 : hit.side;
	hit.side = dir.y < 0 ? 4 : hit.side;
	draw_line(app, x, wall_dist, hit.side);
}

static void		render_view(t_app *app)
{
	t_vec2f		step;
	t_vec2f		start;
	t_vec2f		dir;
	int			x;
	int			nb_rays;

	nb_rays = app->size.x;
	step = ft_vec2f_scale(app->player.plane, (float)1 / (nb_rays - 1));
	start = ft_vec2f_sub(
			app->player.dir
			, ft_vec2f_scale(app->player.plane, 0.5));
	x = -1;
	dir = start;
	while (++x < nb_rays)
	{
		cast_ray(app, x, app->player.pos, dir);
		dir = ft_vec2f_add(dir, step);
	}
}

void			render(t_app *app)
{
	image_clear(app->draw_buf, 0x0);
	app->player.plane = ft_vec2f_rot(ft_vec2f_scale(app->player.dir, 2), M_PI / 2);
	render_view(app);
	mlx_put_image_to_window(app->mlx.core, app->mlx.win, app->draw_buf->image
			, 0, 0);
}
