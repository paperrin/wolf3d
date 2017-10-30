/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 07:22:53 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/30 07:27:02 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	player_update(t_app *app)
{
	const float		rot_val = M_PI / 90;
	t_vec2f			forward;

	forward = ft_vec2f_scale(app->player.dir, 0.05);
	if (app->player.left_pressed)
		app->player.dir = ft_vec2f_rot(app->player.dir, -rot_val);
	if (app->player.right_pressed)
		app->player.dir = ft_vec2f_rot(app->player.dir, rot_val);
	if (app->player.up_pressed)
		app->player.pos = ft_vec2f_add(app->player.pos, forward);
	if (app->player.down_pressed)
		app->player.pos = ft_vec2f_sub(app->player.pos, forward);
	app->player.plane = ft_vec2f_rot(ft_vec2f_scale(app->player.dir, 2)
			, M_PI / 2);
}
