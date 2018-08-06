/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:18:13 by dkliukin          #+#    #+#             */
/*   Updated: 2018/01/25 16:18:14 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	key_w(t_window *win, t_game_win *gw)
{
	if (win->current_map[(int)(gw->pl.pos.x + gw->pl.cam.dir.x *
			gw->pl.movespeed)][(int)(gw->pl.pos.y)] == FALSE)
		gw->pl.pos.x += gw->pl.cam.dir.x * gw->pl.movespeed;
	if (win->current_map[(int)(gw->pl.pos.x)][(int)(gw->pl.pos.y +
			gw->pl.cam.dir.y * gw->pl.movespeed)] == FALSE)
		gw->pl.pos.y += gw->pl.cam.dir.y * gw->pl.movespeed;
}

void	key_s(t_window *win, t_game_win *gw)
{
	if (win->current_map[(int)(gw->pl.pos.x - gw->pl.cam.dir.x *
			gw->pl.movespeed)][(int)(gw->pl.pos.y)] == FALSE)
		gw->pl.pos.x -= gw->pl.cam.dir.x * gw->pl.movespeed;
	if (win->current_map[(int)(gw->pl.pos.x)][(int)(gw->pl.pos.y -
			gw->pl.cam.dir.y * gw->pl.movespeed)] == FALSE)
		gw->pl.pos.y -= gw->pl.cam.dir.y * gw->pl.movespeed;
}

void	key_a(t_game_win *gw)
{
	double tmpdx;
	double tmppx;

	tmpdx = gw->pl.cam.dir.x;
	gw->pl.cam.dir.x = gw->pl.cam.dir.x * cos(gw->pl.rotspeed) -
						gw->pl.cam.dir.y * sin(gw->pl.rotspeed);
	gw->pl.cam.dir.y = tmpdx * sin(gw->pl.rotspeed) +
						gw->pl.cam.dir.y * cos(gw->pl.rotspeed);
	tmppx = gw->pl.cam.plane.x;
	gw->pl.cam.plane.x = gw->pl.cam.plane.x * cos(gw->pl.rotspeed) -
						gw->pl.cam.plane.y * sin(gw->pl.rotspeed);
	gw->pl.cam.plane.y = tmppx * sin(gw->pl.rotspeed) +
						gw->pl.cam.plane.y * cos(gw->pl.rotspeed);
}

void	key_d(t_game_win *gw)
{
	double tmpdx;
	double tmppx;

	tmpdx = gw->pl.cam.dir.x;
	gw->pl.cam.dir.x = gw->pl.cam.dir.x * cos(-gw->pl.rotspeed) -
						gw->pl.cam.dir.y * sin(-gw->pl.rotspeed);
	gw->pl.cam.dir.y = tmpdx * sin(-gw->pl.rotspeed) +
						gw->pl.cam.dir.y * cos(-gw->pl.rotspeed);
	tmppx = gw->pl.cam.plane.x;
	gw->pl.cam.plane.x = gw->pl.cam.plane.x * cos(-gw->pl.rotspeed) -
						gw->pl.cam.plane.y * sin(-gw->pl.rotspeed);
	gw->pl.cam.plane.y = tmppx * sin(-gw->pl.rotspeed) +
						gw->pl.cam.plane.y * cos(-gw->pl.rotspeed);
}

void	key_event(t_window *win, t_game_win *gw, SDL_Event *ev)
{
	int		i;

	i = 0;
	ev->key.keysym.sym = 0;
	if (gw->keystate[SDL_SCANCODE_W])
		key_w(win, gw);
	if (gw->keystate[SDL_SCANCODE_S])
		key_s(win, gw);
	if (gw->keystate[SDL_SCANCODE_A])
		key_a(gw);
	if (gw->keystate[SDL_SCANCODE_D])
		key_d(gw);
	if (gw->keystate[SDL_SCANCODE_LSHIFT])
		gw->pl.shift = 2;
	else
		gw->pl.shift = 1;
	if (gw->keystate[SDL_SCANCODE_W] || gw->keystate[SDL_SCANCODE_S] ||
				gw->keystate[SDL_SCANCODE_D] || gw->keystate[SDL_SCANCODE_A])
	{
		while (i < win->height * win->width)
		{
			gw->pl.cam.pixels[i] = 0;
			i++;
		}
	}
}
