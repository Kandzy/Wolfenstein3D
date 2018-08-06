/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_initiate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:21:55 by dkliukin          #+#    #+#             */
/*   Updated: 2018/01/25 16:21:56 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			player_initiate(t_game_win *gw)
{
	gw->pl.pos.x = 1.5;
	gw->pl.pos.y = 1.5;
	gw->pl.cam.plane.x = 0;
	gw->pl.cam.plane.y = 0.66;
	gw->pl.cam.dir.x = -1;
	gw->pl.cam.dir.y = 0;
	gw->pl.shift = 1;
}

void			create_game_window(t_window *win)
{
	win->win = SDL_CreateWindow("Wolfenstein 3D", SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, win->width, win->height, win->sflag);
	if (win->win == NULL)
	{
		ft_putendl(SDL_GetError());
		exit(0);
	}
	win->ren = SDL_CreateRenderer(win->win, -1, SDL_RENDERER_ACCELERATED |
	SDL_RENDERER_PRESENTVSYNC);
	if (win->ren == NULL)
	{
		ft_putendl(SDL_GetError());
		exit(0);
	}
}

int				sdl_initiate_all(t_window *win)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		ft_putendl(SDL_GetError());
		return (1);
	}
	default_display_option(win);
	win->win = SDL_CreateWindow("Wolfenstein 3D", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 1366, 768, win->sflag);
	if (win->win == NULL)
	{
		ft_putendl(SDL_GetError());
		return (2);
	}
	win->ren = SDL_CreateRenderer(win->win, -1, SDL_RENDERER_ACCELERATED |
	SDL_RENDERER_PRESENTVSYNC);
	if (win->ren == NULL)
	{
		ft_putendl(SDL_GetError());
		return (3);
	}
	return (0);
}
