SRC		=	$(SRC_DIR)/allocs/allocs.c \
			$(SRC_DIR)/argm/receive_args.c \
			$(SRC_DIR)/argm/nodes.c  \
			$(SRC_DIR)/argm/handlers.c  \
			$(SRC_DIR)/argm/args_aux.c  \
			$(SRC_DIR)/builtins/builtins.c \
			$(SRC_DIR)/builtins/utils1.c \
			$(SRC_DIR)/cmd/cmd.c \
			$(SRC_DIR)/cmd/cmd_utils.c \
			$(SRC_DIR)/cmd/cmd_utils2.c \
			$(SRC_DIR)/env/env.c \
			$(SRC_DIR)/exec/exec_main.c \
			$(SRC_DIR)/exec/prep_exec.c \
			$(SRC_DIR)/exec/utils.c \
			$(SRC_DIR)/files_check/files_check.c \
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
			$(SRC_DIR)/argm/args_aux.c  \
			$(SRC_DIR)/argm/args_aux2.c	\


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

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m


COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m


all:	$(NAME)

header:
	@printf "%b" "$(COM_COLOR)"
	@echo "        ___  _____ ___  ___      _        "
	@echo "       /   |/ __  \|  \/  |     | |       "
	@echo "      / /| |\`' / /'| .  . | __ _| | _____ "
	@echo "     / /_| |  / /  | |\/| |/ _\` | |/ / _ \\"
	@echo "     \___  |./ /___| |  | | (_| |   <  __/"
	@echo "         |_/\_____/\_|  |_/\__,_|_|\_\___| v2"
	@echo

$(NAME):	create_dirs $(OBJ)
	@printf "%b" "$(OK_COLOR)"
	@echo  "✨✨ Upgraded Successfuly!! ✨✨"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L/usr/local/lib -I/usr/local/include -lreadline

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@printf "%b" "$(OBJ_COLOR)"
	@echo  "🔨🔨  Compiling Objects... 🔨🔨"
	@$(CC) $(CFLAGS) -L/usr/local/lib -I/usr/local/include -lreadline -c $< -o $@

clean:	header
	@echo $(PURPLE) "🧹🧹 Cleaning... 🧹🧹" $(EOC)
	@$(RM) $(OBJ_DIR)

fclean:	header header clean
	$(RM) $(NAME)

create_dirs:
	mkdir -p objs/{allocs,cmd,exec,gnl,str,files_check,argm}
git:
	@git add .
	@git commit -m "$m"
	@git push
	@echo "Commit sent to github"

re:	fclean all
