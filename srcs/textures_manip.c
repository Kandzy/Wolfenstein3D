/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_manip.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:30:53 by dkliukin          #+#    #+#             */
/*   Updated: 2018/02/18 16:30:56 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			create_texture(t_window win, t_camera *cam, SDL_Rect *pos)
{
	cam->vision = SDL_CreateTexture(win.ren, SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING, win.width, win.height);
	cam->tex_h = win.height;
	cam->tex_w = win.width;
	pos->x = 0;
	pos->y = 0;
	pos->h = win.height;
	pos->w = win.width;
	cam->pixels = (int*)ft_memalloc(sizeof(int) * win.height * win.width);
}

void			pixel_put(t_camera *cam, int x, int y, int color)
{
	cam->pixels[y * cam->tex_w + x] = color;
}

void			draw_line(t_game_win gw, t_camera *cam, int x, int color)
{
	int		y;

	y = gw.ray.dstart;
	while (y < gw.ray.dend)
	{
		pixel_put(cam, x, y, color);
		y++;
	}
}

void			vertical_line(t_game_win *gw, int x)
{
	draw_line(*gw, &(gw->pl.cam), x, gw->wtex.color);
}
