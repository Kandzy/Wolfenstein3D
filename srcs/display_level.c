/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_level.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 18:30:31 by dkliukin          #+#    #+#             */
/*   Updated: 2018/02/14 18:30:33 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			init_ray(t_game_win *gw, t_window win, int x)
{
	gw->pl.cam.x = 2 * x / (double)(win.width) - 1;
	gw->ray.dirx = gw->pl.cam.dir.x + gw->pl.cam.plane.x * gw->pl.cam.x;
	gw->ray.diry = gw->pl.cam.dir.y + gw->pl.cam.plane.y * gw->pl.cam.x;
	if (gw->ray.diry == 0)
		gw->ray.diry = 0.00000001;
	gw->map.x = (int)gw->pl.pos.x;
	gw->map.y = (int)gw->pl.pos.y;
	gw->map.dx = sqrt(1 + (gw->ray.diry * gw->ray.diry) /
	(gw->ray.dirx * gw->ray.dirx));
	gw->map.dy = sqrt(1 + (gw->ray.dirx * gw->ray.dirx) /
	(gw->ray.diry * gw->ray.diry));
	gw->wtex.hit = 0;
}

void			steps_calc(t_game_win *gw)
{
	if (gw->ray.dirx < 0)
	{
		gw->map.stepx = -1;
		gw->ray.side.dist.x = (gw->pl.pos.x - gw->map.x) *
		gw->map.dx;
	}
	else
	{
		gw->map.stepx = 1;
		gw->ray.side.dist.x = (gw->map.x + 1.0 - gw->pl.pos.x) *
		gw->map.dx;
	}
	if (gw->ray.diry < 0)
	{
		gw->map.stepy = -1;
		gw->ray.side.dist.y = (gw->pl.pos.y - gw->map.y) *
		gw->map.dy;
	}
	else
	{
		gw->map.stepy = 1;
		gw->ray.side.dist.y = (gw->map.y + 1.0 - gw->pl.pos.y) *
		gw->map.dy;
	}
}

void			wall_hit(t_game_win *gw, int **map)
{
	while (gw->wtex.hit == 0)
	{
		if (gw->ray.side.dist.x < gw->ray.side.dist.y)
		{
			gw->ray.side.dist.x += gw->map.dx;
			gw->map.x += gw->map.stepx;
			gw->wtex.side = 0;
		}
		else
		{
			gw->ray.side.dist.y += gw->map.dy;
			gw->map.y += gw->map.stepy;
			gw->wtex.side = 1;
		}
		if (map[gw->map.x][gw->map.y] > 0)
			gw->wtex.hit = 1;
	}
}

void			draw_parametrs(t_game_win *gw, t_window *win)
{
	if (gw->wtex.side == 0)
	{
		gw->wtex.wall_dist = (gw->map.x - gw->pl.pos.x +
		(1 - gw->map.stepx) / 2) / gw->ray.dirx;
	}
	else
	{
		gw->wtex.wall_dist = (gw->map.y - gw->pl.pos.y +
		(1 - gw->map.stepy) / 2) / gw->ray.diry;
	}
	gw->wtex.linehe = (int)(win->height / gw->wtex.wall_dist);
	gw->ray.dstart = -(gw->wtex.linehe) / 2 + win->height / 2;
	if (gw->ray.dstart < 0)
		gw->ray.dstart = 0;
	gw->ray.dend = gw->wtex.linehe / 2 + win->height / 2;
	if (gw->ray.dend >= win->height)
		gw->ray.dend = win->height - 1;
}

void			choose_color(t_game_win *gw, t_window *win)
{
	if (win->current_map[gw->map.x][gw->map.y] == 1)
		gw->wtex.color = 0xFF0000;
	else if (win->current_map[gw->map.x][gw->map.y] == 2)
		gw->wtex.color = 0x00FF00;
	else if (win->current_map[gw->map.x][gw->map.y] == 3)
		gw->wtex.color = 0x0000FF;
	else if (win->current_map[gw->map.x][gw->map.y] == 4)
		gw->wtex.color = 0xFFFFFF;
	else
		gw->wtex.color = 0xFFFF00;
	if (gw->wtex.side == 1)
		gw->wtex.color = gw->wtex.color / 2;
}
