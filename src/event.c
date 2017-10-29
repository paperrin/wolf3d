/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 21:15:40 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/29 21:31:09 by paperrin         ###   ########.fr       */
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
	t_app	*app;

	(void)key;
	app = (t_app*)param;
	return (0);
}

int			event_cross(void *param)
{
	t_app		*app;

	app = (t_app*)param;
	destroy_app(app, EXIT_SUCCESS);
	return (0);
}
