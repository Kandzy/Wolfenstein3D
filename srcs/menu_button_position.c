/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_button_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:36:58 by dkliukin          #+#    #+#             */
/*   Updated: 2018/01/30 15:36:59 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		position(int x, int y, t_textures tex, t_window *win)
{
	SDL_Rect	pos;

	pos.x = x;
	pos.y = y;
	SDL_QueryTexture(tex.texture, NULL, NULL, &pos.w, &pos.h);
	pos.h = win->height / 15;
	pos.w = win->width / 10;
	SDL_RenderCopy(win->ren, tex.texture, NULL, &pos);
}

void		menu_button_position(t_window *win)
{
	int		pos_x;
	int		pos_y;
	int		n;

	n = win->menu.slot;
	pos_x = win->width / 2 - win->width / 22;
	pos_y = win->height / 2 + 20 - win->height / 4;
	position(pos_x - win->width / 10, pos_y + win->height / 15 * n,
	win->menu.arrow, win);
	position(pos_x, pos_y, win->menu.new_game, win);
	position(pos_x, pos_y + win->height / 15, win->menu.levels, win);
	position(pos_x, pos_y + 2 * win->height / 15, win->menu.options, win);
	position(pos_x, pos_y + 3 * win->height / 15, win->menu.exit_op, win);
}

void		menu_section_2_position(t_window *win)
{
	int		pos_x;
	int		pos_y;
	int		n;
	int		nlvl;

	n = win->menu.slot;
	pos_x = win->width / 2 - win->width / 22;
	pos_y = win->height / 2 - win->height / 4;
	position(pos_x - win->width / 10, pos_y + win->height / 20 * n,
	win->menu.arrow, win);
	nlvl = 0;
	while (nlvl < NLVL)
	{
		position(pos_x, pos_y + win->height / 20 * nlvl,
		win->menu.level[nlvl], win);
		nlvl++;
	}
	position(pos_x, pos_y + win->height / 20 * nlvl, win->menu.back, win);
}

void		menu_section_3_position(t_window *win)
{
	int		pos_x;
	int		pos_y;
	int		n;
	int		nsize;

	n = win->menu.slot;
	pos_x = win->width / 2 - win->width / 22;
	pos_y = win->height / 2 - win->height / 4;
	position(pos_x - win->width / 10, pos_y + win->height / 20 * n,
	win->menu.arrow, win);
	nsize = 0;
	while (nsize < 5)
	{
		position(pos_x, pos_y + win->height / 20 * nsize,
		win->menu.size[nsize], win);
		nsize++;
	}
	position(pos_x, pos_y + win->height / 20 * nsize, win->menu.back, win);
}
