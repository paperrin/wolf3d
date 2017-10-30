/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 21:15:40 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/30 07:27:18 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	event_key_toggle(int key, int state, void *param)
{
	t_app			*app;

	app = (t_app*)param;
	if (key == KC_A)
		app->player.left_pressed = state;
	if (key == KC_D)
		app->player.right_pressed = state;
	if (key == KC_W)
		app->player.up_pressed = state;
	if (key == KC_S)
		app->player.down_pressed = state;
}

int			event_key_press(int key, void *param)
{
	event_key_toggle(key, 1, param);
	return (0);
}

int			event_key_release(int key, void *param)
{
	t_app		*app;

	event_key_toggle(key, 0, param);
	app = (t_app*)param;
	if (key == KC_ESCAPE)
		destroy_app(app, EXIT_SUCCESS);
	return (0);
}

int			event_cross(void *param)
{
	t_app		*app;

	app = (t_app*)param;
	destroy_app(app, EXIT_SUCCESS);
	return (0);
}
