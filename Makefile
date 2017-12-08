# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/08 16:12:13 by mfonteni          #+#    #+#              #
#    Updated: 2017/12/08 18:06:51 by mfonteni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnltests
TESTDIR = tests/
GNLDIR = ../gnl/
SRC =	gnltests.c \
		$(TESTDIR)test_ft_realloc.c

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(SRC) $(GNLDIR)*.c libft.a

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
