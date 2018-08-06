/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_menu_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:35:01 by dkliukin          #+#    #+#             */
/*   Updated: 2018/01/30 15:35:02 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		load_menu_levels(t_window *win)
{
	int		i;
	char	*path;
	char	*level;

	i = 0;
	while (i < NLVL)
	{
		level = ft_itoa(i + 1);
		path = ft_strjoin("menu/level", level);
		ft_strdel(&level);
		level = ft_strjoin(path, ".bmp");
		ft_strdel(&path);
		win->menu.level[i].texture = load_texture(level, win->ren);
		if (win->menu.level[i].texture == NULL)
			ft_putendl("Menu texture error!\n");
		ft_strdel(&level);
		i++;
	}
}

void		load_options(t_window *win)
{
	win->menu.size[0].texture = load_texture("menu/1600x900.bmp", win->ren);
	if (win->menu.size[0].texture == NULL)
		ft_putendl("Menu texture error!\n");
	win->menu.size[1].texture = load_texture("menu/2048x1152.bmp", win->ren);
	if (win->menu.size[1].texture == NULL)
		ft_putendl("Menu texture error!\n");
	win->menu.size[2].texture = load_texture("menu/2560x1440.bmp", win->ren);
	if (win->menu.size[2].texture == NULL)
		ft_putendl("Menu texture error!\n");
	win->menu.size[3].texture = load_texture("menu/2880x1620.bmp", win->ren);
	if (win->menu.size[3].texture == NULL)
		ft_putendl("Menu texture error!\n");
	win->menu.size[4].texture = load_texture("menu/3200x1800.bmp", win->ren);
	if (win->menu.size[4].texture == NULL)
		ft_putendl("Menu texture error!\n");
}

void		load_menu_textures(t_window *win)
{
	win->menu.arrow.texture = load_texture("menu/arrow.bmp", win->ren);
	if (win->menu.arrow.texture == NULL)
		ft_putendl("Menu texture error!\n");
	win->menu.background.texture = load_texture("menu/menu.bmp", win->ren);
	if (win->menu.background.texture == NULL)
		ft_putendl("Menu texture error!\n");
	win->menu.new_game.texture = load_texture("menu/new_game.bmp", win->ren);
	if (win->menu.new_game.texture == NULL)
		ft_putendl("Menu texture error!\n");
	win->menu.options.texture = load_texture("menu/options.bmp", win->ren);
	if (win->menu.options.texture == NULL)
		ft_putendl("Menu texture error!\n");
	load_options(win);
	win->menu.exit_op.texture = load_texture("menu/exit.bmp", win->ren);
	if (win->menu.exit_op.texture == NULL)
		ft_putendl("Menu texture error!\n");
	win->menu.back.texture = load_texture("menu/back.bmp", win->ren);
	if (win->menu.back.texture == NULL)
		ft_putendl("Menu texture error!\n");
	win->menu.levels.texture = load_texture("menu/level.bmp", win->ren);
	if (win->menu.levels.texture == NULL)
		ft_putendl("Menu texture error!\n");
	load_menu_levels(win);
}
