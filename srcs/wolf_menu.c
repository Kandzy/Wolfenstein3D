/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:29:46 by dkliukin          #+#    #+#             */
/*   Updated: 2018/01/29 12:29:47 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		display_menu(t_window *win, SDL_Event *ev)
{
	if (win->menu.status == ACTIVE)
	{
		if (ev->key.state == SDL_PRESSED && win->keystatus == 0)
		{
			menu_key_manip(win, *ev);
			win->keystatus = 15;
		}
		if (ev->type == SDL_MOUSEMOTION || (SDL_GetMouseState(NULL, NULL)
											& SDL_BUTTON(SDL_BUTTON_LEFT)))
			mouse_action(win, ev);
		wolf_menu(win);
	}
}

void		wolf_menu(t_window *win)
{
	SDL_Rect	background;

	background.x = 0;
	background.y = 0;
	background.h = win->height;
	background.w = win->width;
	SDL_RenderCopy(win->ren, win->menu.background.texture, NULL, &background);
	if (win->menu.section == 0)
	{
		win->menu.max_slot = SLOT_0_MAX;
		menu_button_position(win);
	}
	if (win->menu.section == 1)
	{
		win->menu.max_slot = SLOT_1_MAX;
		menu_section_2_position(win);
	}
	if (win->menu.section == 2)
	{
		win->menu.max_slot = SLOT_2_MAX;
		menu_section_3_position(win);
	}
}

static int	menu_level_slot(t_window *win)
{
	if (win->menu.section == 0)
	{
		main_section(win);
		if (win->exit_flag == FALSE)
			win->menu.slot = 0;
		return (1);
	}
	if (win->menu.section == 1)
	{
		level_section(win);
		if (win->exit_flag == FALSE)
			win->menu.slot = 0;
		return (1);
	}
	if (win->menu.section == 2)
	{
		options_section(win);
		if (win->exit_flag == FALSE)
			win->menu.slot = 0;
		return (1);
	}
	return (0);
}

void		menu_key_manip(t_window *win, SDL_Event ev)
{
	if (ev.key.keysym.sym == SDLK_DOWN && win->menu.slot < win->menu.max_slot)
		win->menu.slot++;
	if (ev.key.keysym.sym == SDLK_UP && win->menu.slot > 0)
		win->menu.slot--;
	if (ev.key.keysym.sym == SDLK_RETURN)
	{
		if (menu_level_slot(win) == 1)
			return ;
	}
}
