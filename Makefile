NAME = fdf

SOURCES =	main.c \
			parse_grid.c \
			check_file_ext.c \
			init_grid.c \
			parse_line.c \
			init_plane.c \
			init_plane_width.c \
			init_plane_height.c \
			get_height.c \
			get_depth.c \
			init_horizontal_margin.c \
			init_vertical_margin.c \
			init_pixel.c \
			adapt_scale_to_three.c \
			upd_all_abs.c \
			upd_all_ord.c \
			handle_key_input.c \
			open_window.c \
			put_plane_in_window.c \
			show_plane.c \
			draw_vector.c \
			add_to_coord.c \
			create_map.c \
			draw.c \
			bresenham.c \
			exit.c \
			free_tab.c \
			coord_clear.c \
			free_plane.c

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
