NAME = fdf

SOURCES =	main_v4.c \
			check_file_ext.c \
			init_image.c \
			create_image.c \
			draw.c \
			put_pixels_in_image.c \
			line_left_bresenham.c \
			line_up_bresenham.c \
			my_pixel_put.c \
			open_and_close_window.c \
			clean_and_exit.c \
			free_tab.c \

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
	${CC} ${CFLAGS} -o $@ ${OBJETS} -L${LIBFT_PATH} -lft -L${MINILIBX_PATH} -lmlx -lXext -lX11

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
