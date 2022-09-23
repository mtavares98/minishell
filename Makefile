SRC		=	$(SRC_DIR)/allocs/allocs.c \
			$(SRC_DIR)/cmd/cmd.c \
			$(SRC_DIR)/cmd/cmd_utils.c \
			$(SRC_DIR)/exec/exec_main.c \
			$(SRC_DIR)/exec/utils.c \
			$(SRC_DIR)/gnl/get_next_line.c \
			$(SRC_DIR)/gnl/get_next_line_utils.c \
			$(SRC_DIR)/str/str.c \
			$(SRC_DIR)/str/utils1.c \
			$(SRC_DIR)/str/utils2.c \
			$(SRC_DIR)/main.c \
			$(SRC_DIR)/files_check/files_check.c \
			$(SRC_DIR)/argm/receive_args.c \
			$(SRC_DIR)/argm/nodes.c  \
			$(SRC_DIR)/argm/handlers.c  \
			$(SRC_DIR)/argm/args_aux.c	\

OBJ			=	$(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR		=	srcs

OBJ_DIR		=	objs

NAME		=	minishell

SHELL		=	/bin/bash

INC			=	includes/

CC			=	gcc

#-fsanitize=address

CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address -I$(INC)

RM			=	rm -rf

all:	$(NAME)

$(NAME):	create_dirs $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L/usr/local/lib -I/usr/local/include -lreadline

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -L/usr/local/lib -I/usr/local/include -lreadline -c $< -o $@
clean:
	$(RM) $(OBJ_DIR)

fclean:	clean
	$(RM) $(NAME)

create_dirs:
	mkdir -p objs/{allocs,cmd,exec,gnl,str,files_check,argm}

re:	fclean all
