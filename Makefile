SRC		=	$(SRC_DIR)/allocs/allocs.c \
			$(SRC_DIR)/argm/receive_args.c \
			$(SRC_DIR)/argm/nodes.c \
			$(SRC_DIR)/argm/handlers.c \
			$(SRC_DIR)/argm/args_aux.c \
			$(SRC_DIR)/argm/args_aux2.c \
			$(SRC_DIR)/argm/redirection.c \
			$(SRC_DIR)/argm/split_aux.c \
			$(SRC_DIR)/builtins/builtins.c \
			$(SRC_DIR)/builtins/builtins2.c \
			$(SRC_DIR)/builtins/utils1.c \
			$(SRC_DIR)/builtins/utils2.c \
			$(SRC_DIR)/cmd/cmd.c \
			$(SRC_DIR)/cmd/cmd_utils.c \
			$(SRC_DIR)/cmd/cmd_utils2.c \
			$(SRC_DIR)/env/env.c \
			$(SRC_DIR)/exec/exec_main.c \
			$(SRC_DIR)/exec/prep_exec.c \
			$(SRC_DIR)/exec/utils.c \
			$(SRC_DIR)/exec/utils2.c \
			$(SRC_DIR)/expander/expander.c \
			$(SRC_DIR)/expander/expander_utils.c \
			$(SRC_DIR)/expander/expander_utils2.c \
			$(SRC_DIR)/files_check/files_check.c \
			$(SRC_DIR)/files_check/utils.c \
			$(SRC_DIR)/redirections/red.c \
			$(SRC_DIR)/redirections/red_utils.c \
			$(SRC_DIR)/redirections/red_utils2.c \
			$(SRC_DIR)/redirections/heredoc.c \
			$(SRC_DIR)/redirections/heredoc_utlis.c \
			$(SRC_DIR)/redirections/check_red.c \
			$(SRC_DIR)/str/str.c \
			$(SRC_DIR)/str/utils1.c \
			$(SRC_DIR)/str/utils2.c \
			$(SRC_DIR)/main.c \


OBJ			=	$(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR		=	srcs

OBJ_DIR		=	objs

NAME		=	minishell

SHELL		=	/bin/bash

LIB			=	lib/printf_fd/libprintf_fd.a

INC			=	includes/

CC			=	cc

#-fsanitize=address

CFLAGS		=	-Wall -Wextra -Werror -g -I$(INC)# -fsanitize=address

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

$(NAME):	$(LIB) $(OBJ)
	@printf "%b" "$(OK_COLOR)"
	@echo  "✨✨ Upgraded Successfuly!! ✨✨"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lreadline -L lib/printf_fd -lprintf_fd
	@printf "%b" "$(NO_COLOR)"

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@printf "%b" "$(OBJ_COLOR)"
	@echo  "🔨🔨  Compiling Objects... 🔨🔨"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I includes -I /usr/local/include -I lib/printf_fd/include -c $< -o $@
	@printf "%b" "$(NO_COLOR)"

$(LIB):
	make -C lib/printf_fd

clean:	header
	@echo $(PURPLE) "🧹🧹 Cleaning... 🧹🧹" $(EOC)
	@$(RM) $(OBJ_DIR)
	@make clean -C lib/printf_fd
	@printf "%b" "$(NO_COLOR)"

fclean:	clean
	@$(RM) $(NAME)

git:
	@git add .
	@git commit -m "$m"
	@git push
	@echo "Commit sent to github"

valgrind:	re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --log-file=valgrind-out.txt ./minishell

re:	fclean all
