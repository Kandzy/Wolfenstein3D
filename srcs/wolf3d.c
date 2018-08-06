/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:20:18 by dkliukin          #+#    #+#             */
/*   Updated: 2018/01/25 16:20:20 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			exit_points(t_level *lvl)
{
	lvl[0].exitx = 11;
	lvl[0].exity = 15;
	lvl[1].exitx = 43;
	lvl[1].exity = 61;
	lvl[2].exitx = 15;
	lvl[2].exity = 37;
	lvl[3].exitx = 87;
	lvl[3].exity = 1;
	lvl[4].exitx = 101;
	lvl[4].exity = 5;
	lvl[5].exitx = 108;
	lvl[5].exity = 1;
	lvl[6].exitx = 25;
	lvl[6].exity = 10;
	lvl[7].exitx = 17;
	lvl[7].exity = 21;
}

void			init_levels(t_level *lvl, int amount_of_lvl)
{
	int			i;

	i = 0;
	while (i < amount_of_lvl)
	{
		lvl[i].lvl_id = i + 1;
		lvl[i].str_map = NULL;
		lvl[i].map = 0;
		lvl[i].map_width = 0;
		lvl[i].map_height = 0;
		lvl[i].posx = 1;
		lvl[i].posy = 1;
		i++;
	}
	exit_points(lvl);
}

int				load_levels(t_level *level, int amount_of_lvl)
{
	int			fd;
	char		*lvlname;
	int			i;

	fd = open("maps/levels", O_RDONLY);
	if (fd < 0)
	{
		ft_putendl("File lost: maps/levels\n");
		return (-1);
	}
	i = 0;
	while (i < amount_of_lvl)
	{
		get_next_line(fd, &lvlname);
		lvlname = map_path("maps/", lvlname);
		read_level(lvlname, &level[i]);
		ft_strdel(&lvlname);
		i++;
	}
	close(fd);
	return (0);
}

void			destroy_all(t_window *win)
{
	int		i;

	i = 0;
	SDL_DestroyTexture(win->menu.arrow.texture);
	SDL_DestroyTexture(win->menu.background.texture);
	SDL_DestroyTexture(win->menu.back.texture);
	SDL_DestroyTexture(win->menu.new_game.texture);
	SDL_DestroyTexture(win->menu.options.texture);
	SDL_DestroyTexture(win->menu.exit_op.texture);
	SDL_DestroyTexture(win->menu.levels.texture);
	while (i < NLVL)
	{
		SDL_DestroyTexture(win->menu.level[i].texture);
		if (i < 5)
			SDL_DestroyTexture(win->menu.size[i].texture);
		i++;
	}
	SDL_RenderClear(win->ren);
	SDL_DestroyRenderer(win->ren);
	SDL_DestroyWindow(win->win);
}

int				main(void)
{
	t_window	win;
	t_level		level[NLVL];
	t_texur		*tex;
	SDL_Surface	img[TEX_AMOUNT];

	tex = (t_texur*)malloc(sizeof(t_texur) * TEX_AMOUNT);
	if (init_level_texture(&win, level, tex, img) == 0)
		return (0);
	load_menu_textures(&win);
	SDL_RenderClear(win.ren);
	menu_window(&win);
	SDL_DestroyWindow(win.win);
	SDL_DestroyRenderer(win.ren);
	if (win.exit_flag == FALSE)
		game_init(&win, level, tex);
	win.i = 0;
	while (win.i < TEX_AMOUNT)
	{
		free(tex[win.i].tex_pixels);
		SDL_FreeSurface(img);
		win.i++;
	}
	atexit(SDL_Quit);
	return (0);
}
