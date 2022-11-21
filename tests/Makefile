# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 03:11:53 by eryudi-m          #+#    #+#              #
#    Updated: 2022/11/21 00:27:54 by eryudi-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#it should get the bin on so_long, and test here

CC = clang -g3

TESTS_FILES = validate_extension.c \
		ck_retangle.c \
		ck_border.c \
		ck_elements.c \
		validate_map.c 

PATH_TEST = ./test/
TESTS = $(addprefix $(PATH_TEST), $(TESTS_FILES))

TESTER = ./unity/src/unity.c

MAIN = test_pipex.h test_pipex.c

FILE = ../pipex/bin/pipex

all:
	$(CC) $(TESTS) $(TESTER) $(MAIN) $(FILE) -o $(NAME)
	./pipex

