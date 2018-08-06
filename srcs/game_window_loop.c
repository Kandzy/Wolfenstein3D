/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_window_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:34:46 by dkliukin          #+#    #+#             */
/*   Updated: 2018/02/22 14:34:48 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				**wolf_level_map(t_level *level)
{
	int		**map;
	int		width;
	int		height;
	int		count;

	map = (int**)malloc(sizeof(int*) * level->map_height);
	height = 0;
	count = 0;
	while (height < level->map_height)
	{
		map[height] = (int*)malloc(sizeof(int) * level->map_width);
		width = 0;
		while (count < level->map_width * height + level->map_width)
		{
			map[height][width] = level->map[count];
			width++;
			count++;
		}
		height++;
	}
	return (map);
}

void			display_textures(t_game_win *gw, t_window *win,
											t_texur *tex, int x)
{
	int			d;
	int			y;

	gw->wtex.tex_num = win->current_map[gw->map.x][gw->map.y] - 1;
	if (gw->wtex.side == 0)
		gw->wtex.wall_x = gw->pl.pos.y + gw->wtex.wall_dist * gw->ray.diry;
	else
		gw->wtex.wall_x = gw->pl.pos.x + gw->wtex.wall_dist * gw->ray.dirx;
	gw->wtex.wall_x -= floor(gw->wtex.wall_x);
	gw->wtex.tex_x = (int)(gw->wtex.wall_x * (double)TEXW);
	if (gw->wtex.side == 0 && gw->ray.dirx > 0)
		gw->wtex.tex_x = TEXW - gw->wtex.tex_x - 1;
	if (gw->wtex.side == 1 && gw->ray.diry < 0)
		gw->wtex.tex_x = TEXW - gw->wtex.tex_x - 1;
	y = gw->ray.dstart - 1;
	while (++y < gw->ray.dend)
	{
		d = y * 256 - win->height * 128 + gw->wtex.linehe * 128;
		gw->wtex.tex_y = ((d * TEXH) / gw->wtex.linehe) / 256;
		gw->wtex.color = tex[gw->wtex.tex_num].tex_pixels[TEXH *
		gw->wtex.tex_y + gw->wtex.tex_x];
		if (gw->wtex.side == 1)
			gw->wtex.color = (gw->wtex.color >> 1) & 8355711;
		pixel_put(&gw->pl.cam, x, y, gw->wtex.color);
	}
}

void			next_level(t_level *level, t_game_win *gw, t_window *win)
{
	int			y;

	if (level[win->lvl_id].exitx < gw->pl.pos.x &&
		level[win->lvl_id].exitx + 1 > gw->pl.pos.x &&
		level[win->lvl_id].exity < gw->pl.pos.y &&
		level[win->lvl_id].exity + 1 > gw->pl.pos.y)
	{
		gw->pl.pos.x = 1.5;
		gw->pl.pos.y = 1.5;
		y = -1;
		while (++y < level[win->lvl_id].map_height)
			free(win->current_map[y]);
		free(win->current_map);
		win->lvl_id++;
		win->current_map = wolf_level_map(&level[win->lvl_id]);
	}
}

void			game_window(t_window *win, t_level *level, t_texur *tex)
{
	SDL_Event	ev;
	t_game_win	gw;
	int			x;
	SDL_Rect	pos;

	create_texture(*win, &gw.pl.cam, &pos);
	player_initiate(&gw);
	gw.frametime.start = 0;
	win->current_map = wolf_level_map(&level[win->lvl_id]);
	while (TRUE)
	{
		SDL_RenderClear(win->ren);
		SDL_PollEvent(&ev);
		gw.keystate = SDL_GetKeyboardState(NULL);
		x = -1;
		while (++x < win->width)
			loop(&gw, win, tex, x);
		present_frame(&gw, win, &pos);
		if (quit_wolf(win, ev) == TRUE)
			break ;
		key_event(win, &gw, &ev);
		next_level(level, &gw, win);
	}
	free(gw.pl.cam.pixels);
	SDL_DestroyTexture(gw.pl.cam.vision);
}
