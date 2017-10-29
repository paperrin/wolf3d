/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:32:48 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/29 23:08:37 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		create_app(t_app *app, size_t width, size_t height
		, char *title)
{
	app->mlx.core = NULL;
	app->mlx.win = NULL;
	app->draw_buf = NULL;
	app->size = ft_vec2i(width, height);
	if (!(app->mlx.core = mlx_init()))
		return (0);
	if (!(app->mlx.win = mlx_new_window(app->mlx.core
			, width, height, title)))
		return (0);
	if (!(app->draw_buf = image_new(app->mlx.core, width, height)))
		destroy_app(app, EXIT_FAILURE);
	app->draw_buf->pixels = mlx_get_data_addr(
			app->draw_buf->image
			, &app->draw_buf->bits_per_pixel
			, &app->draw_buf->bytes_width
			, &app->draw_buf->is_big_endian);
	return (1);
}

void			destroy_app(t_app *app, int exit_code)
{
	image_free(app->mlx.core, &app->draw_buf);
	mlx_destroy_window(app->mlx.core, app->mlx.win);
	exit(exit_code);
}

static void		init_player(t_app *app)
{
	app->player.pos = ft_vec2f((float)app->map.size.x / 2
			, (float)app->map.size.y / 2);
	app->player.dir = ft_vec2f_rot(ft_vec2f(0, 1), M_PI / 4);
	app->player.plane = ft_vec2f_rot(app->player.dir, M_PI / 2);
}

int		main(int ac, char **av)
{
	t_app	app;

	(void)ac;
	(void)av;
	if (!create_app(&app, 1200, 700, "Fract'ol paperrin"))
		return (EXIT_FAILURE);
	if (!map_load(&app.map))
		destroy_app(&app, EXIT_FAILURE);
	init_player(&app);
	render(&app);
	mlx_hook(app.mlx.win, X11_KEY_PRESS, 0, &event_key_down, &app);
	mlx_hook(app.mlx.win, X11_KEY_RELEASE, 0, &event_key_release, &app);
	mlx_hook(app.mlx.win, X11_DESTROY_NOTIFY, 0, &event_cross, &app);
	mlx_loop(app.mlx.core);
	return (EXIT_SUCCESS);
}
