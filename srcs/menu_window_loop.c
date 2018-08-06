/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:02:18 by dkliukin          #+#    #+#             */
/*   Updated: 2018/02/02 15:02:20 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				quit_wolf(t_window *win, SDL_Event ev)
{
	if (ev.type == SDL_QUIT || (ev.type == SDL_KEYDOWN &&
		ev.key.keysym.sym == SDLK_ESCAPE) || win->exit_flag)
	{
		win->exit_flag = TRUE;
		return (1);
	}
	return (0);
}

void			menu_window(t_window *win)
{
	SDL_Event	ev;

	win->menu.slot = 0;
	win->exit_flag = FALSE;
	win->menu.section = 0;
	win->keystatus = 0;
	while (TRUE)
	{
		SDL_RenderClear(win->ren);
		if (win->keystatus > 0)
			win->keystatus--;
		SDL_PollEvent(&ev);
		display_menu(win, &ev);
		if (quit_wolf(win, ev) == TRUE)
			break ;
		if (win->menu.status == DISACTIVE)
			break ;
		SDL_RenderPresent(win->ren);
		SDL_GetWindowSize(win->win, &(win->width), &(win->height));
	}
}
