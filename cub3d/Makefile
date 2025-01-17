NAME	= cub3d
# CFLAGS	= -fsanitize=address #-Wextra -Wall -Werror
LIBMLX	= ~/MLX42
CC		= cc

HEADERS	= -I ./include -I $(LIBMLX)/include/MLX42 -I $(LIBFT)/include
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	= src/main.c src/ft_free.c src/border_check.c src/elements.c src/map.c \
        get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		libft/ft_split.c libft/ft_substr.c libft/ft_mini_strchr.c
OBJS	= ${SRCS:.c=.o}

all: libmlx libft $(NAME)

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

.PHONY: clean libmlx
