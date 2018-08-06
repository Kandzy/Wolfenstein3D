/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:50:25 by dkliukin          #+#    #+#             */
/*   Updated: 2018/01/26 16:50:26 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				validate_levels(t_level *level)
{
	int		y;
	int		x;
	int		i;
	char	**map_y;
	char	**map_x;

	i = -1;
	while (++i < NLVL)
	{
		map_y = ft_strsplit(level[i].str_map, '\n');
		y = -1;
		while (map_y[++y] != NULL)
		{
			x = -1;
			map_x = ft_strsplit(map_y[y], ' ');
			while (y == 0 && map_x[level[i].map_width] != NULL)
				level[i].map_width++;
			while (map_x[++x] != NULL)
				texture_value(map_x[x], &level[i], x, y);
			del_double_arr(&map_x, x);
			error_valid(x, i, level);
		}
		free_val(map_y, y, (level[i].str_map));
	}
	return (0);
}

int				validate_size(t_level *level)
{
	int		i;

	i = 0;
	while (i < NLVL)
	{
		if (level[i].map_height < 3 || level[i].map_width < 3)
		{
			ft_putstr("Wrong size of map.\nCheck your input\nLevel ID: ");
			ft_putnbr(i + 1);
			return (-1);
		}
		i++;
	}
	return (0);
}

int				validate_texture(t_level *level)
{
	int		i;

	i = 0;
	while (i < NLVL)
	{
		if (level[i].map[level[i].map_width + 1] != 0)
		{
			ft_putendl("Texture cant be plased in position x = 1, y = 1");
			ft_putstr("Check your input\nLevel ID: ");
			ft_putnbr(i + 1);
			return (-1);
		}
		i++;
	}
	return (0);
}

int				validate(t_level *level)
{
	if (validate_levels(level) == -1)
		return (-1);
	if (validate_size(level) == -1)
		return (-1);
	if (validate_texture(level) == -1)
		return (-1);
	return (0);
}
