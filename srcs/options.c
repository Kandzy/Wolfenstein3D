/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:29:33 by dkliukin          #+#    #+#             */
/*   Updated: 2018/01/25 14:29:34 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

char			*map_path(char *a, char *b)
{
	char		*ret;

	ret = ft_strjoin(a, b);
	ft_strdel(&b);
	return (ret);
}

void			default_display_option(t_window *win)
{
	win->resolution = 4;
	win->menu.status = ACTIVE;
	win->lvl_id = 0;
	win->sflag = SDL_WINDOW_RESIZABLE;
}

void			screen_size(t_window *win)
{
	if (win->resolution == 1)
	{
		win->width = 1600;
		win->height = 900;
	}
	if (win->resolution == 2)
	{
		win->width = 2048;
		win->height = 1152;
	}
	if (win->resolution == 3)
	{
		win->width = 2560;
		win->height = 1440;
	}
	if (win->resolution == 4)
	{
		win->width = 2880;
		win->height = 1620;
	}
	if (win->resolution == 5)
	{
		win->width = 3200;
		win->height = 1800;
	}
}
