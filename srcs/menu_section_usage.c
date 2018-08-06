/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_section_usage.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:41:05 by dkliukin          #+#    #+#             */
/*   Updated: 2018/02/18 12:41:08 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		main_section(t_window *win)
{
	if (win->menu.slot == NEWGAME)
	{
		win->menu.status = DISACTIVE;
		win->lvl_id = 0;
	}
	if (win->menu.slot == EXIT_SLOT)
		win->exit_flag = TRUE;
	if (win->menu.slot == LEVEL_SLOT)
		win->menu.section = 1;
	if (win->menu.slot == OPTIONS_SLOT)
		win->menu.section = 2;
}

void		level_section(t_window *win)
{
	if (win->menu.slot < BACK_SLOT_2)
	{
		win->lvl_id = win->menu.slot;
		win->menu.status = DISACTIVE;
	}
	if (win->menu.slot == BACK_SLOT_2)
		win->menu.section = 0;
}

void		options_section(t_window *win)
{
	if (win->menu.slot == BACK_SLOT_3)
		win->menu.section = 0;
	if (win->menu.slot < BACK_SLOT_3)
	{
		win->resolution = win->menu.slot + 1;
		win->menu.section = 0;
	}
}
