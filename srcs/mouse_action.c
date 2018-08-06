/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:03:05 by dkliukin          #+#    #+#             */
/*   Updated: 2018/02/01 19:03:06 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		mouse_action(t_window *win, SDL_Event *ev)
{
	if (win->menu.section == 0)
		mouse_action_section_0(win, ev);
	if (win->menu.section == 1)
		mouse_action_section_1(win, ev);
	if (win->menu.section == 2)
		mouse_action_section_2(win, ev);
}

void		mouse_action_section_0(t_window *win, SDL_Event *ev)
{
	int		pos_x;
	int		pos_y;

	pos_x = win->width / 2 - win->width / 22;
	pos_y = win->height / 2 + 20 - win->height / 4;
	if (ev->motion.x >= pos_x && ev->motion.x <= pos_x + win->width / 10)
	{
		if (ev->motion.y >= pos_y && ev->motion.y <= pos_y + win->height / 15)
			new_game_sec(win, ev);
		else if (ev->motion.y >= pos_y + win->height / 15 &&
					ev->motion.y <= pos_y + 2 * win->height / 15)
			level_sec(win, ev);
		else if (ev->motion.y >= pos_y + 2 * win->height / 15 &&
					ev->motion.y <= pos_y + win->height / 5)
			options_sec(win, ev);
		else if (ev->motion.y >= pos_y + win->height / 5 &&
					ev->motion.y <= pos_y + 4 * win->height / 15)
			exit_sec(win, ev);
	}
}

void		mouse_action_section_1(t_window *win, SDL_Event *ev)
{
	int		pos_x;
	int		pos_y;

	pos_x = win->width / 2 - win->width / 22;
	pos_y = win->height / 2 - win->height / 4;
	if (ev->motion.x >= pos_x && ev->motion.x <= pos_x + win->width / 10)
	{
		if (ev->motion.y > pos_y && ev->motion.y <= pos_y + 10 *
														win->height / 20)
			win->menu.slot = 9 - (10 * win->height / 20 -
							(ev->motion.y - pos_y)) / (win->height / 20);
		if (win->menu.slot == NLVL && ev->button.button == SDL_BUTTON_LEFT)
		{
			win->menu.slot = 0;
			win->menu.section = 0;
			ev->button.button = OFF;
		}
		else if (ev->button.button == SDL_BUTTON_LEFT)
		{
			win->lvl_id = win->menu.slot;
			ev->button.button = OFF;
			win->menu.status = DISACTIVE;
		}
	}
}

void		mouse_action_section_2(t_window *win, SDL_Event *ev)
{
	int		pos_x;
	int		pos_y;

	pos_x = win->width / 2 - win->width / 22;
	pos_y = win->height / 2 - win->height / 4;
	if (ev->motion.x >= pos_x && ev->motion.x <= pos_x + win->width / 10)
	{
		if (ev->motion.y > pos_y && ev->motion.y <=
											pos_y + 6 * win->height / 20)
			win->menu.slot = 5 - (6 * win->height / 20 -
						(ev->motion.y - pos_y)) / (win->height / 20);
		if (win->menu.slot == BACK_SLOT_3 &&
									ev->button.button == SDL_BUTTON_LEFT)
		{
			win->menu.slot = 0;
			win->menu.section = 0;
			ev->button.button = OFF;
		}
		else if (ev->button.button == SDL_BUTTON_LEFT)
		{
			win->resolution = win->menu.slot + 1;
			win->menu.section = 0;
			ev->button.button = OFF;
		}
	}
}
