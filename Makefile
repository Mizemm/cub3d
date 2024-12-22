NAME	= cub3d
CFLAGS	= -Wextra -Wall -Werror
LIBMLX	= ~/MLX42
CC		= cc

HEADERS	= -I ./include -I $(LIBMLX)/include/MLX42
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	= src/cub3d.c src/player_action.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJS	= ${SRCS:.c=.o}


all: libmlx $(NAME)

libmlx: 
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c ./include/cub3d.h
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	# @rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: clean, libmlx