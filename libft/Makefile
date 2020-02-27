# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 15:20:56 by sluhtala          #+#    #+#              #
#    Updated: 2020/02/26 12:43:50 by sluhtala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ./
CFILES = ./ft_atoi.c ./ft_isdigit.c ./ft_memcmp.c ./ft_putchar.c ./ft_putstr.c \
./ft_strcpy.c ./ft_strjoin.c ./ft_strncmp.c ./ft_strsplit.c \
./ft_bzero.c ./ft_isprint.c ./ft_memcpy.c ./ft_putchar_fd.c ./ft_putstr_fd.c \
./ft_strdel.c ./ft_strlcat.c ./ft_strncpy.c ./ft_strstr.c \
./ft_intlen.c ./ft_itoa.c ./ft_memdel.c ./ft_putendl.c ./ft_strcat.c ./ft_strdup.c \
./ft_strlen.c ./ft_strnequ.c ./ft_strsub.c \
./ft_isalnum.c ./ft_memalloc.c ./ft_memmove.c ./ft_putendl_fd.c ./ft_strchr.c \
./ft_strequ.c ./ft_strmap.c ./ft_strnew.c ./ft_strtrim.c \
./ft_isalpha.c ./ft_memccpy.c ./ft_memset.c ./ft_putnbr.c ./ft_strclr.c \
./ft_striter.c ./ft_strmapi.c ./ft_strnstr.c ./ft_tolower.c \
./ft_isascii.c ./ft_memchr.c ./ft_power.c ./ft_putnbr_fd.c \
./ft_strcmp.c ./ft_striteri.c\
 ./ft_strncat.c ./ft_strrchr.c ./ft_toupper.c ./ft_lstnew.c ./ft_lstdelone.c \
 ./ft_lstdel.c ./ft_lstadd.c ./ft_lstiter.c ./ft_lstmap.c ./ft_lstappend.c \
 ./ft_printlst.c ./ft_strtoupper.c ./ft_strtolower.c ./ft_realloc.c ./ft_pow.c \
 ./get_next_line.c ./ft_split.c
PATHCFILES = $(patsubst ./%, $(SRCS)%, $(CFILES))
OFILES = $(patsubst %.c,%.o,$(CFILES))
INCLUDES = .

all: $(NAME)

$(NAME):
	@gcc -I $(INCLUDES) -Wall -Wextra -Werror -c $(PATHCFILES)
	@ar -rc $(NAME) $(OFILES)
	@ranlib $(NAME)

.PHONY:clean

clean:
	@rm -f $(OFILES)

fclean:clean
	@rm -f $(NAME)

re: fclean all
