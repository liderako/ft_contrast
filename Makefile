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

LIBFT = ./src/general/libft/ft_atoi.c 											\
		./src/general/libft/ft_bzero.c 											\
		./src/general/libft/ft_isdigit.c 										\
		./src/general/libft/ft_strcmp.c 										\
		./src/general/libft/ft_strcpy.c 										\
		./src/general/libft/ft_strdup.c 										\
		./src/general/libft/ft_strjoin.c 										\
		./src/general/libft/ft_strlen.c 										\
		./src/general/libft/ft_strsub.c 										\
		./src/general/libft/ft_putchar_fd.c 									\
		./src/general/libft/ft_putnbr_fd.c 										\
		./src/general/libft/ft_putstr_fd.c 										\


LIST = 	./src/general/list/ft_nlstadd.c 										\
		./src/general/list/ft_nlstnew.c 										\

GENERAL = 	./src/general/get_next_line.c 										\
			./src/general/input_param.c 										\
			./src/general/ft_read.c 											\
			./src/general/init.c 												\
			./src/general/algo_contrast.c 										\
			./src/general/change_mapping.c 										\
			./src/general/save_file.c 											\


SRC = 	$(LIBFT)																\
		$(LIST) 																\
		$(GENERAL)																\
		main.c 																	\

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