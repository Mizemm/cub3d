#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
// #include <../../MLX42/include/MLX42/MLX42.h>
#include <MLX42.h>

#define UNIT_SIZE 30
#define FOV 60

typedef struct s_ray {
	int ray_number;
	double ray_angle;
} t_ray;

typedef struct s_player {
	double position_x;
	double position_y;
	double angle_rotation;
	double rotate_speed;
	double move_speed;
	int rotate_direction;
	int move_direction;
	mlx_image_t *player_image;
	mlx_image_t *line_img;

} t_player;

typedef struct s_game {
	size_t WIDTH;
	size_t HEIGHT;
	char **map;
	mlx_t *mlx;
	mlx_image_t *wall_img; 
	mlx_image_t *background_img;
	t_player player;
	t_ray	ray;
} t_game;

char	*get_next_line(int fd);
char 	**get_map(char **map);
size_t 	get_height(char **map);
size_t	get_width(char **map);

void	init_struct(t_game *game);

void	draw_background(t_game *game);
void	draw_wall(t_game *game);
void	draw_player(t_game *game);
void 	draw_line(t_game *game);
void 	draw_ray(t_game *game);

void 	right_move(t_game *game);
void	left_move(t_game *game);
void	backward_move(t_game *game);
void	forward_move(t_game *game);

void	rebuild_game(t_game *game);
void	key_hook(mlx_key_data_t key, void *param);


// -------------------------------------------------------------------

//     ------------------------------
// .. the angle most not > 360 or <  ..
//     ------------------------------

// calculate the horizontal and vertical distances between the wall and the player
// choose the nearest one to the player
// cast rays

// -------------------------------------------------------------------

// render walls