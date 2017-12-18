# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/08 16:12:13 by mfonteni          #+#    #+#              #
#    Updated: 2017/12/18 14:10:31 by mfonteni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnltests
TESTDIR = tests/
GNL = ../gnl/get_next_line.c
SRC =	gnltests.c \
		$(TESTDIR)basic_test.c \
		$(TESTDIR)buffer_test.c \
		$(TESTDIR)fd0_test.c \
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
	@rm -f $(OBJ) libft.a

fclean: clean
	@rm -f $(NAME)

re: fclean all
