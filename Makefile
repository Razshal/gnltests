# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/08 16:12:13 by mfonteni          #+#    #+#              #
#    Updated: 2017/12/17 19:12:49 by mfonteni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnltests
TESTDIR = tests/
GNL = ../gnl/get_next_line.c
SRC =	gnltests.c \
		$(TESTDIR)basic_test.c \
		$(TESTDIR)buffer_test.c \
		$(GNL)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

f: re
	@./$(NAME)

$(NAME): $(OBJ)
	@make -C ../gnl/libft/
	@cp ../gnl/libft/libft.a .
	@gcc -o $(NAME) $(FLAGS) $(SRC) libft.a
	@echo "done"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
