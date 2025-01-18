NAME	= cub3d
CFLAGS	= -Wextra -Wall -Werror -fsanitize=address -g
LIBMLX	= ~/MLX42
CC		= cc

HEADERS	= -I ./include -I $(LIBMLX)/include/MLX42
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	= src/cub3d.c src/player_action.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		  src/init_struct.c src/utils.c src/draw_map.c src/player_movement.c src/raycasting.c src/player_direction.c \
		  src/utils2.c
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
	#@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: clean, libmlx