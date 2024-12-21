#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <MLX42.h>

typedef struct s_player {
	double position_x;
	double position_y;
	double angl_rotation;

} t_player;

typedef struct s_game {
	int WIDTH;
	int HEIGHT;
	char **map;
	t_player player;
} t_game;

char	*get_next_line(int fd);

// draw 2d map pixel by pixel (finish)
// put player
// make the player direction and make him rotate
// make the player mvts
// the player must not pass the walls

// -------------------------------------------------------------------

// calculate the horizontal and vertical distances between the wall and the player
// choose the nearest one to the player
// cast rays

// -------------------------------------------------------------------

// render walls