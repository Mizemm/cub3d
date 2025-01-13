#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <limits.h>
#include <math.h>
// #include <../../MLX42/include/MLX42/MLX42.h>
#include <MLX42.h>

#define UNIT_SIZE 30
#define FOV 60 * (M_PI / 180)

typedef struct s_horizontal {
	double x_intercept;
	double y_intercept;
	double x_step;
	double y_step;
	double horzWallHitX;
	double horzWallHitY;
	bool foundHorzWall;
} t_horizontal;

typedef struct s_vertical {
	double x_intercept;
	double y_intercept;
	double x_step;
	double y_step;
	double vertWallHitX;
	double vertWallHitY;
	bool foundVertWall;
} t_vertical;

typedef struct s_player {
	double position_x;
	double position_y;
	double angle_rotation;
	double rotate_speed;
	double move_speed;
	int rotate_direction;
	int move_direction;
	mlx_image_t *player_image;
} t_player;

typedef struct s_ray {
	double wallHitX;
	double wallHitY;
	double ray_angle;
} t_ray;

typedef struct s_game {
	size_t WIDTH;
	size_t HEIGHT;
	double rays_number;
	double wallHitX;
	double wallHitY;
	char **map;
	mlx_t *mlx;
	mlx_image_t *image;
	t_ray *rays;
	t_player player;
	t_vertical vertical;
	t_horizontal horizontal;
} t_game;

char	*get_next_line(int fd);
char 	**get_map(char **map);
size_t 	get_height(char **map);
size_t	get_width(char **map);

void	init_struct(t_game *game);

void	draw_background(t_game *game);
void	draw_wall(t_game *game);
void	draw_player(t_game *game);
void 	draw_line(t_game *game, t_ray ray);
void	rebuild_game(t_game *game);

void 	right_move(t_game *game);
void	left_move(t_game *game);
void	backward_move(t_game *game);
void	forward_move(t_game *game);

bool	is_facing_down(double angle);
bool	is_facing_up(double angle);
bool	is_facing_right(double angle);
bool	is_facing_left(double angle);
bool 	is_wall(t_game *game, double x, double y);

void	key_hook(mlx_key_data_t key, void *param);

double	normalize_angle(double angle);
void 	find_distance(t_game *game, t_ray *ray, double ray_angle);
void 	cast_rays(t_game *game);
double 	calculate_distance(double x1, double y1, double x2, double y2);


// -------------------------------------------------------------------

//     ------------------------------
// .. the angle most not > 360 or <  ..
//     ------------------------------

// calculate the horizontal and vertical distances between the wall and the player
// choose the nearest one to the player
// cast rays

// -------------------------------------------------------------------

// render walls