SRC		=	$(SRC_DIR)/str/str.c \
			$(SRC_DIR)/str/utils1.c \
			$(SRC_DIR)/str/utils2.c \
			$(SRC_DIR)/main.c \

OBJ			=	$(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR		=	srcs

OBJ_DIR		=	objs

NAME		=	minishell

INC			=	includes/

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I$(INC) -g

RM			=	rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L/usr/local/lib -I/usr/local/include -lreadline

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -L/usr/local/lib -I/usr/local/include -lreadline -c $< -o $@
clean:
	$(RM) $(OBJ_DIR)/*.o $(OBJ_DIR)/*/*.o

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
