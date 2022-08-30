SRC		=	$(SRC_DIR)/main.c \
			$(SRC_DIR)/str.c \
			$(SRC_DIR)/utils1.c \

OBJ			=	$(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR	=	srcs

OBJ_DIR		=	objs

NAME		=	minishell

INC			=	includes/

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I$(INC) -g -fsanitize=address

RM			=	rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L/usr/local/lib -I/usr/local/include -lreadline

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -L/usr/local/lib -I/usr/local/include -lreadline -c $< -o $@
clean:
	$(RM) $(OBJ_DIR)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
