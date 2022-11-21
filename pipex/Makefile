# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 20:25:34 by eryudi-m          #+#    #+#              #
#    Updated: 2022/11/11 07:16:28 by eryudi-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

#Compile
CC = clang -g
FLAGS = -Wall -Wextra -Werror
AR = ar -rcs

VALGRIND =	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
DEBUGGER = gdb

#PATHS
PATH_INC = ./inc/
PATH_SRC = ./src/
PATH_OBJ = ./obj/
PATH_BIN = ./bin/
PATH_LIBFT =./libft/

#FILES
APP_FILE = ./app/app.c
SRC_FILES = pipex.c

SOURCES = $(addprefix $(PATH_SRC), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(PATH_OBJ), $(OBJ_FILES))

#MISC
MKDIR = mkdir -p
RM = rm -f
MAKE_NOPRINT = $(MAKE) --no-print-directory

#TARGETS
all: libft $(NAME)

libft:
	@cd $(PATH_LIBFT) && $(MAKE_NOPRINT)

$(NAME): libft $(OBJECTS)
	@$(MKDIR) $(PATH_BIN)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) -L $(PATH_LIBFT) -lft

$(PATH_OBJ)%.o : $(PATH_SRC)%.c


