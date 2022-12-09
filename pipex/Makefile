# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 20:25:34 by eryudi-m          #+#    #+#              #
#    Updated: 2022/12/09 16:25:13 by eryudi-m         ###   ########.fr        #
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
SRC_FILES = pipex.c \
			errors.c \
			file_handler.c \
			free.c 
			#test_pipe.c \
			#pipex.c \
			#test_exec.c \
			#test_signal_communicate_process.c \
			#test_signals.c \
			
SOURCES = $(addprefix $(PATH_SRC), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(PATH_OBJ), $(OBJ_FILES))

#MISC
MKDIR = mkdir -p
RM = rm -f
MAKE_NOPRINT = $(MAKE) --no-print-directory

#TARGETS
all: libft $(NAME) main

libft:
	@cd $(PATH_LIBFT) && $(MAKE_NOPRINT)

$(NAME): $(OBJECTS)
	@cp $(PATH_LIBFT)libft.a $(PATH_LIBFT)$(NAME)
	@ar -rcs $(PATH_LIBFT)$(NAME) $(OBJECTS)


$(PATH_OBJ)%.o : $(PATH_SRC)%.c $(PATH_INC)*.h
	mkdir -p $(PATH_OBJ)
	$(CC) $(FLAGS) -c $< -o $@

main: $(APP_FILE)
	@$(MKDIR) $(PATH_BIN)
	@$(CC) $(FLAGS) $(OBJECTS) $< $(PATH_LIBFT)$(NAME) -I$(PATH_INC) -o $(PATH_BIN)$(NAME)

#Delete compiled files
clean:
	@cd $(PATH_LIBFT) && $(MAKE) clean
	@$(RM) $(OBJECTS)

fclean: clean
	@cd $(PATH_LIBFT) && $(MAKE) fclean
	@$(RM) $(PATH_BIN)$(NAME)

#Tests
test: all
	$(PATH_BIN)$(NAME) ./test/input1.txt "ls -l" "wc -c" ./test/output.txt
leak:
	$(VALGRIND) -s $(PATH_BIN)$(NAME) ./test/input1.txt "abc" "grep d" "output.txt"

#These tests shoud fail - error
one_arg: all
	$(VALGRIND) $(PATH_BIN)$(NAME) "./test/input.txt"

input_test: all
	$(VALGRIND) $(PATH_BIN)$(NAME) ./test/inut1.txt "ls -l" "wc -c" "output.txt"

input_test1: all
	touch ./test/no_read.txt
	echo "HELLOABVVD hello" >> ./test/no_read.txt
	chmod 333 ./test/no_read.txt
	$(VALGRIND) $(PATH_BIN)$(NAME) ./test/no_read.txt "ls -l" "wc -c" "output.txt"
##rm -f ./test/no_read.txt
#< no_read.txt ls -l | wc -c > "output.txt"

#These tests are a pass
valid:
	$(PATH_BIN)$(NAME) ./test/input1.txt "abc" "cdv" "abde"



re: fclean all

.PHONY: all clean fclean re libft
