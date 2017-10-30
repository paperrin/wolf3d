/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:32:48 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/30 08:27:16 by paperrin         ###   ########.fr       */
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
	app->player.pos = ft_vec2f(5.5, 5.5);
	app->player.dir = ft_vec2f_rot(ft_vec2f(1, 0), 0);
	app->player.left_pressed = 0;
	app->player.right_pressed = 0;
	app->player.up_pressed = 0;
	app->player.down_pressed = 0;
}

int				main(void)
{
	t_app	app;

	if (!create_app(&app, 1600, 900, "Wolf3D papabgrall"))
		return (EXIT_FAILURE);
	if (!map_load(&app.map))
		destroy_app(&app, EXIT_FAILURE);
	init_player(&app);
	render(&app);
	mlx_loop_hook(app.mlx.core, &render, &app);
	mlx_hook(app.mlx.win, X11_KEY_PRESS, 0, &event_key_press, &app);
	mlx_hook(app.mlx.win, X11_KEY_RELEASE, 0, &event_key_release, &app);
	mlx_hook(app.mlx.win, X11_DESTROY_NOTIFY, 0, &event_cross, &app);
	mlx_loop(app.mlx.core);
	return (EXIT_SUCCESS);
}
