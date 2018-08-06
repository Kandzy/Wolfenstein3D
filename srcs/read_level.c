/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:56:20 by dkliukin          #+#    #+#             */
/*   Updated: 2018/01/26 15:56:20 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static char	*ft_strjoin_mod(char *a, char *b)
{
	char	*str;

	str = ft_strjoin(a, b);
	ft_strdel(&a);
	return (str);
}

static void	check_freeline(char *str)
{
	if (strlen(str) == 0)
	{
		ft_putendl("Error of map input!\nCheck your input!!");
		exit(0);
	}
}

void		read_level(char *filename, t_level *level)
{
	int		fd;
	char	*line;
	int		i;

	level->str_map = ft_strnew(0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return ;
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		check_freeline(line);
		while (line[++i] != '\0')
		{
			if ((line[i] > '9' || line[i] < '0') && line[i] != ' ')
			{
				ft_putendl("Error of map input! Symb on map not 0 - 9");
				exit(0);
			}
		}
		line = ft_strjoin_mod(line, "\n");
		level->map_height++;
		level->str_map = ft_strconcat(level->str_map, line);
	}
	ft_strdel(&line);
}
