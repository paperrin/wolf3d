/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 21:15:40 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/30 03:58:45 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			event_key_release(int key, void *param)
{
	t_app		*app;

	app = (t_app*)param;
	if (key == KC_ESCAPE)
		destroy_app(app, EXIT_SUCCESS);
	return (0);
}

int			event_key_down(int key, void *param)
{
	t_app			*app;
	const float		rot_val = M_PI / 90;
	t_vec2f			forward;

	app = (t_app*)param;
	forward = ft_vec2f_scale(app->player.dir, 0.05);
	if (key == KC_A)
		app->player.dir = ft_vec2f_rot(app->player.dir, -rot_val);
	else if (key == KC_D)
		app->player.dir = ft_vec2f_rot(app->player.dir, rot_val);
	else if (key == KC_W)
		app->player.pos = ft_vec2f_add(app->player.pos, forward);
	else if (key == KC_S)
		app->player.pos = ft_vec2f_sub(app->player.pos, forward);
	render(app);
	return (0);
}

int			event_cross(void *param)
{
	t_app		*app;

	app = (t_app*)param;
	destroy_app(app, EXIT_SUCCESS);
	return (0);
}
