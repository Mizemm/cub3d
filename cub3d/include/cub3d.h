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
	char **elements;
	char **map;
	char *NO_DATA;
	char *SO_DATA;
	char *WE_DATA;
	char *EA_DATA;
	char *FLOOR_DATA;
	char *CEILING_DATA;
	t_player player;
} t_game;

int		ft_strlen(char *s);
int		ft_mini_strchr(char s, char *c);
int     ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, int start, int len);
char	**ft_split(char *s, char *c);
char	*get_next_line(int fd);





size_t 	count_width(char **map);
size_t 	count_height(char **map);
int		elements_counter(char *map_name);
void	ft_free(char **arr);
int		map_finder(char *str);
void    elements(t_game *game, char *line);
void	map(t_game *game, char *line);
void	struct_elements(t_game *game);
int		borders(t_game *game);

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