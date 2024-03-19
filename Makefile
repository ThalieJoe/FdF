NAME = fdf

SOURCES =	main.c \
			init_map.c \
			parse_grid.c \
			parse_line.c \
			add_to_coord.c \
			init_plane.c \
			init_plane_width.c \
			init_plane_height.c \
			adapt_scale_to_three.c \
			get_height.c \
			get_depth.c \
			upd_all_abs.c \
			upd_all_ord.c \
			init_horizontal_margin.c \
			init_vertical_margin.c \
			create_image.c \
			put_plane_in_image.c \
			create_map.c \
			draw.c \
			my_pixel_put.c \
			bresenham.c \
			open_window.c \
			handle_key_input.c \
			add_new_image.c \
			translations.c \
			rotations.c \
			zoom.c \
			init_pixel.c \
			free_tab.c \
			free_plane.c \
			coord_clear.c \
			img_clear.c \
			free_and_exit.c \
			exit_before_window.c \
			clean_all.c

OBJ_DIR = .obj
OBJETS = ${addprefix ${OBJ_DIR}/,${SOURCES:.c=.o}}

LIBFT_NAME = libft.a
LIBFT_PATH = ./Libft

MINILIBX_NAME = libmlx_Linux.a
MINILIBX_PATH = ./Minilibx

CC = cc
CFLAGS = -Wall -Wextra -Werror

HEADER = fdf.h


all: ${NAME}

${OBJ_DIR}/%.o: %.c ${HEADER}
	@mkdir -p ${OBJ_DIR}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJETS} ${LIBFT_PATH}/${LIBFT_NAME} ${MINILIBX_PATH}/${MINILIBX_NAME}
	${CC} ${CFLAGS} -o $@ ${OBJETS} -L${LIBFT_PATH} -lft -L${MINILIBX_PATH} -lmlx -lXext -lX11 -lm

${LIBFT_PATH}/${LIBFT_NAME}:
	make -C ${LIBFT_PATH}

${MINILIBX_PATH}/${MINILIBX_NAME}:
	make -C ${MINILIBX_PATH}

clean:
	rm -rf ${OBJ_DIR}
	make clean -C ${LIBFT_PATH}
	make clean -C ${MINILIBX_PATH}

fclean: clean
	rm -f ${NAME}
	rm -f ${LIBFT_PATH}/${LIBFT_NAME}

re: fclean all

.PHONY: all clean fclean re
