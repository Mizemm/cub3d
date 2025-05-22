NAME	= cub3d_bonus
CFLAGS	= -Wextra -Wall -Werror #-fsanitize=address -g 
LIBMLX	= ~/MLX42
CC		= cc

HEADERS	= -I ./include -I $(LIBMLX)/include/MLX42
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	= cub3d_bonus.c raycasting_bonus/player_action_bonus.c raycasting_bonus/init_struct_bonus.c raycasting_bonus/utils_bonus.c raycasting_bonus/draw_map_bonus.c \
		raycasting_bonus/player_movement_bonus.c raycasting_bonus/raycasting_bonus.c raycasting_bonus/player_direction_bonus.c raycasting_bonus/utils2_bonus.c raycasting_bonus/minimap_bonus.c raycasting_bonus/minimap_utils_bonus.c raycasting_bonus/doors_bonus.c raycasting_bonus/doors_utils_bonus.c raycasting_bonus/raycasting_utils_bonus.c raycasting_bonus/raycasting_utils2_bonus.c \
		parsing_bonus/parsing_bonus.c parsing_bonus/ft_free_bonus.c parsing_bonus/border_check_bonus.c parsing_bonus/elements_bonus.c parsing_bonus/map_bonus.c \
		parsing_bonus/parsing_error_bonus.c parsing_bonus/colors_check_bonus.c parsing_bonus/textures_bonus.c parsing_bonus/texture_walls_bonus.c \
		parsing_bonus/texture_doors_bonus.c parsing_bonus/border_check_2_bonus.c parsing_bonus/map_checkers_bonus.c \
		parsing_bonus/flag_counters_bonus.c parsing_bonus/textures_2_bonus.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		libft/ft_split.c libft/ft_substr.c libft/ft_mini_strchr.c libft/ft_strlen.c libft/ft_strdup.c libft/ft_isdigit.c \
		libft/ft_atoi.c libft/ft_strtrim.c libft/ft_memset.c
OBJS	= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx: 
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c ./include/cub3d.h
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: clean, libmlx