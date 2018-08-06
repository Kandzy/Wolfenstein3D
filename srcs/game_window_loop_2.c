/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_window_loop_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 12:18:03 by dkliukin          #+#    #+#             */
/*   Updated: 2018/03/10 12:18:05 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		floor_params(t_game_win *gw)
{
	if (gw->wtex.side == 0 && gw->ray.dirx > 0)
	{
		gw->floortex.poswall.x = gw->map.x;
		gw->floortex.poswall.y = gw->map.y + gw->wtex.wall_x;
	}
	else if (gw->wtex.side == 0 && gw->ray.dirx < 0)
	{
		gw->floortex.poswall.x = gw->map.x + 1.0;
		gw->floortex.poswall.y = gw->map.y + gw->wtex.wall_x;
	}
	else if (gw->wtex.side == 1 && gw->ray.diry > 0)
	{
		gw->floortex.poswall.x = gw->map.x + gw->wtex.wall_x;
		gw->floortex.poswall.y = gw->map.y;
	}
	else
	{
		gw->floortex.poswall.x = gw->map.x + gw->wtex.wall_x;
		gw->floortex.poswall.y = gw->map.y + 1.0;
	}
}

void			display_floor(t_game_win *gw, t_window *win,
										t_texur *tex, int x)
{
	int		y;

	floor_params(gw);
	gw->floortex.dist.wall = gw->wtex.wall_dist;
	gw->floortex.dist.player = 0.0;
	if (gw->ray.dend < 0)
		gw->ray.dend = win->height;
	y = gw->ray.dend;
	while (++y < win->height)
	{
		gw->floortex.dist.current = win->height / (2.0 * y - win->height);
		gw->floortex.leng = (gw->floortex.dist.current -
		gw->floortex.dist.player) / (gw->floortex.dist.wall -
		gw->floortex.dist.player);
		gw->floortex.curr_pos.x = gw->floortex.leng * gw->floortex.poswall.x +
		(1.0 - gw->floortex.leng) * gw->pl.pos.x;
		gw->floortex.curr_pos.y = gw->floortex.leng * gw->floortex.poswall.y +
		(1.0 - gw->floortex.leng) * gw->pl.pos.y;
		gw->floortex.ftex_x = (int)(gw->floortex.curr_pos.x * TEXW) % TEXW;
		gw->floortex.ftex_y = (int)(gw->floortex.curr_pos.y * TEXH) % TEXH;
		pixel_put(&gw->pl.cam, x, y, tex[2].tex_pixels[64 *
		(int)gw->floortex.ftex_y + (int)gw->floortex.ftex_x]);
		pixel_put(&gw->pl.cam, x, win->height - y, tex[51].tex_pixels[64 *
		(int)gw->floortex.ftex_y + gw->floortex.ftex_x]);
	}
}

static void		frametime_speed(t_game_win *gw)
{
	gw->frametime.end = gw->frametime.start;
	gw->frametime.start = SDL_GetTicks();
	gw->frametime.ftime = (gw->frametime.start - gw->frametime.end) / 1000;
	gw->pl.movespeed = gw->frametime.ftime * 5.0 * gw->pl.shift;
	gw->pl.rotspeed = gw->frametime.ftime * 3;
}

void			loop(t_game_win *gw, t_window *win, t_texur *tex, int x)
{
	init_ray(gw, *win, x);
	steps_calc(gw);
	wall_hit(gw, win->current_map);
	draw_parametrs(gw, win);
	display_textures(gw, win, tex, x);
	display_floor(gw, win, tex, x);
}

void			present_frame(t_game_win *gw, t_window *win, SDL_Rect *pos)
{
	SDL_UpdateTexture(gw->pl.cam.vision, NULL,
	gw->pl.cam.pixels, win->width * 4);
	SDL_RenderCopy(win->ren, gw->pl.cam.vision, NULL, pos);
	frametime_speed(gw);
	SDL_RenderPresent(win->ren);
}
