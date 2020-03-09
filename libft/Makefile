# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 17:01:16 by sluhtala          #+#    #+#              #
#    Updated: 2020/03/09 14:30:01 by sluhtala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = create_list.c error_manager.c free_list.c ft_printf.c \
initialize_pf.c is_fspecif.c get_data.c ft_itoa_u.c ft_itoa_l.c \
ft_itoa_ul.c  number_manager.c ft_itoa_base.c \
ft_itoa_base_ll.c hex_manager.c save_float.c save_ldouble.c \
float_manager.c get_valid_flags.c apply_flags.c is_hex.c \
apply_preci.c

OFILES = create_list.o error_manager.o free_list.o ft_printf.o \
initialize_pf.o is_fspecif.o get_data.o ft_itoa_u.o ft_itoa_l.o \
ft_itoa_ul.o  number_manager.o ft_itoa_base.o \
ft_itoa_base_ll.o hex_manager.o save_float.o save_ldouble.o \
float_manager.o get_valid_flags.o apply_flags.o is_hex.o \
apply_preci.o

LIBFT = libft/libft.a

INCLUDES = .

all: $(NAME)

$(NAME):
	@make re -C libft
	@cp  $(LIBFT) libft.a
	@gcc -c $(SRCS) -I $(INCLUDES) -Wall -Wextra -Werror
	@ar -rc $(NAME) $(OFILES)
	@ranlib $(NAME)

.PHONY:clean

clean:
	@rm -f $(OFILES)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all
