NAME = fractol

SRCS = srcs/main.c srcs/error_manager.c

OFILES = main.o srcs/error_manager.o


all: $(NAME)

$(NAME):
	@make -C libft
	@echo compiling ..
	@gcc $(SRCS) libft/libft.a -o $(NAME) -I includes -l mlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror
	@echo $(NAME) created

cata:
	@make -C libt
	@echo compiling ..
	@gcc $(SRCS) libft/libft.a -I /usr/X11/include -I includes -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo $(NAME) created

clean:
	rm -f $(OFILES)
	@make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -rf $(NAME).dSYM
	@make fclean -C libft

re: fclean all
