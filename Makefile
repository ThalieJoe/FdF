NAME = fdf

SOURCES =	main.c \
			check_map.c \
			check_file_ext.c \
			parse_map.c \
			init_plane.c \
			init_plane_size.c \
			vertical_rotation.c \
			horizontal_rotation.c \
			upd_view.c \
			handle_key_input.c \
			open_and_close_window.c \
			put_plane_in_window.c \
			show_plane.c \
			draw_vector_pos.c \
			draw_vector_neg.c \
			add_to_coord.c \
			create_map.c \
			draw.c \
			bresenham.c \
			clean_and_exit.c \
			free_tab.c \
			# infos_init.c \
			# init_image.c \
			# create_plane.c \
			# add_coords.c \
			# draw.c \
			# line_up_bresenham.c \
			# line_down_bresenham.c \
			# my_pixel_put.c \

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
