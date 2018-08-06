/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:30:46 by dkliukin          #+#    #+#             */
/*   Updated: 2018/01/24 15:30:47 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

SDL_Texture		*load_texture(char *file, SDL_Renderer *ren)
{
	SDL_Surface *image;
	SDL_Texture *texture;

	image = SDL_LoadBMP(file);
	texture = NULL;
	if (image != NULL)
	{
		texture = SDL_CreateTextureFromSurface(ren, image);
		SDL_FreeSurface(image);
	}
	else
		ft_putendl(SDL_GetError());
	return (texture);
}

void			open_image(SDL_Surface *image)
{
	if (image == NULL)
	{
		ft_putendl(SDL_GetError());
		exit(0);
	}
}

void			load_tex(char *filename, t_texur *tex, SDL_Surface *image)
{
	int			x;
	int			y;
	SDL_Surface	*img;

	image = SDL_LoadBMP(filename);
	open_image(image);
	img = SDL_ConvertSurfaceFormat(image, SDL_PIXELFORMAT_ARGB8888, 0);
	SDL_FreeSurface(image);
	image = img;
	SDL_LockSurface(image);
	x = 0;
	while (x < 64)
	{
		y = 0;
		while (y < 64)
		{
			tex->tex_pixels[64 * y + x] = ((int *)image->pixels)[64 * y + x];
			y++;
		}
		x++;
	}
	SDL_UnlockSurface(image);
	SDL_FreeSurface(image);
}
