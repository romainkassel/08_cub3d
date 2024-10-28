/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:46:56 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/26 14:33:54 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

//Mandatory
# define SCREEN_W 1920
# define SCREEN_H 1080

//Bonus
// # define SCREEN_W 1366
// # define SCREEN_H 768

# define TEXTURE_SIZE 64

// minimap
# define MINIMAP_SIZE_MAX 500
# define MINIMAP_PADDING_TOP 69
# define PLAYER_COLOR 0x0000ff00
# define EMPTY_CELL_BD_COL 0x333333
# define EMPTY_CELL_BG_COL 0xffffff
# define WALL_BD_COL 0xffffff
# define WALL_BG_COL 0x333333

/* is_wall_found */
# define NOT_FOUND_YET 0
# define FOUND 1

/* wall side DDA */
# define VERTICAL_SIDE_X_EAST 3
# define HORIZONTAL_SIDE_Y_SOUTH 4
# define VERTICAL_SIDE_X_WEST 1
# define HORIZONTAL_SIDE_Y_NORTH 2

/* camera rotation */

# define ROT_SPEED_ARROWS 0.05
# define ROT_SPEED_MOUSE 0.01
# define MOV_SPEED 0.05
# define GAP_BEFORE_WALL_COLISION 10

/* keys */

# define ESCAPE 65307
# define RIGHT_ARROW 65363
# define LEFT_ARROW 65361
# define UP_W 119
# define LEFT_A 97
# define DOWN_S 115
# define RIGHT_D 100

/* return and exit status */
# define SUCCESS 0
# define FAILURE 1

// textS
# define NO 0
# define SO 1
# define WE 2
# define EA 3

/*
##################
# ERROR MESSAGES #
##################
*/

// File errors

# define ERR_MIS_FILE "Error\nWrong number of arguments. Please provide a .cub"
# define ERR_EXT "Error\nWrong extension for the .cub file"
# define ERR_DIR "Error\nThe cub provided is a directory"
# define ERR_READ "Error\nCouldn't read the file"

// Errors in the config file
# define ERR_EMPTY_FILE "Error\nThe file is empty"
# define ERR_MIS_TEXT "Error\nAt least one texture is missing"
# define ERR_MIS_FC "Error\nFloor or ceiling color missing"
# define ERR_TWICE_TX "Error\nTexture is specified twice"
# define ERR_TX_PATH "Error\nPath syntax is not valid"
# define ERR_FC_SYNTAX "Error\nFloor or ceiling syntax is not valid"
# define ERR_FC_NUM "Error\nColor identifier is not valid [0, 255]"
# define ERR_TWICE_COL "Error\nColor is specified twice"

// Errors in the map
# define ERR_MAP_EL "Error\nEmpty line in map"
# define ERR_MAP_INVALID_CH "Error\nInvalid char in map"
# define ERR_MAP_PLAYER "Error\nThere must be one player"
# define ERR_MAP_OPEN "Error\nThe map is not closed or there is an invalid space"
# define ERR_MAP_SPACE "Error\nThere is a space in the map"
# define ERR_NO_MAP "Error\nMap not found"
# define ERR_CONFIG "Error\nWrong map configuration"
/*
##################
#   STRUCTURES   #
##################
*/

typedef struct s_collect
{
	int			fd;
	char		**map;
	char		**copy_map;
	int			lines_count;
	int			line_size;
	int			file_nb_lines;
	int			map_nb_lines;
	char		**texts;
	char		**c_rgb;
	char		**f_rgb;
	int			color_f;
	int			color_c;
	int			map_found;
	int			map_finished;
	int			all_elem_found;
	int			pos_player_x;
	int			pos_player_y;
	int			map_real_lines;
	int			map_real_lsize;
	int			orient_x;
	int			orient_y;
	double		plane_x;
	double		plane_y;

}				t_collect;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*mlx_win;
}				t_mlx;

typedef struct s_column
{
	int			line_height;
	int			draw_start;
	int			draw_start_out;
	int			draw_end;
	int			draw_end_out;
	double		wall_x;
	int			text_x_pos;
	int			text_x_by_bpp;
	int			screen_x_by_bpp;
	double		text_y_start_pos;
	double		text_y_start_pos_tmp;
	double		text_scale;
	int			text_addr_i;
	int			main_img_addr_i;
}				t_column;

typedef struct s_window_object
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img_obj;

typedef struct s_minimap
{
	int			tile_size;
	int			minimap_w;
	int			minimap_h;
	int			start_x;
	int			start_y;
	int			player_size;
}				t_minimap;

typedef struct s_raycast
{
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			step_x;
	int			step_y;
	double		side_dist_x;
	double		side_dist_y;
	int			is_wall_found;
	int			wall_side;
	double		perp_wall_dist;
	int			mouse_x;
}				t_raycast;

typedef struct s_cub3d
{
	char		**map;
	int			map_w;
	int			map_h;
	double		pos_x;
	double		pos_y;
	int			map_x;
	int			map_y;
	int			ceiling_color;
	int			floor_color;
	t_img_obj	*main_img;
	t_img_obj	*text_west;
	t_img_obj	*text_north;
	t_img_obj	*text_east;
	t_img_obj	*text_south;

}				t_cub3d;

typedef struct s_data
{
	t_collect	*collect;
	t_mlx		*mlx;
	t_minimap	*minimap;
	t_cub3d		*cub3d;
	t_column	*column;
	t_raycast	*raycast;
}				t_data;

// Functions for error handling

int				error_file(int error_code);
int				error_elements(int error_code);
int				error_map(int error_code);

// Functions for initialization
t_img_obj		*ft_lstnew_img_obj(t_data *data);
int				init_and_parse(char *filename, t_data *data);
t_data			*init_data(t_data *data);
int				init_graphisms(t_data *data);
t_minimap		*init_minimap_struct(t_data *data);
t_cub3d			*init_cub3d_struct(t_data *data);
t_raycast		*init_raycast_struct(t_data *data);
t_column		*init_column_struct(t_data *data);
t_mlx			*init_mlx(t_data *data);
void			init_main_img(t_data *data);

// Functions for file parsing

bool			extension_control(char *str);
int				parse_file(char *filename, t_data *data);
int				collect_texts(char *line, char **text);
int				collect_colors_fc(char *line, t_data *data);
int				retrieve_colors(char *line, char **rgb, t_data *data);
bool			is_text(char *line);
bool			is_f_or_c(char *line);
bool			is_map(char *line);
int				check_text(char *line, char **text, int i);
bool			is_a_map_char(char c);

// Functions for map parsing
int				parse_map(t_data *data);
int				verif_map(char **map, t_data *data);
char			**copy_map(char **map, char **copy_map, t_data *data,
					int index);
int				verif_borders(char **map, t_data *data);
int				is_player(char c, t_data *data, int i, int j);
char			**create_map_ff(t_data *data, int nb_lines, int line_size);
char			**copy_map_ff(t_data *data, char **copy_map, int nb_lines,
					int line_size);
int				launch_fill(char **map, t_data *data, int nb_cols, int nb_rows);
int				verif_flood_fill(char **map, int nb_cols, int nb_rows);
int				check_positions_ff(char c, char to_compare);
void			fill_with_walls(char **map, int nb_cols, int nb_rows);
int				verif_player(char c);
char			**malloc_map(int nb_lines);

// Parsing utils
char			*ft_strjoin_cub(char const *s1, char const *s2, t_data *data);
bool			count_lines(int fd, t_data *data);
char			*get_next_line(int fd, t_data *data, int i);
int				collect_map(char *line, int fd, int j, t_data *data);
int				ft_atoi_cub(const char *nptr);
int				convert_to_hex(long r, long g, long b, int a);
int				check_spaces(char *line, int fd, int j, t_data *data);

// Graphics functions
int				init_texts(t_data *data, t_cub3d *cub3d);

// minimap

// init minimap

void			init_minimap(t_data *data);
void			get_tile_size(t_data *data);
void			get_player_size(t_data *data);
void			get_minimap_size(t_data *data, t_cub3d *cub3d);
void			get_start_xy(t_minimap *minimap);

// draw minimap

int				get_player_offset(t_data *data, int y, int x);
void			draw_player(t_data *data);
void			draw_cell(t_data *data, int offset, int bd_color, int bg_color);
int				get_cell_offset(t_data *data, int y, int x);
void			draw_minimap(t_data *data);

// Moves
int				manage_keys(int keycode, t_data *data);

// Functions for memory freeing
int				exit_safely(t_data *data, int exit_code);
void			free_data(t_data *data);
void			free_cub3d(t_data *data);
void			destroy_images(t_data *data, t_cub3d *cub3d);
void			free_collect(t_collect *collect);
void			ft_free_mlx(t_mlx *mlx);
void			ft_free_maps(char **map, int count);
void			free_rgb(char **rgb);
void			free_minimap(t_minimap *minimap);
void			ft_free_texts(char **texts);

// Functions for raycasting

// 01 raycasting

void			raycast_it(t_data *data);
void			get_camera_x(t_raycast *raycast, int screen_x);
void			get_ray_dir(t_raycast *raycast);
void			get_delta_dist(t_raycast *raycast);
void			get_map_vector(t_cub3d *cub3d);

// 02 raycasting

void			get_step_and_side_dist_x(t_data *data);
void			get_step_and_side_dist_y(t_data *data);
void			manage_x_moves(t_data *data);
void			manage_y_moves(t_data *data);
void			find_wall(t_data *data, t_cub3d *cub3d);

// 03 raycasting

void			get_ray_distance(t_raycast *raycast);
void			get_line_height(t_data *data);
void			get_column_pixel_range(t_column *column);
void			get_wall_impact_coordinate_on_x(t_data *data);

// Functions for rendering

// ceiling and floor

void			put_pix_on_img(int screen_x, int start_y, t_cub3d *cub3d,
					int col);
void			draw_ceiling_column(t_data *data, t_column *column,
					int screen_x);
void			draw_floor_column(t_data *data, t_column *column, int screen_x);

// 01 walls

void			draw_wall_column(t_data *data, t_column *column, int screen_x);
t_img_obj		*get_text(t_data *data);
void			get_text_x_pos(t_data *data);
void			get_text_y_start_pos(t_data *data);
void			get_column_var_values(t_data *data, int screen_x,
					t_img_obj *text);

// 02 walls

void			put_text_on_main_img(t_data *data, int start_y,
					t_img_obj *text);

// Functions for moves

/* srcs/manage_camera.c */
void			rotate_camera_right(t_data *data, double rot_speed);
void			rotate_camera_left(t_data *data, double rot_speed);
int				manage_mouse(int x, int y, t_data *data);

/* srcs/manage_moves.c */
void			move_up(t_data *data);
void			move_down(t_data *data);
void			move_left(t_data *data);
void			move_right(t_data *data);

// Utils for testing
void			display_copy_map(char **map, int nb_rows);

#endif