/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 21:59:54 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/29 23:09:29 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		cast_ray(t_app *app, int x, t_vec2f orig, t_vec2f dir)
{

}

static void		render_view(t_app *app)
{
	t_vec2f		step;
	t_vec2f		start;
	t_vec2f		dir;
	int			x;

	step = ft_vec2f_scale(app->player.plane, 1 / app->size.x);
	start = ft_vec2f_sub(
			ft_vec2f_add(app->player.pos, app->player.dir)
			, ft_vec2f_scale(app->player.plane, 0.5));
	x = -1;
	dir = start;
	while (++x < app->size.x)
	{
		cast_ray(app, x, app->player.pos, dir);
		dir = ft_vec2f_add(dir, step);
	}
}

void			render(t_app *app)
{
	//image_put_pixel(app->draw_buf, ft_vec3f(10, 10, 0), 0xFF0000);
	render_view(app);
	mlx_put_image_to_window(app->mlx.core, app->mlx.win, app->draw_buf->image
			, 0, 0);
}
