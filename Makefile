NAME = fractol

SRCS = srcs/main.c srcs/error_manager.c srcs/create_background.c \
	srcs/color_init.c srcs/image_manager.c srcs/input_manager.c \
	srcs/draw_coord_grid.c srcs/renderer.c srcs/draw_fractal.c \
	srcs/hsv.c

OFILES = main.o srcs/error_manager.o


all: $(NAME)

$(NAME):
	@make -C libft
	@echo compiling ..
	@gcc $(SRCS) libft/libft.a -o $(NAME) -I includes -l mlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror
	@echo $(NAME) created

cata:
	@make -C libft
	@echo compiling ..
	@gcc $(SRCS) libft/libft.a -lpthread -I /usr/X11/include -I includes -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo $(NAME) created

clean:
	rm -f $(OFILES)
	@make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -rf $(NAME).dSYM
	@make fclean -C libft

re: fclean all
