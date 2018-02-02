# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makafile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asvirido <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/04 14:27:54 by asvirido          #+#    #+#              #
#    Updated: 2017/01/12 17:54:44 by asvirido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_contrast

FLAGS = -c -Wall -Wextra -Werror

HEADER = head.h

LIBFT = ./src/general/libft/ft_bzero.c 											\
		./src/general/libft/ft_strcpy.c 										\
		./src/general/libft/ft_strdup.c 										\
		./src/general/libft/ft_strjoin.c 										\
		./src/general/libft/ft_strlen.c 										\

LIST = 	./src/general/list/ft_nlstadd.c 										\
		./src/general/list/ft_nlstnew.c 										\

GENERAL = ./src/general/get_next_line.c 										\

SRC = 	$(LIBFT)																\
		$(LIST) 																\
		$(GENERAL)																\

BINS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	gcc -o $(NAME) $(BINS)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -o $@ $<

clean:
	 /bin/rm -f $(BINS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

norm:
	norminette *.c *.h