/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 12:25:53 by dkliukin          #+#    #+#             */
/*   Updated: 2018/03/10 12:25:55 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		error_msg(t_level *level)
{
	ft_putstr("Wrong texture on map.\nCheck your input\nLevel ID: ");
	ft_putnbr(level->lvl_id);
}

static void		check_inmap_tex(t_level *level, int x, int y)
{
	if (x > 0 && x < level->map_width - 1 && y > 0 && y < level->map_height - 1)
	{
		if (level->map[y * level->map_width + x] < 0 ||
		level->map[y * level->map_width + x] > TEX_AMOUNT)
		{
			error_msg(level);
			exit(0);
		}
	}
}

void			texture_value(char *strtext, t_level *level, int x, int y)
{
	if (y == 0 && x == 0)
		level->map = (int*)ft_memalloc(sizeof(int) *
		level->map_height * level->map_width);
	level->map[y * level->map_width + x] = ft_atoi(strtext);
	check_inmap_tex(level, x, y);
	if ((y == 0 || y == level->map_height - 1) &&
		(level->map[y * level->map_width + x] <= 0 ||
		level->map[y * level->map_width + x] > TEX_AMOUNT))
	{
		error_msg(level);
		exit(0);
	}
	if (x == 0 && (level->map[y * level->map_width + x] <= 0 ||
		level->map[y * level->map_width + x] > TEX_AMOUNT))
	{
		error_msg(level);
		exit(0);
	}
	if (y != 0 && x == level->map_width - 1 &&
		(level->map[y * level->map_width + x] <= 0 ||
		level->map[y * level->map_width + x] > TEX_AMOUNT))
	{
		error_msg(level);
		exit(0);
	}
}

void			error_valid(int x, int i, t_level *level)
{
	if (x != level[i].map_width)
	{
		ft_putstr("Error: WIDHT of each column not equal\nLevel ID: ");
		ft_putnbr(level[i].lvl_id);
		exit(0);
	}
}

void			free_val(char **map_y, int y, char *str)
{
	del_double_arr(&map_y, y);
	ft_strdel(&str);
}
