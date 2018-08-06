/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkliukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 13:24:59 by dkliukin          #+#    #+#             */
/*   Updated: 2018/01/21 13:25:00 by dkliukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <SDL2/SDL.h>
# include <math.h>
# include <fcntl.h>
# define ON 1
# define OFF 0
# define THREADS 4
# define FPS 60
# define TEXW 64
# define TEXH 64
# define NLVL 9
# define ACTIVE 1
# define DISACTIVE 0
# define TRUE 1
# define FALSE 0
# define SLOT_0_MAX 3
# define SLOT_1_MAX 9
# define SLOT_2_MAX 5
# define EXIT_SLOT 3
# define NEWGAME 0
# define LEVEL_SLOT 1
# define BACK_SLOT_2 9
# define BACK_SLOT_3 5
# define OPTIONS_SLOT 2
# define TEX_AMOUNT 60

typedef struct		s_time
{
	double			start;
	double			end;
	double			ftime;
}					t_time;

typedef struct		s_val
{
	int				x;
	int				y;
	int				size;
	int				width;
	int				height;
}					t_val;

typedef struct		s_texur
{
	int				*tex_pixels;
}					t_texur;

typedef	struct		s_textures
{
	SDL_Texture		*texture;
	t_val			val;
}					t_textures;

typedef struct		s_level
{
	int				lvl_id;
	char			*str_map;
	int				*map;
	int				map_width;
	int				map_height;
	int				posx;
	int				posy;
	int				exitx;
	int				exity;
}					t_level;

typedef	struct		s_menu
{
	t_textures		level[9];
	t_textures		size[5];
	t_textures		background;
	t_textures		new_game;
	t_textures		options;
	t_textures		exit_op;
	t_textures		arrow;
	t_textures		back;
	t_textures		levels;
	short int		slot;
	short int		max_slot;
	short int		section;
	int				status;
}					t_menu;

typedef struct		s_winpos
{
	int				x;
	int				y;
	int				xmove;
	int				ymove;
}					t_winpos;

typedef	struct		s_position
{
	double			x;
	double			y;
}					t_position;

typedef struct		s_camera
{
	t_position		dir;
	t_position		plane;
	double			x;
	int				*pixels;
	int				tex_h;
	int				tex_w;
	int				tex_init;
	SDL_Texture		*vision;
}					t_camera;

typedef	struct		s_side
{
	t_position		dist;
}					t_side;

typedef struct		s_ray
{
	t_side			side;
	int				dstart;
	int				dend;
	double			dirx;
	double			diry;
}					t_ray;

typedef struct		s_player
{
	t_position		pos;
	t_camera		cam;
	int				shift;
	double			movespeed;
	double			rotspeed;
}					t_player;

typedef struct		s_walls
{
	double			wall_x;
	double			wall_dist;
	int				tex_x;
	int				tex_y;
	int				hit;
	int				side;
	int				linehe;
	int				tex_num;
	unsigned int	color;
}					t_walls;

typedef	struct		s_dist
{
	double			wall;
	double			player;
	double			current;
}					t_dist;

typedef struct		s_floor
{
	t_position		poswall;
	t_position		curr_pos;
	int				ftex_x;
	int				ftex_y;
	t_dist			dist;
	double			leng;
}					t_floor;

typedef struct		s_map
{
	double			dx;
	double			dy;
	int				x;
	int				y;
	int				stepx;
	int				stepy;
}					t_map;

typedef struct		s_game_win
{
	t_ray			ray;
	t_player		pl;
	t_walls			wtex;
	t_map			map;
	t_time			frametime;
	t_floor			floortex;
	const Uint8		*keystate;
}					t_game_win;

typedef struct		s_window
{
	t_menu			menu;
	SDL_Window		*win;
	SDL_Renderer	*ren;
	int				i;
	int				**buffer;
	int				**current_map;
	int				height;
	int				width;
	int				sflag;
	int				lvl_id;
	int				keystatus;
	short int		resolution;
	int				exit_flag;
}					t_window;

/*
** Load Levels && Menu textures
*/

SDL_Texture			*load_texture(char *file, SDL_Renderer *ren);
void				read_level(char *filename, t_level *level);
int					validate(t_level *level);
int					validate_levels(t_level *level);
void				init_textures(t_texur *tex, SDL_Surface *img);
void				init_levels(t_level *lvl, int amount_of_lvl);
int					load_levels(t_level *level, int amount_of_lvl);
void				game_init(t_window *win, t_level *level, t_texur *tex);
int					init_level_texture(t_window *win, t_level *level,
									t_texur *tex, SDL_Surface *img);

/*
**Validate map
*/

void				texture_value(char *strtext, t_level *level,
					int x, int y);
void				error_valid(int x, int i, t_level *level);
void				free_val(char **map_y, int y, char *str);

/*
** INITIATE DEFAULT
*/

int					sdl_initiate_all(t_window *win);

/*
** OPTIONS
*/

char				*map_path(char *a, char *b);
int					quit_wolf(t_window *win, SDL_Event ev);

/*
** ANTILEAKS
*/

void				del_double_arr(char ***str, int size);

/*
** MENU
*/

void				default_display_option(t_window *win);
void				menu_window(t_window *win);
void				display_menu(t_window *win, SDL_Event *ev);
void				wolf_menu(t_window *win);
void				screen_size(t_window *win);
void				load_menu_textures(t_window *win);
void				load_options(t_window *win);
void				load_menu_levels(t_window *win);
void				menu_key_manip(t_window *win, SDL_Event ev);
void				new_game_sec(t_window *win, SDL_Event *ev);
void				level_sec(t_window *win, SDL_Event *ev);
void				options_sec(t_window *win, SDL_Event *ev);
void				exit_sec(t_window *win, SDL_Event *ev);
void				mouse_action(t_window *win, SDL_Event *ev);

/*
** ARROW AND BUTTONS BOSITION
*/

void				position(int x, int y, t_textures tex, t_window *win);
void				menu_button_position(t_window *win);
void				menu_section_2_position(t_window *win);
void				menu_section_3_position(t_window *win);

/*
** MENU MOUSE ACTOIN
*/

void				mouse_action(t_window *win, SDL_Event *ev);
void				mouse_action_section_0(t_window *win, SDL_Event *ev);
void				mouse_action_section_1(t_window *win, SDL_Event *ev);
void				mouse_action_section_2(t_window *win, SDL_Event *ev);

/*
** SECTIONS
*/

void				main_section(t_window *win);
void				level_section(t_window *win);
void				options_section(t_window *win);

/*
** IN GAME
*/

void				create_game_window(t_window *win);
void				create_texture(t_window win, t_camera *cam, SDL_Rect *pos);
void				display_floor(t_game_win *gw, t_window *win,
										t_texur *tex, int x);
void				loop(t_game_win *gw, t_window *win, t_texur *tex, int x);
void				present_frame(t_game_win *gw, t_window *win, SDL_Rect *pos);
void				display_textures(t_game_win *gw, t_window *win,
											t_texur *tex, int x);
void				game_window(t_window *win, t_level *level, t_texur *tex);
void				player_initiate(t_game_win *gw);
void				draw_line(t_game_win gw, t_camera *cam, int x, int color);
void				vertical_line(t_game_win *gw, int x);
void				init_ray(t_game_win *gw, t_window win, int x);
void				steps_calc(t_game_win *gw);
void				wall_hit(t_game_win *gw, int **map);
void				draw_parametrs(t_game_win *gw, t_window *win);
void				choose_color(t_game_win *gw, t_window *win);
void				key_event(t_window *win, t_game_win *gw, SDL_Event *ev);
void				pixel_put(t_camera *cam, int x, int y, int color);
void				load_tex(char *filename, t_texur *tex, SDL_Surface *image);

#endif
