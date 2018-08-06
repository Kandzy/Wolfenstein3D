/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 11:42:48 by dkliukin          #+#    #+#             */
/*   Updated: 2018/03/10 11:42:50 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		init_textures_part2(t_texur *tex, SDL_Surface *img)
{
	load_tex("textures/Bricks01.bmp", &tex[10], &img[10]);
	load_tex("textures/Bricks02.bmp", &tex[11], &img[11]);
	load_tex("textures/Bricks03.bmp", &tex[12], &img[12]);
	load_tex("textures/Bricks04.bmp", &tex[13], &img[13]);
	load_tex("textures/Bricks09.bmp", &tex[14], &img[14]);
	load_tex("textures/Bricks10.bmp", &tex[15], &img[15]);
	load_tex("textures/Bricks12.bmp", &tex[16], &img[16]);
	load_tex("textures/Bricks13.bmp", &tex[17], &img[17]);
	load_tex("textures/Bricks14.bmp", &tex[18], &img[18]);
	load_tex("textures/Rock01.bmp", &tex[19], &img[19]);
	load_tex("textures/Rock02.bmp", &tex[20], &img[20]);
	load_tex("textures/Woodlike01.bmp", &tex[21], &img[21]);
	load_tex("textures/Woodlike02.bmp", &tex[22], &img[22]);
	load_tex("textures/Woodlike03.bmp", &tex[23], &img[23]);
	load_tex("textures/Woodlike04.bmp", &tex[24], &img[24]);
	load_tex("textures/Woodlike05.bmp", &tex[25], &img[25]);
	load_tex("textures/WALL19.bmp", &tex[26], &img[26]);
	load_tex("textures/Woodlike07.bmp", &tex[27], &img[27]);
	load_tex("textures/Woodlike08.bmp", &tex[28], &img[28]);
	load_tex("textures/WALL57.bmp", &tex[29], &img[29]);
	load_tex("textures/WALL58.bmp", &tex[30], &img[30]);
	load_tex("textures/WALL32.bmp", &tex[31], &img[31]);
	load_tex("textures/WALL10.bmp", &tex[32], &img[32]);
	load_tex("textures/WALL11.bmp", &tex[33], &img[33]);
	load_tex("textures/WALL22.bmp", &tex[34], &img[34]);
}

static void		init_textures_part3(t_texur *tex, SDL_Surface *img)
{
	load_tex("textures/WALL63.bmp", &tex[35], &img[35]);
	load_tex("textures/WALL38.bmp", &tex[36], &img[36]);
	load_tex("textures/WALL34.bmp", &tex[37], &img[37]);
	load_tex("textures/WALL104.bmp", &tex[38], &img[38]);
	load_tex("textures/WALL67.bmp", &tex[39], &img[39]);
	load_tex("textures/WALL27.bmp", &tex[40], &img[40]);
	load_tex("textures/WALL69.bmp", &tex[41], &img[41]);
	load_tex("textures/WALL70.bmp", &tex[42], &img[42]);
	load_tex("textures/WALL71.bmp", &tex[43], &img[43]);
	load_tex("textures/WALL1.bmp", &tex[44], &img[44]);
	load_tex("textures/WALL89.bmp", &tex[45], &img[45]);
	load_tex("textures/WALL74.bmp", &tex[46], &img[46]);
	load_tex("textures/WALL0.bmp", &tex[47], &img[47]);
	load_tex("textures/WALL76.bmp", &tex[48], &img[48]);
	load_tex("textures/WALL77.bmp", &tex[49], &img[49]);
	load_tex("textures/WALL82.bmp", &tex[50], &img[50]);
	load_tex("textures/SKY.bmp", &tex[51], &img[51]);
	load_tex("textures/WALL88.bmp", &tex[52], &img[52]);
	load_tex("textures/WALL90.bmp", &tex[53], &img[53]);
	load_tex("textures/WALL92.bmp", &tex[54], &img[54]);
	load_tex("textures/WALL93.bmp", &tex[55], &img[55]);
	load_tex("textures/WALL31.bmp", &tex[56], &img[56]);
	load_tex("textures/WALL13.bmp", &tex[57], &img[57]);
	load_tex("textures/WALL14.bmp", &tex[58], &img[58]);
	load_tex("textures/WALL15.bmp", &tex[59], &img[59]);
}

void			init_textures(t_texur *tex, SDL_Surface *img)
{
	int			x;

	x = 0;
	while (x < TEX_AMOUNT)
	{
		tex[x].tex_pixels = (int*)malloc(sizeof(int) * 64 * 64);
		x++;
	}
	load_tex("textures/doyouknowdeway.bmp", &tex[0], &img[0]);
	load_tex("textures/001.bmp", &tex[1], &img[1]);
	load_tex("textures/002.bmp", &tex[2], &img[2]);
	load_tex("textures/003.bmp", &tex[3], &img[3]);
	load_tex("textures/005.bmp", &tex[4], &img[4]);
	load_tex("textures/Bricks12.bmp", &tex[5], &img[5]);
	load_tex("textures/Bricks05.bmp", &tex[6], &img[6]);
	load_tex("textures/WALL5.bmp", &tex[7], &img[7]);
	load_tex("textures/WALL3.bmp", &tex[8], &img[8]);
	load_tex("textures/WALL59.bmp", &tex[9], &img[9]);
	init_textures_part2(tex, img);
	init_textures_part3(tex, img);
}

void			game_init(t_window *win, t_level *level, t_texur *tex)
{
	win->sflag = SDL_WINDOW_FULLSCREEN_DESKTOP;
	screen_size(win);
	create_game_window(win);
	game_window(win, level, tex);
	SDL_RenderClear(win->ren);
	SDL_DestroyWindow(win->win);
	SDL_DestroyRenderer(win->ren);
}

int				init_level_texture(t_window *win, t_level *level,
									t_texur *tex, SDL_Surface *img)
{
	init_textures(tex, img);
	init_levels(level, NLVL);
	if (load_levels(level, NLVL) == -1)
		return (0);
	if (validate(level) == -1)
		return (0);
	if (sdl_initiate_all(win) != 0)
		return (0);
	return (1);
}
