/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:02:49 by mizem             #+#    #+#             */
/*   Updated: 2025/02/26 00:25:56 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define UNIT_SIZE 30
# define FOV 1.04719755
# define MOVE_SPEED 5
# define WIDTH 2000
# define HEIGHT 1200
# define MINIMAP_SCALE 0.2
# define ZOOM 0.5

# include </Users/mizem/MLX42/include/MLX42/MLX42.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
// #include <MLX42.h>

typedef struct s_dda
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				dx;
	int				dy;
	int				stepx;
	int				stepy;
	int				err;
	int				e2;
}					t_dda;

typedef struct s_horizontal
{
	double			x_intercept;
	double			y_intercept;
	double			x_step;
	double			y_step;
	double			horz_wall_hitx;
	double			horz_wall_hity;
	bool			found_horz_wall;
	double			next_horz_stepx;
	double			next_horz_stepy;
}					t_horizontal;

typedef struct s_vertical
{
	double			x_intercept;
	double			y_intercept;
	double			x_step;
	double			y_step;
	double			vert_wall_hitx;
	double			vert_wall_hity;
	bool			found_vert_wall;
	double			next_vert_stepx;
	double			next_vert_stepy;
}					t_vertical;

typedef struct s_player
{
	double			position_x;
	double			position_y;
	double			angle_rotation;
	double			rotate_speed;
	double			move_speed;
	int				rotate_direction;
	int				move_direction;
	mlx_image_t		*player_image;
}					t_player;

typedef struct s_ray
{
	double			wall_hitx;
	double			wall_hity;
	double			ray_angle;
	double			line_hight;
	double			distance;
	bool			found_horz;
	bool			found_vert;
	bool			found_no;
	bool			found_so;
	bool			found_ea;
	bool			found_we;
}					t_ray;

typedef struct s_textures
{
	mlx_texture_t	*wall_texture[4];
	double			p_wall_height;
	double			projection_distance;
	int				wall_top_pixel;
	int				wall_buttom_pixel;
}					t_textures;

typedef struct s_game
{
	int				width;
	int				height;
	int				minimap_width;
	int				minimap_height;
	int				x_draw;
	int				y_draw;
	double			rays_number;
	char			**map;
	char			**elements;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	char			*floor_color;
	char			*ceiling_color;
	int				floor_color_int[4];
	int				ceiling_color_int[4];
	char			*trash;
	char			player_direction;
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_ray			*rays;
	t_player		player;
	t_vertical		vertical;
	t_horizontal	horizontal;
	t_textures		*textures;
}					t_game;

// LIBFT FUNCTIONS //

int					ft_strlen(char *s);
int					ft_isdigit(char c);
int					ft_mini_strchr(char s, char *c);
int					ft_strcmp(char *s1, char *s2);
int					ft_atoi(char *str);
char				*ft_strdup(char *s1);
char				*ft_substr(char *s, int start, int len);
char				*ft_strtrim(char *s1, char *set);
char				**ft_split(char *s, char *c);
void				*ft_memset(void *b, int c, size_t len);

// GET_NEXT_LINE //
char				*get_next_line(int fd);

// PARSING FUNCTIONS //

size_t				count_width(char **map);
size_t				count_height(char **map);
int					elements_counter(char *map_name);
void				ft_free(char **arr);
int					map_finder(char *str);
void				elements(t_game *game, char *line);
void				map(t_game *game, char *line);
int					struct_elements(t_game *game);
int					empty_line(char *str);
int					map_checker(t_game *game);
int					map_checker_2(t_game *game);
int					map_checker_4(t_game *game);
int					flag_counter(t_game *game, char **str, int flag);
int					flag_counter_2(t_game *game, char **str, int flag_2);
int					border_check(t_game *game, int y, int x);
int					borders(t_game *game);
int					parsing_error(t_game *game);
int					file_check(char *name);
int					floor_color_check(t_game *game);
int					floor_color_check_2(t_game *game);
int					ceiling_color_check(t_game *game);
int					ceiling_color_check_2(t_game *game);
uint32_t			color(uint8_t *arr);
void				render_weapon(t_game *game);
void				animate_weapon(t_game *game);
void				deanimate_weapon(t_game *game);
size_t				count_width(char **map);
size_t				count_height(char **map);
void				load_textures(t_game *game);
void				parsing(t_game *game, char *line);
void				render_textures(t_game *game, t_ray *ray);
void				render_no(t_game *game, t_ray *ray, int i, int y);
void				render_ea(t_game *game, t_ray *ray, int i, int y);
void				render_so(t_game *game, t_ray *ray, int i, int y);
void				render_we(t_game *game, t_ray *ray, int i, int y);
void				render_horzdoor(t_game *game, t_ray *ray, int i, int y);
void				render_vertdoor(t_game *game, t_ray *ray, int i, int y);
void				render_weapon(t_game *game);
void				animate_weapon(t_game *game);
void				deanimate_weapon(t_game *game);
void				ft_free(char **arr);
void				free_all(t_game *game);

// init & draw function //

void				init_struct(t_game *game);
void				draw_ceiling(t_game *game);
void				draw_floor(t_game *game);
void				rebuild_game(t_game *game);
void				render_textures(t_game *game, t_ray *ray);
unsigned int		rgbt_color(int t, int r, int g, int b);

// player movement //

void				rotate_right(t_game *game);
void				rotate_left(t_game *game);
void				find_player(t_game *game);
void				right_move(t_game *game);
void				left_move(t_game *game);
void				backward_move(t_game *game);
void				forward_move(t_game *game);
void				movement_hook(void *param);

// player direction //

void				rays_direction(t_ray *ray);
bool				is_facing_down(double angle);
bool				is_facing_up(double angle);
bool				is_facing_right(double angle);
bool				is_facing_left(double angle);
double				normalize_angle(double angle);

// minimap //

int					bounds_error(t_game *game, double px, double py);
void				init_line(t_game *game, int px, int py);
int					get_status_color(int status);
void				start_draw(t_game *game, int x, int y, int status);
void				draw_minimap(t_game *game);

// doors //

void				doors_allocted(t_game *game);
void				close_door(t_game *game);
void				open_door(t_game *game);
int					check_for_close(t_game *game, int door_x, int door_y);
void				check_for_open(t_game *game, int grid_x, int grid_y);
bool				is_doors(t_game *game, double x, double y);
bool				is_opendoor(t_game *game, double x, double y);

// raycasting function //

void				init_horz_rays(t_game *game, t_ray *ray,
						double horizontal_distance);
void				init_vert_rays(t_game *game, t_ray *ray,
						double vertical_distance);
bool				check_vert_wall(t_game *game, double checkStepX,
						double checkStepY);
void				check_vert_door(t_game *game, double checkStepX,
						double checkStepY, double angle);
bool				check_horz_wall(t_game *game, double checkStepX,
						double checkStepY);
void				check_horz_door(t_game *game, double checkStepX,
						double checkStepY, double angle);
void				cast_rays(t_game *game);
void				init_vertical_intersection(t_game *game, double angle);
void				init_horizontal_intersection(t_game *game, double angle);
void				find_distance(t_game *game, t_ray *ray, double ray_angle);
double				calculate_distance(double x1, double y1, double x2,
						double y2);
bool				is_wall(t_game *game, double x, double y);

#endif