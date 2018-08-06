/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_action_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 12:39:32 by dkliukin          #+#    #+#             */
/*   Updated: 2018/03/10 12:39:33 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		new_game_sec(t_window *win, SDL_Event *ev)
{
	win->menu.slot = 0;
	if (ev->button.button == SDL_BUTTON_LEFT)
	{
		win->menu.status = DISACTIVE;
		ev->button.button = OFF;
	}
}

void		level_sec(t_window *win, SDL_Event *ev)
{
	win->menu.slot = 1;
	if (ev->button.button == SDL_BUTTON_LEFT)
	{
		win->menu.section = 1;
		ev->button.button = OFF;
	}
}

void		options_sec(t_window *win, SDL_Event *ev)
{
	win->menu.slot = 2;
	if (ev->button.button == SDL_BUTTON_LEFT)
	{
		win->menu.section = 2;
		ev->button.button = OFF;
	}
}

void		exit_sec(t_window *win, SDL_Event *ev)
{
	win->menu.slot = 3;
	if (ev->button.button == SDL_BUTTON_LEFT)
		win->exit_flag = TRUE;
}
